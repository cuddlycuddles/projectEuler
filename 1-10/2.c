#include <stdio.h>

int main (int argc, char *argv[]) {
	int x = 1, y = 1, sum = 0;
	while (y < 4000000) {
		y += x;
		x = y - x;
		if (y % 2 == 0) {
			sum += y;
		}
	}
	printf ("Sum = %i\n", sum);
	return 0;
}
