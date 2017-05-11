#include <stdio.h>

int main (int argc, char *argv[]) {
	int sum = 0;
	int i = 1;
	while (i < 1000) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
		++i;
	}
	printf ("Result = %i\n", sum);
}
