/* SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only */
/* Copyright (c) 2022 Brett Sheffield <bacs@librecast.net> */

#ifndef LCRQ_H
#define LCRQ_H 1

#include <stddef.h>
#include <stdint.h>

/* rounding integer division */
#define CEIL(x, y)  (((x) + ((y) - 1)) / (y))
#define FLOOR(x, y) ((x) / (y))

typedef struct part_s {
	size_t IL;
	size_t IS;
	size_t JL;
	size_t JS;
} part_t;

typedef struct rq_s rq_t;

part_t rq_partition(size_t I, uint16_t J);
size_t rq_rand(size_t y, uint8_t i, size_t m);

rq_t *rq_init(size_t F, uint16_t T);
void rq_free(rq_t *rq);

#endif /* LCRQ_PVT_H */
