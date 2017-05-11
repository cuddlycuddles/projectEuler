#include <stdio.h>

long gcd (long x, int y);
long lcm (long x, int y);

int main (int argc, char *argv[]) {
	int i = 2;
	long result = 1;
	
	while (i <= 20) {
		result = lcm (result, i);
		
		++i;
	}
	
	printf ("Smallest common multiple = %li\n", result);
	
	return 0;
}

// calculates greatest common divisor of two numbers
long gcd (long x, int y) {
	int temp;
	while (y != 0) {
		temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}

// calculates lowest common multiple of two numbers
// by dividing their product
// by their greatest common divisor
long lcm (long x, int y) {
	return x / gcd(x, y) * y;
}
