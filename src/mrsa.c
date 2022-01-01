#include "mrsa.h"
#include "bigint.h"

// Calculate n^e mod m
uint64_t mod_exponent(uint64_t n, uint64_t e, uint64_t m) {
	uint64_t x = n % m;
	for (uint64_t i = 1; i < e; i++) {
		x = (x * n) % m;
	}
	return x;
}

// Solve for nx = 1 mod m using the extended Euclidean algorithm
uint64_t modular_inverse(uint64_t n, uint64_t m) {
	for (uint64_t x = 1; x < m; ++x) {
		if ((x * n) % m == 1) return x;
	}
	return 0;
}

// Calculate the greatest common divisor of a, b using the Euclidean algorithm
uint64_t gcd(uint64_t a, uint64_t b) {
	if (a < b) return gcd(b, a);
	uint64_t d = a / b;
	uint64_t r = a % b;
	if (r == 0) return b;
	return gcd(b, r);
}

// Calculate the least common multiple of a, b by |ab| / gcd(a, b)
uint64_t lcm(uint64_t a, uint64_t b) {
	uint64_t n = a * b;
	if (n < 0) n *= -1;
	return n / gcd(a, b);
}

// Find 1 < x < n such that x is coprime to n
uint64_t coprime(uint64_t n) {
	for (uint64_t x = 3; x < n; ++x) {
		if (n % x != 0) return x;
	}
	return 1;
}

void generate_public_key(uint64_t p, uint64_t q, uint64_t* n, uint64_t* e) {
	*n = p * q;
	uint64_t l = lcm(p - 1, q - 1);
	*e = coprime(l);
}

void generate_private_key(uint64_t p, uint64_t q, uint64_t e, uint64_t* d) {
	uint64_t l = lcm(p - 1, q - 1);
	*d = modular_inverse(e, l);
}

void generate_keys(uint64_t p, uint64_t q, uint64_t* n, uint64_t* e, uint64_t* d) {
	*n = p * q;
	uint64_t l = lcm(p - 1, q - 1);
	*e = coprime(l);
	*d = modular_inverse(*e, l);
}

uint64_t encrypt(uint64_t n, uint64_t e, uint64_t m) {
	return mod_exponent(m, e, n);
}

uint64_t decrypt(uint64_t n, uint64_t d, uint64_t c) {
	return mod_exponent(c, d, n);
}