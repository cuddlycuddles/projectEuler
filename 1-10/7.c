#include <stdio.h>
#include <math.h>

#define NTH_PRIME 10001

int isPrime (int x);

int main (int argc, char *argv[]) {
	int i = 3;
	int primeCount = 1;
	while (primeCount < NTH_PRIME) {
		if (isPrime (i)) {
			++primeCount;
		}
		i += 2;
	}
	
	i -= 2; // subtract the last two added to get the 10001st prime
	
	printf ("The 10001st prime = %i\n", i);
	
	return 0;
}

// returns whether or not the input is a prime number
int isPrime (int x) {
	int j = 3;
	double squareRoot = floor (sqrt (x));
	while (j <= squareRoot) {
		if (x % j == 0) {
			return 0;
		}
		j += 2;
	}
	return 1;
}
