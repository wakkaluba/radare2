/* radare - LGPL - Copyright 2009-2021 - pancake, nibble */

#include <stdio.h>
#include <r_types.h>
#include <r_util.h>
#include <r_asm.h>

#include "d/6502.c"

static const SdbGperf *gperfs[] = {
	(const SdbGperf*)&gperf_6502,
	NULL
};

R_API SdbGperf *r_asm_get_gperf(const char *k) {
	SdbGperf **gp = (SdbGperf**)gperfs;
	while (*gp) {
		SdbGperf *g = *gp;
		if (!strcmp (k, g->name)) {
			return *gp;
		}
		gp++;
	}
	return NULL;
}
