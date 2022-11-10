#include <stdio.h>

int main(){
	int numCents;
	printf("Enter number of cents: ");
	scanf("%d", &numCents);
	int numQuarters = numCents / 25;
	numCents = numCents % 25;
	int numDimes = numCents / 10;
	numCents = numCents % 10;
	int numNickels = numCents / 5;
	numCents = numCents % 5;
	int numPennies = numCents;
	printf("q=%d, d=%d, n=%d, p=%d\n", numQuarters, numDimes, numNickels, numPennies);
}
