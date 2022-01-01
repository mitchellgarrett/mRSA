#ifndef M_BIGINT_H
#define M_BIGINT_H

#include <stdint.h>

typedef struct bigint {
	uint64_t length : 63;
	uint64_t sign : 1;
	uint64_t* data;
} bigint;

bigint* bigint_create(uint64_t len, const uint64_t data, uint64_t sign);

void bigint_add(uint64_t n, const uint64_t* a, const uint64_t* b, uint64_t* x);
void bigint_sub(uint64_t n, const uint64_t* a, const uint64_t* b, uint64_t* x);

#endif