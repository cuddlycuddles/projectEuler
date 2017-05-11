#include <stdio.h>

void largestPrimeFactor (long long x);

int main (int argc, char *argv[]) {
	long long x = 600851475143;
	
	largestPrimeFactor (x);
	
	return 0;
}

void largestPrimeFactor (long long x) {
	long long i = 2;
	while (i < x) {
		if (x % i == 0) {
			x /= i;
		} else {
			i++;
		}
	}
	printf ("Largest prime factor: %lli\n", i);
}
