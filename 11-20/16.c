#include <stdio.h>
#include <math.h>

int sumDigits (char *str);
int asciiToInt (char c);

int main (int argc, char *argv[]) {
	char str[] = "10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376";
	// through the use of pow (2, 1000)
	printf ("Sum of 2^1000's digits = %i\n", sumDigits (str));
	return 0;
}

int sumDigits (char *str) {
	int i = 0, sum = 0;
	while (str[i] != '\0') {
		sum += asciiToInt (str[i]);
		++i;
	}
	return sum;
}

int asciiToInt (char c) {
	return c - '0';
}
