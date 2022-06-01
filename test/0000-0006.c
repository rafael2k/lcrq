/* SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only */
/* Copyright (c) 2022 Brett Sheffield <bacs@librecast.net> */

#include "test.h"
#include <assert.h>
#include <lcrq.h>
#include <lcrq_pvt.h>
#include <sodium.h>
#include <sys/param.h>

static const size_t MAX_PAYLOAD = 4; /* MAX_PAYLOAD must be at least Al=4 bytes */
//static const size_t MAX_SRCOBJ = MAX_PAYLOAD * 10 + 0;// OK
static const size_t MAX_SRCOBJ = MAX_PAYLOAD * 1 + 0;// FIXME breaks if > 10 * T

//#define MAX_SRCOBJ 1024 * 1024 * 1024
//#define MAX_SRCOBJ 1538 * 420
//static_assert(MAX_SRCOBJ > 1);

/* generate source object of data of random size and content up to max bytes */
unsigned char *generate_source_object(size_t max, size_t *F)
{
	unsigned char *block;
	size_t sz = 0;
	//size_t sz = randombytes_uniform(max);
	if (!sz) sz = max;
	block = malloc(sz);
	assert(block);
	//randombytes_buf(block, sz);
	for (unsigned char i = 0; i < 4; i++) block[i] = i + 42;
	//memset(block, 0, sz);
	*F = sz;
	return block;
}

int main(void)
{
	rq_t *rq;
	matrix_t A = {0};
	matrix_t D = {0};
	matrix_t A_dup = {0};
	matrix_t C;
	unsigned char *srcobj = NULL;
	unsigned char *padblk = NULL;
	unsigned char *srcblk;
	size_t F, len; /* F requires 40 bits */
	uint8_t SBN;
	//uint32_t ESI; 24 bit unsigned
	size_t blklen;

	loginit();
	test_name("5.3.3.4 Intermediate Symbol Generation");

	/* generate random source block for test */
	srcobj = generate_source_object(MAX_SRCOBJ, &F);
	test_log("block of %u bytes generated\n", F);

	rq = rq_init(F, MAX_PAYLOAD);
	rq_dump(rq, stderr);

	srcblk = srcobj;
	len = F;

	test_log("ZL = %zu\n", rq->src_part.JL);
	test_log("ZS = %zu\n", rq->src_part.JS);

	/* NB: the mth symbol of a source block consists of the
	   concatenation of the mth sub-symbol from each of the N sub-blocks.
	   Note that this implies that when N > 1, a symbol is NOT a contiguous
	   portion of the object */

	/* Note that the value of K is not necessarily the same for each source
	   block of an object, and the value of T' may not necessarily be the
	   same for each sub-block of a source block.  However, the symbol size
	   T is the same for all source blocks of an object, and the number of
	   symbols K is the same for every sub-block of a source block. */

	/* encode blocks */
	for (SBN = 0; SBN < rq->Z; SBN++) {
		if (SBN < rq->src_part.JL) {
			/* long block */
			rq->K = rq->src_part.IL;
			blklen = rq->src_part.IL * rq->T;
			test_log("SBN %u: long block %zu bytes\n", SBN, blklen);
		}
		else {
			/* short block */
			rq->K = rq->src_part.IS;
			blklen = rq->src_part.IS * rq->T;
			test_log("SBN %u: short block %zu bytes\n", SBN, blklen);
		}
		if (SBN + 1 == rq->Z && rq->Kt * rq->T > rq->F) {
			/* last block needs padding */
			size_t padbyt = rq->Kt * rq->T - rq->F;
			test_log("last block and it needs padding of %zu bytes\n",
					padbyt);
			padblk = malloc(blklen);
			memcpy(padblk, srcblk, blklen - padbyt);
			memset(padblk + blklen - padbyt, 0, padbyt);
			srcblk = padblk;
		}

		rq_block(rq);
		rq_dump(rq, stderr);

		test_log("SBN %zu: K' (%u) * T (%u) = %zu\n", SBN, rq->KP, rq->T, rq->KP * rq->T);

		test_log("generating matrix A\n");
		rq_generate_matrix_A(rq, &A);

		//rq_dump_ldpc(rq, &A, stderr);
		//rq_dump_hdpc(rq, &A, stderr);

		test_log("matrix A done (%i x %i) %zu bytes\n", A.rows, A.cols, A.size);
		A_dup = matrix_dup(&A);
		test_assert(A.rows == A.cols, "Matrix A is square");
		test_assert(A.rows == rq->L, "Matrix A has dimension L");

		test_log("generating matrix D\n");
		D = rq_matrix_D(rq, srcblk);
		test_assert(D.rows = rq->L, "D has L rows");
		test_assert(D.cols = rq->T, "D has T cols");

		matrix_dump(&D, stderr);

		test_log("generating intermediate symbols\n");
		C = rq_intermediate_symbols(&A, &D);

		matrix_dump(&C, stderr);

		/* verify A*C=D */
		test_log("verifying A*C=D ... \n");
		matrix_t D2 = {0};
		matrix_multiply_gf256(&A_dup, &C, &D2);
		test_assert(memcmp(D.base, D2.base, D.size) == 0, "verify A*C=D");

		/* encoding (5.3.4) */
		/* as per 5.3.2, the original source symbols C' can be generated
		 * using the encoding process where 0 < ISI < K'
		 * we will use this to test the encoder before generating repair
		 * symbols */
		uint8_t *sym;
		uint8_t *src = srcblk;
		for (size_t isi = 0; isi < rq->K; isi++) {
			test_log("encoding ISI %zu\n", isi);
			sym = rq_encode(rq, &C, isi);
			test_assert(!memcmp(sym, src, rq->T), "verify ISI %zu", isi);

			rq_dump_symbol(rq, src, stderr);
			rq_dump_symbol(rq, sym, stderr);

			free(sym);
			src += rq->T;
		}
		/* TODO: repair symbols */
		//for (size_t isi = rq->KP; isi < rq->KP + 5; isi++) {
		//}

		matrix_free(&D2);
		matrix_free(&D);
		matrix_free(&C);

		matrix_free(&A_dup);
		matrix_free(&A);

		size_t off = MIN(blklen, len);
		srcblk += off;
		len -= off;
		fprintf(stderr, "len remaining = %zu\n", len);
	}

	rq_free(rq);
	free(padblk);
	free(srcobj);

	test_log("test done\n");

	return fails;
}
