#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "bigint.h"

bigint* bigint_create(uint64_t len, const uint64_t* data, uint64_t sign) {
	while (len > 0 && data[len - 1] == 0) --len;
	
	bigint* val = (bigint*) malloc(sizeof(bigint));
	val->length = len;
	val->sign = sign;
	val->data = data;
	
	return val;
}

// Add n bits of a, b into n+1 bits of x
void bigint_add(uint64_t n, const uint64_t* a, const uint64_t* b, uint64_t* x) {
	/*bool carry, carry_a, carry_b;
	uint64_t sum_a, sum_b;
	
	carry = false;
	for (uint64_t i = 0; i < n; ++i) {
		sum_a = a[i] + carry;
		carry_a = sum_a < a[i];
		
		sum_b = sum_a + b[i];
		carry_b = sum_b < sum_a;
		
		x[i] = sum_b;
		assert(carry_a + carry_b <= 1);
		carry = carry_a + carry_b;
	}
	
	x[n] = carry;*/
	uint64_t carry = 0;
	for (uint64_t sum, i = 0; i < n; ++i) {
		sum = a[i] + b[i] + carry;
		x[i] = sum;
		carry = sum;
	}
	x[n] = carry;
}

// Return -1 if a < b, 1 if a > b, and 0 if a = b
static int bigint_cmp(uint64_t a_len, const uint64_t* a, uint64_t b_len, const uint64_t* b) {
	if (a_len != b_len) return a_len < b_len ? -1 : 1;
	
	for (uint64_t i = a_len - 1; i >= 0; --i) {
		if (a[i] != b[i]) return a[i] < b[i] ? -1 : 1;
	}
	
	return 0;
}

// Subtract n bits from a, b into x
void bigint_sub(uint64_t n, const uint64_t* a, const uint64_t* b, uint64_t* x) {
	if (bigint_cmp(n, a, n, b) < 0) return bigint_sub(n, b, a, x);
	printf("alive\n");
	/*bool borrow, borrow_a, borrow_b;
	uint64_t diff_a, diff_b;
	
	borrow = false;
	for (uint64_t i = 0; i < n; ++i) {
		diff_a = a[i] - borrow;
		borrow_a = diff_a > a[i];
		
		diff_b = diff_a - b[i];
		borrow_b = diff_a > diff_a;
		
		x[i] = diff_b;
		assert(borrow_a + borrow_b <= 1);
		borrow = borrow_a + borrow_b;
	}*/
	
	uint64_t borrow = 0;
	for (uint64_t diff, i = 0; i < n; ++i) {
		diff = a[i] - b[i] + borrow;
		x[i] = diff;
		borrow = diff;
	}
}