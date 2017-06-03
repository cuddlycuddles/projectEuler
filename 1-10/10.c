#include <stdio.h>
#include <assert.h>
#include <math.h>

#define LIMIT 2000000

void testFunctions (void);
int isPrime (int x);

int main (int argc, char *argv[]) {
	testFunctions();
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

void testFunctions (void) {
	assert (isPrime (142857) == 0);
	assert (isPrime (20)	 == 0);
	assert (isPrime (25)	 == 0);
	assert (isPrime (9801)	 == 0);
	assert (isPrime (1009)	 == 1);
	assert (isPrime (1567)	 == 1);
	assert (isPrime (7919)	 == 1);
	assert (isPrime (104729) == 1);
	printf ("Functions work.\n");
}

int isPrime (int x) {
	int i = 2;
	int root = (int) sqrt (x);
	if (x % i == 0) { // check if even
		return 0;
	}
	++i;
	while (i <= root) { // only need to check until square root of input
		if (x % i == 0) {
			return 0;
		}
		i += 2;
	}
	return 1;
}
