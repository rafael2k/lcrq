/* SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only */
/* Copyright (c) 2022-2024 Brett Sheffield <bacs@librecast.net> */

#include <matrix.h>
#include <gf256.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <unistd.h>

#define VSZ 256

void matrix_row_add_sse2(matrix_t *dst, const int drow, const matrix_t *src, const int srow)
{
	assert(matrix_cols(dst) == matrix_cols(src));
	uint8_t *d = matrix_ptr_row(dst, drow);
	uint8_t *s = matrix_ptr_row(src, srow);
	const int mcols = matrix_cols(dst);
	const int mod_sse3 = mcols % 16;
	const int maxv_sse3 = mcols - mod_sse3;
	int j;
	for (j = 0; j < maxv_sse3; j += 16) {
		__m128i S = _mm_loadu_si128((const __m128i_u *)&s[j]);
		__m128i D = _mm_loadu_si128((const __m128i_u *)&d[j]);
		D = _mm_xor_si128(D, S);
		_mm_storeu_si128((__m128i*)&d[j], D);
	}
	for (; j < mcols; j++) d[j] ^= s[j];
}
