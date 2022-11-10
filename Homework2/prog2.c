#include <stdio.h>

int isUpper(int c){
	if (c>64 && c<91)
		return 1;
	else
		return 0;
}
int isLower(int c){
        if (c>96 && c<123)
                return 1;
        else
                return 0;
}
int isAlpha(int c){
        if ((c>64 && c<91)||(c>96 && c<123))
                return 1;
        else
                return 0;
}
int isDigit(int c){
        if (c>47 && c<58)
                return 1;
        else
                return 0;
}
int toLower(int c){
	if(c>64 && c<91)
		c=c+32;
	return c;
}
int toUpper(int c){
        if(c>96 && c<123)
                c=c-32;
        return c;
}
int foo(void){
	char x;
	int count=0;
	do{
		printf("Enter character: ");
		scanf(" %c",&x); /*found out that putting space before %c would skip leading whitespace from Stack Overflow */
		count = count+1;
	}while((int)x>96 && (int)x<123);
		if((int)x>64 && (int)x<91)
			printf("Entered uppercase letter!\n");
		else
			printf("Did not enter letter!\n");
		return(count-1);
}
int goo(void){
	int num1;
	int num2;
	int total=0;
	do{
		printf("Enter num1: ");
		scanf(" %d",&num1);
		printf("Enter num2: ");
		scanf(" %d",&num2);
		total = total + (num1 * num2);
	}while(num1 * num2 != 0);
		return total;
}
int foo2(int n, int k){
	int i;
	int j;
	int count = 0;
	int total = 0;
	
	for(i = 1; i<n+1; i++){
		count = 0;
		for(j = 1; j<i+1;j++){
			if (i%j == 0)
				count = count+1;
		} 
		if(count == k)
			total = total+1;
	}
	return total;
}

// ===== CUT HERE =====

int main(){
	printf("foo2(5,2) returned %d\n",foo2(5,2));
	printf("foo2(12,3) returned %d\n", foo2(12,3));
}
