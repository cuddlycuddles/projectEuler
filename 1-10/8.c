#include <stdio.h>
#define STRING_LENGTH 13
#define LAST_STARTPOINT 987

void substr (char *orig, char *dest, int start, int len);
unsigned long long multiplyDigits (char *str);
int asciiToInt (char c);

int main (int argc, char *argv[]) {
	unsigned long long current, largest = 0;
	int x = 0;
	char thousandDigits[] =
	"73167176531330624919225119674426574742355349194934"
	"96983520312774506326239578318016984801869478851843"
	"85861560789112949495459501737958331952853208805511"
	"12540698747158523863050715693290963295227443043557"
	"66896648950445244523161731856403098711121722383113"
	"62229893423380308135336276614282806444486645238749"
	"30358907296290491560440772390713810515859307960866"
	"70172427121883998797908792274921901699720888093776"
	"65727333001053367881220235421809751254540594752243"
	"52584907711670556013604839586446706324415722155397"
	"53697817977846174064955149290862569321978468622482"
	"83972241375657056057490261407972968652414535100474"
	"82166370484403199890008895243450658541227588666881"
	"16427171479924442928230863465674813919123162824586"
	"17866458359124566529476545682848912883142607690042"
	"24219022671055626321111109370544217506941658960408"
	"07198403850962455444362981230987879927244284909188"
	"84580156166097919133875499200524063689912560717606"
	"05886116467109405077541002256983155200055935729725"
	"71636269561882670428252483600823257530420752963450";
	char numberHolder[STRING_LENGTH];
	while (x < LAST_STARTPOINT) {
		substr (thousandDigits, numberHolder, x, STRING_LENGTH);
		current = multiplyDigits (numberHolder);
		if (current > largest) {
			largest = current;
		}
		++x;
	}
	printf ("Largest product of 13 adjacent digits = %lli\n", largest);
	return 0;
}

// retrieves len amount of letters from start index of orig string
// and inserts those letters into dest
void substr (char *orig, char *dest, int start, int len) {
	int i = 0;
	while (i < len && orig[start + i] != '\0') {
		dest[i] = orig[start + i];
		++i;
	}
	dest[i] = '\0';
}

// multiplies all the numbers in a string and returns the result
unsigned long long multiplyDigits (char *str) {
	unsigned long long result = 1;
	int i = 0;
	while (str[i] != '\0') { // check if there are any zeros
		if (asciiToInt (str[i++]) == 0) {
			return 0;
		}
	}
	i = 0;
	while (str[i] != '\0') {
		result *= asciiToInt (str[i++]);
	}
	return result;
}

// returns the integer value of an ascii number
int asciiToInt (char c) {
	return c - '0';
}
