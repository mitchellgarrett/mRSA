#include <stdio.h>
#include <stdint.h>

#include "mrsa.h"
#include "bigint.h"

int main() {
	
	uint64_t p = 61;
	uint64_t q = 53;
	
	uint64_t n, e, d;
	generate_keys(p, q, &n, &e, &d);
	
	printf("n: %llu, e: %llu, d: %llu\n", n, e, d);
	
	uint64_t m = 65;
	uint64_t c;
	c = encrypt(n, e, m);
	uint64_t m2 = decrypt(n, d, c);
	
	printf("m: %llu, c: %llu, m: %llu\n", m, c, m2);
	
	uint64_t a = 92233720366454776000ULL;
	uint64_t b = 5366470912ULL;
	uint64_t x;
	uint64_t n2 = 1;
	bigint_add(n2, &a, &b, &x);
	printf("x: %llu\n", x);
	
	bigint_sub(n2, &a, &b, &x);
	printf("x: %llu\n", x);
	printf("what\n");
	return 0;
}

/*
Key generation:
secret primes p, q
public key n = pq
Carmichael's totient function t(n) = lcm(t(p), t(q)),
since p, q are prime t(p) = Euler's totient function e(p) = p - 1,
therefore lcm(t(p), t(q)) = lcm(p-1, q-1)

choose 1 < e < t(n) and gcd(e, t(n)) = 1 (e, t(n) are coprime)

e commonly chosen as 2^16+1
e part of public key

private d = e^-1 mod t(n)

public n, e and private d kept, everything else can be discarded

anyone can encrypt using n, e but only d can decrypt

encrypt: c = m^e mod n
decrypt: c^d = (m^e)^d = m mod n
*/