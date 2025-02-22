/* SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only */
/* Copyright (c) 2012-2022 Brett Sheffield <bacs@librecast.net> */

#include <assert.h>
#include <semaphore.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "log.h"

#define LOG_BUFSIZE 256

unsigned int loglevel = LOG_LOGLEVEL_DEFAULT;
static int uselock;
static sem_t loglock;

void loginit(void)
{
	uselock = 1;
	sem_init(&loglock, 0, 1);
}

void logwait(void)
{
	if (uselock) sem_wait(&loglock);
}

void logdone(void)
{
	if (uselock) sem_post(&loglock);
}

void logmsg(unsigned int level, const char *fmt, ...)
{
	int len;
	char *mbuf = NULL;
	char buf[LOG_BUFSIZE];
	char *b = buf;
	va_list argp;
	if ((level & loglevel) != level) return;
	va_start(argp, fmt);
	len = vsnprintf(buf, LOG_BUFSIZE, fmt, argp);
	if (len >= LOG_BUFSIZE) {
		/* need a bigger buffer, resort to malloc */
		mbuf = malloc(len + 1);
		va_end(argp);
		va_start(argp, fmt);
		vsprintf(mbuf, fmt, argp);
		b = mbuf;
	}
	va_end(argp);
	if (uselock) logwait();
	if (level == LOG_INFO)
		fprintf(stdout, "%s\n", b);
	else {
		if (level >= LOG_TRACE) {
			fprintf(stderr, "%lu: ", (long unsigned int)clock());
		}
		fprintf(stderr, "%s\n", b);
	}
	if (uselock) logdone();
	free(mbuf);
}
