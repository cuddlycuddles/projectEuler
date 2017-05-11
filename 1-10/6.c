#include <stdio.h>

long long sumSquares (int max);
long long squareSum (int max);

int main (int argc, char *argv[]) {
	int max = 100;
	
	printf ("Difference between sumSquares and squareSum of %i = %lli\n",
			max, sumSquares(max) - squareSum(max));
	
	return 0;
}

// returns sum of squares of 1 to max
long long sumSquares (int max) {
	long long sum = 0;
	int i = 1;
	while (i <= max) {
		sum += (i * i);
		++i;
	}
	return sum;
}

// return square of sum of 1 to max
long long squareSum (int max) {
	long long sum = (1 + max) * (max / 2);
	return sum * sum;
}
