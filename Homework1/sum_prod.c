#include <stdio.h>

int main() {
	int num1;
	int num2;
	printf("Enter the first two numbers:\n");
	scanf("%d",&num1);
	scanf("%d", &num2);
	int sum = num1 + num2;
	int product = num1 * num2;
	printf("The sum is: %d.\n", sum);
	printf("The product is: %d.\n", product);
}
