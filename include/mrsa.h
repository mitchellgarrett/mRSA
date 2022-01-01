#ifndef M_RSA_H
#define M_RSA_H

#include <stdint.h>

// Calculate n^e mod m
uint64_t mod_exponent(uint64_t n, uint64_t e, uint64_t m);

// Solve for nx = 1 mod m using the extended Euclidean algorithm
uint64_t modular_inverse(uint64_t n, uint64_t m);

// Calculate the greatest common divisor of a, b using the Euclidean algorithm
uint64_t gcd(uint64_t a, uint64_t b);

// Calculate the least common multiple of a, b by |ab| / gcd(a, b)
uint64_t lcm(uint64_t a, uint64_t b);

// Find 1 < x < n such that x is coprime to n
uint64_t coprime(uint64_t n);

// Generate public RSA key (n, e) using given p, q
void generate_public_key(uint64_t p, uint64_t q, uint64_t* n, uint64_t* e);

// Generate private RSA key (n, d) using given p, q
void generate_private_key(uint64_t p, uint64_t q, uint64_t e, uint64_t* d);

// Generate public, private RSA keys (n, e), (n, d) using given p, q
void generate_keys(uint64_t p, uint64_t q, uint64_t* n, uint64_t* e, uint64_t* d);

// Encrypt message by c = m^e mod n
uint64_t encrypt(uint64_t n, uint64_t e, uint64_t m);

// Decrypt ciphertext by m = c^d mod n
uint64_t decrypt(uint64_t n, uint64_t d, uint64_t c);

#endif