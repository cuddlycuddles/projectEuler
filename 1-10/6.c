
#include <stdio.h>

long long sumSquares (int n);
long long squareSum (int n);

int main (int argc, char *argv[]) {
	int n = 100;
	
	printf ("Difference between sumSquares and squareSum of %i = %lli\n",
			n, sumSquares(n) - squareSum(n));
	
	return 0;
}

// returns sum of squares of 1 to n
long long sumSquares (int n) {
	return n * (n + 1) * (2 * n + 1) / 6;
}

// return square of sum of 1 to n
long long squareSum (int n) {
	return (n * n) * (n + 1) * (n + 1) / 4;
}
