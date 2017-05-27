#include <stdio.h>
#include <math.h>

int numFactors (int n);

int main (int argc, char *argv[]) {
	int i = 8;
	int triNum = 28;
	while (numFactors (triNum) < 500) { // get the number that has over 500 divisors
		triNum += i++;
	}
	printf ("%i\n", triNum);
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
