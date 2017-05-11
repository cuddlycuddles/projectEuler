#include <stdio.h>

long long palindrome (long long x);

int main (int argc, char *argv[]) {
	int x = 101;
	int y;
	long long largest = 0;
	while (x < 1000) {
		y = 101;
		while (y < 1000) {
			if (palindrome (x * y) > largest)  {
				largest = x * y;
			}
			++y;
		}
		++x;
	}
	printf ("Largest palindrome = %lli\n", largest);
	
	return 0;
}

// returns original number if it is palindrome, else returns 0
long long palindrome (long long x) {
	long long og = x;
	long long r = 0;
	int digit;
	while (x > 0) {
		digit = x % 10;
		r = r * 10 + digit;
		x /= 10;
	}
	
	return og == r ? og : 0;
}

