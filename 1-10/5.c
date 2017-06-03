#include <stdio.h>
#include <assert.h>

void testFunctions (void);
long gcd (long x, int y);
long lcm (long x, int y);

int main (int argc, char *argv[]) {
	testFunctions();
	int i = 2;
	long result = 1;
	while (i <= 20) {
		result = lcm (result, i++);
	}
	printf ("Smallest common multiple = %li\n", result);
	return 0;
}

// test lcm and gcd
void testFunctions (void) {
	assert (lcm (1, 2) == 2);
	assert (lcm (999999, 142857) == 999999);
	assert (lcm (1513, 1531) == 2316403);
	assert (gcd (120, 24) == 24);
	assert (gcd (250, 25) == 25);
	assert (gcd (9801, 9603) == 99);
	printf ("Functions work.\n");
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
	return (x * y) / gcd(x, y);
}
