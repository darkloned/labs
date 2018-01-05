#include <stdio.h>

unsigned int lsh(unsigned int n, unsigned int k)
{
	k %= 32;
	unsigned int bit = n >> (32 - k);
	n <<= k;
	n |= bit;

	return n;
}

unsigned int rsh(unsigned int n, unsigned int k)
{
	k %= 32;
	unsigned int bit = n << (32 - k);
	n >>= k;
	n |= bit;

	return n;
}

int main()
{
	return 0;
}
