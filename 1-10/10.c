#include <stdio.h>
#include <math.h>

#define LIMIT 2000000

int isPrime (int x);

int main (int argc, char *argv[]) {
	unsigned long long sum = 2;
	int curr = 3;
	while (curr < LIMIT) {
		if (isPrime (curr)) {
			sum += curr;
		}
		curr += 2;
	}
	printf ("Sum of all primes under %i = %lli\n", LIMIT, sum);
	return 0;
}

int isPrime (int x) {
	int i = 2;
	int root = (int) sqrt (x);
	if (x % i == 0) { // check if even
		return 0;
	}
	++i;
	while (i <= root) {
		if (x % i == 0) {
			return 0;
		}
		i += 2;
	}
	return 1;
}
