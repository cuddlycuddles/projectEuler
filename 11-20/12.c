#include <stdio.h>
#include <assert.h>
#include <math.h>

void testFunctions (void);
int numFactors (int n);

int main (int argc, char *argv[]) {
	testFunctions();
	int i = 8;
	int triNum = 28;
	while (numFactors (triNum) < 500) { // get the number that has over 500 divisors
		triNum += i++;
	}
	printf ("%i\n", triNum);
}

void testFunctions (void) {
	assert (numFactors (142752) == 24);
	assert (numFactors (183843) == 16);
	assert (numFactors (20) == 6);
	assert (numFactors (320) == 14);
	assert (numFactors (1846206) == 32);
	assert (numFactors (142857) == 32);
	assert (numFactors (149459) == 2);
	printf ("Functions work.\n");
}

// returns the number of factors a number has (doesn't work on smaller numbers e.g. 1 to 4)
int numFactors (int n) {
	int x = 3;
	int factors = 2; // by default, numbers (except 1) have two factors, 1 and themselves
	int root = (int) sqrt (n);
	if (n % 2 == 0) {
		factors += 2;
	}
	while (x < root) {
		if (n % x == 0) {
			factors += 2; // a number's factors can be sorted into pairs so we only check up to the square root
		}
		++x;
	}
	if (n % root == 0) { // check if n is a perfect square
		++factors;
	}
	return factors;
}
