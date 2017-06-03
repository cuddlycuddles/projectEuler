#include <stdio.h>
#include <assert.h>
#include <math.h>

void testFunctions (void);
int sumDigits (char *str);
int asciiToInt (char c);

int main (int argc, char *argv[]) {
	testFunctions();
	char str[] = "10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376";
	// ascquired through the use of pow (2, 1000)
	printf ("Sum of 2^1000's digits = %i\n", sumDigits (str));
	return 0;
}

void testFunctions (void) {
	assert (sumDigits ("1234") == 10);
	assert (sumDigits ("1111") == 4);
	assert (sumDigits ("900000") == 9);
	assert (sumDigits ("111111111111111111111111111111111111") == 36);
	printf ("Functions work.\n");
}

// returns the sum of the input's digits
int sumDigits (char *str) {
	int i = 0, sum = 0;
	while (str[i] != '\0') {
		sum += asciiToInt (str[i]);
		++i;
	}
	return sum;
}

// returns decimal value of ascii value
int asciiToInt (char c) {
	return c - '0';
}
