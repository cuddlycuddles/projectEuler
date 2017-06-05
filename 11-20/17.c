#include <stdio.h>
#include <assert.h>

void testFunction (void);

int lettersInNum (int x);

int main (int argc, char *argv[]) {
	testFunction();
	int curr = 1;
	int totalLetters = 0;
	while (curr < 1000) {
		totalLetters += lettersInNum (curr);
		++curr;
	}
	totalLetters += 11; // one thousand
	printf ("%i\n", totalLetters);
	
	printf ("%i\n", lettersInNum(5));
	printf ("%i\n", lettersInNum(5));
	
	return 0;
}

void testFunction (void) {
	assert (lettersInNum (5) == 4);
	assert (lettersInNum (76) == 10);
	assert (lettersInNum (342) == 23);
	assert (lettersInNum (115) == 20);
	assert (lettersInNum (100) == 10);
	printf ("Functions work.\n");
}

int lettersInNum (int x) {
	int total = 0;
	int ones[] =		{3, 3, 5, 4, 4, 3, 5, 5, 4}; // one, two, three...
	int tens[] =		{3, 6, 6, 5, 5, 5, 7, 6, 6}; // ten, twenty, thirty...
	int tensSpecial[] =	{6, 6, 8, 8, 7, 7, 9, 8, 8}; // eleven, twelve, thirteen...
	
	// get number of hundreds, tens and ones
	int nOnes = x % 10;
	x /= 10;
	int nTens = x % 10;
	x /= 10;
	int nHundreds = x % 10;
	x /= 10;
	
	if (nHundreds) {
		total += ones[nHundreds - 1];
		total += 7; // 'hundred'
	}
	if (nTens || nOnes) {
		if (nHundreds) {
			total += 3; // 'and'
		}
		if (nTens && nOnes == 0) { // ten, twenty, thirty...
			total += tens[nTens - 1];
		} else if (nTens) {
			if (nTens == 1) { // eleven, twelve, thirteen...
				total += tensSpecial[nOnes - 1];
			} else { // 24, 11, 99, etc
				total += tens[nTens - 1];
				total += ones[nOnes - 1];
			}
		} else {
			total += ones[nOnes - 1];
		}
	}
	
	return total;
}
