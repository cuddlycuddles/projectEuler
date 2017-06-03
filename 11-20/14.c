#include <stdio.h>
#include <assert.h>

#define LIMIT 1000000

void testFunctions (void);
int numWondrous (long  x);

int main (int argc, char *argv[]) {
	testFunctions();
	long curr = 1, most = 0;
	int currTerms, mostTerms = 0;
	while (curr < LIMIT) {
		currTerms = numWondrous (curr);
		if (currTerms > mostTerms) {
			mostTerms = currTerms;
			most = curr;
		}
		++curr;
	}
	printf ("%li\n", most);
}

void testFunctions (void) {
	assert (numWondrous (1) == 1);
	assert (numWondrous (27) == 112);
	assert (numWondrous (871) == 179);
	assert (numWondrous (6171) == 262);
	assert (numWondrous (77031) == 351);
	assert (numWondrous (837799) == 525);
	assert (numWondrous (8400511) == 686);
	assert (numWondrous (670617279) == 987);
	printf ("Functions work.\n");
}

int numWondrous (long x) {
	int terms = 1;
	while (x != 1) {
		if (x % 2 == 0) { // if even
			x /= 2;
		} else { // if odd
			x = (3 * x) + 1;
		}
		++terms;
	}
	return terms;
}
