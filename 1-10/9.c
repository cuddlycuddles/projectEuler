#include <stdio.h>
#include <math.h>
#define square(x) (x * x)

int main (int argc, char *argv[]) {
	int a = 1;
	int b;
	double c; // using double for sqrt function
	while (a < 500) {
		b = 1;
		while (b < 500) {
			c = sqrt (square (a) + square (b));
			if (a + b + c == 1000) {
				printf ("%lf\n", a * b * c);
			}
			++b;
		}
		++a;
	}
	return 0;
}
