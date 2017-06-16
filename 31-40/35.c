#include <stdio.h>
#include <assert.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define LIMIT 1000000

int isCircularPrime (int n);
int isPrime (int n);
void testFunctions (void);

int main (int argc, char *argv[]) {
	testFunctions();
	int circularPrimes = 1; // skip 2 for optimisation
	int curr = 3;
	while (curr < LIMIT) {
		if (isCircularPrime (curr)) {
			++circularPrimes;
		}
		curr += 2;
	}
	printf ("Number of circular primes below %i = %i\n", LIMIT, circularPrimes);
}

int isCircularPrime (int n) {
	int nDigits = 0; // number of different rotations of n
	int nCpy = n; // used to calculate number of digits
	int i;
	// count number of digits
	while (nCpy) {
		nCpy /= 10;
		++nDigits;
	}
	i = 0;
	// check all rotations
	while (i < nDigits) {
		// check if not prime
		if (isPrime (n) == 0) {
			return FALSE;
		}
		// rotate the number
		n = (n % 10) * pow (10, nDigits - 1) + n / 10;
		++i;
	}
	return TRUE; // all rotations are primes
}

int isPrime (int n) {
	int i = 3;
	int root = (int) floor (sqrt (n));
	// check if even
	if (n % 2 == 0) {
		return FALSE;
	}
	// check possible odd factors
	while (i <= root) {
		if (n % i == 0) {
			return FALSE;
		}
		i += 2;
	}
	return TRUE;
}

void testFunctions (void) {
	printf ("Testing isPrime\n");
	assert (isPrime (142857) == 0);
	assert (isPrime (20)	 == 0);
	assert (isPrime (25)	 == 0);
	assert (isPrime (9801)	 == 0);
	assert (isPrime (1009)	 == 1);
	assert (isPrime (1567)	 == 1);
	assert (isPrime (7919)	 == 1);
	assert (isPrime (104729) == 1);
	printf ("Testing isCircularPrime\n");
	assert (isCircularPrime (3) 	== 1);
	assert (isCircularPrime (17) 	== 1);
	assert (isCircularPrime (31) 	== 1);
	assert (isCircularPrime (97) 	== 1);
	assert (isCircularPrime (197) 	== 1);
	assert (isCircularPrime (23) 	== 0);
	assert (isCircularPrime (15) 	== 0);
	assert (isCircularPrime (19) 	== 0);
	assert (isCircularPrime (41) 	== 0);
	assert (isCircularPrime (47) 	== 0);
	printf ("Functions work.\n");
}