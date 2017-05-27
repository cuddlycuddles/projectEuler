#include <stdio.h>

int numWondrous (long  x);

int main (int argc, char *argv[]) {
	long curr = 1, most = 0;
	int currTerms, mostTerms = 0;
	while (curr < 1000000) {
		currTerms = numWondrous (curr);
		if (currTerms > mostTerms) {
			mostTerms = currTerms;
			most = curr;
		}
		++curr;
	}
	printf ("%li\n", most);
}

int numWondrous ( long x) {
	int terms = 1;
	while (x != 1) {
		if (x % 2 == 0) {
			x /= 2;
		} else {
			x = (3 * x) + 1;
		}
		++terms;
	}
	return terms;
}
