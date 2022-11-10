#include "prog3.h"

void sum3(int a, int b, int c, int *sum)
{
	if(sum != NULL){
		*sum = a + b + c;
	}
}

void testSum3(void)
{
	// Test case #1.
	int sum = 0;
	sum3(5, 8, 19, &sum);
	assert(sum == 32);

	// Test case #2.
	sum3(-5, 20, 0, &sum);
	assert(sum == 15);

	// Test case #3. No assertion needed here; just need a crash to not occur.
	sum3(14, 17, 18, NULL);

	fprintf(stderr, "testSum3(): All test cases passed!\n");
}

int compareArrays(float *arr1, float *arr2, int arrLen, int *pos)
{
	if(arr1 != NULL && arr2 != NULL && pos != NULL){
		*pos = -1;
		for(int i = 0; i<arrLen;i++){
			if(arr1[i]!=arr2[i]){
				*pos = i;
				return 0;
			}
		}
	}
	else{
		return -1;
	}
	return 1;
}

void testCompareArrays(void)
{
	//CASES WHEN ARRAYS ARE THE SAME
	float arr1[] = {1,2,3,4,5};
	float arr2[] = {1,2,3,4,5};
	int pos = -2;
	int retval = compareArrays(arr1,arr2,5,&pos);
	assert(retval == 1);
	assert(pos == -1);
	//CASES WHEN ONLY ARRAY INDEX 1 IS DIFFERENT
	arr1[0] = 0;
	retval = compareArrays(arr1, arr2, 5, &pos);
	assert(retval == 0);
	assert(pos == 1);
	//CASES WHEN ONLY ARRAY INDEX 2 IS DIFFERENT
	arr1[0] = 1;
	arr1[1] = 0;
	retval = compareArrays(arr1, arr2, 5, &pos);
	assert(retval == 0);
	assert(pos == 2);
	//CASES WHEN ONLY ARRAY INDEX 3 IS DIFFERENT
	arr1[1] = 2;
	arr1[2] = 0;
	retval = compareArrays(arr1, arr2, 5, &pos);
	assert(retval == 0);
	assert(pos == 3);
	//CASES WHEN ONLY ARRAY INDEX 4 IS DIFFERENT
	arr1[2] = 3;
	arr1[3] = 0;
	retval = compareArrays(arr1, arr2, 5, &pos);
	assert(retval == 0);
	assert(pos == 4);
	//CASES WHEN ONLY ARRAY INDEX 5 IS DIFFERENT
	arr1[3] = 4;
	arr1[4] = 0;
	retval = compareArrays(arr1, arr2, 5, &pos);
	assert(retval == 0);
	assert(pos == 5);
	//CASES WHEN MULTIPLE ARRAY INDEXES ARE DIFFERENT
	arr1[4] = 5;
	arr1[0] = 0;
	arr1[1] = 0;
	retval = compareArrays(arr1, arr2, 5, &pos);
	assert(retval == 0);
	assert(pos == 1);
	//CASES WITH A NULL IN THE ARR1 SLOT
	retval = compareArrays(NULL, arr2, 5, &pos);
	assert(retval == -1);	
	//CASES WITH A NULL IN THE ARR2 SLOT
	retval = compareArrays(arr1, NULL, 5, &pos);
	assert(retval == -1);
	//CASES WITH A NULL IN THE POS SLOT
	retval = compareArrays(arr1, arr2, 5, NULL);
	assert(retval == -1);
	fprintf(stderr, "testCompareArrays(): All test cases passed!\n");
}

int performShiftCipher(char *inputText, int k, char *outputText)
{
	if(k< (-MAX_SHIFT_CIPHER_KEY) || k > MAX_SHIFT_CIPHER_KEY){
		return 0;
	}
	else{
		while(k>25){
			k = k-26;
		}
		if(inputText != NULL && outputText != NULL){
			int length = strlen(inputText);
			int i;
			for(i = 0;i<length;i++){
				int ascii = (int)inputText[i];
				if(ascii>64 && ascii<91){
					ascii = ascii+k;
					if(ascii>90){
						ascii = ascii - 26;
					}
					if(ascii<65){
						ascii = ascii + 26;
					}
					outputText[i] = (char)ascii;
				}
				else if(ascii>96 && ascii<123){
					ascii = ascii+k;
					if(ascii>122){
						ascii=ascii-26;
					}
					if(ascii<97){
						ascii= ascii + 26;
					}
					outputText[i] = (char)ascii;
				}
				else{
					outputText[i] = (char)ascii;
				}	
			}
			outputText[i] = '\0'; //This line was given to me by my dad because the code kept printing 'yzabZwxyz' and he explained to me that the null identifier is missing on the test string. 
			return 1;
		}
		else{
			return -1;
		}
	}
}
void testPerformShiftCipher(void)
{
	char inputText[] = "Hello, Aaron!";
	char outputText[100];
	//INPUT IS NULL
	int retval = performShiftCipher(NULL, 5, outputText);
	assert(retval == -1);
	//OUTPUT IS NULL
	retval = performShiftCipher(inputText, 5, NULL);
	assert(retval == -1);
	//INPUT AND OUTPUT ARE NULL
	retval = performShiftCipher(NULL, 5, NULL);
	assert(retval == -1);	
	//TEST CASE 1
	char str2[5];
	char str3[5] = "yzab";
	retval = performShiftCipher("wxyz", 2, str2);
	assert(retval == 1);
	assert(strcmp(str2,str3) == 0);
	//TEST CASE 2: INPUT HAS SPECIAL CHARACTERS
	char str4[100];
	char str5[] = "Mjqqt, Ffwts!";
	retval = performShiftCipher("Hello, Aaron!",5,str4);
	assert(retval == 1);
	assert(strcmp(str4,str5) == 0);
	//TEST CASE 3: DECRYPT PREVIOUS CASE
	char str6[] = "Hello, Aaron!";
	retval = performShiftCipher(str5,-5,str4);
	assert(retval == 1);
	assert(strcmp(str4,str6) == 0);
	//INPUT IS VALID BUT CONTAINS NOTHING
	char str7[] = "";
	char str8[2];
	retval = performShiftCipher(str7, 5, str8);
	assert(retval == 1);
	assert(strcmp(str8, str7) == 0);
	//K IS LARGE
	char str9[] = "yzab";
	char str10[5];
	char str11[] = "abcd";
	retval = performShiftCipher(str9, 54, str10);
	assert(retval == 1);
	assert(strcmp(str10,str11) == 0);	
	//INPUT IS LARGE
	char str12[] = "abcdefghijklmnopqrstuvwxyz";
	char str13[27];
	char str14[] = "bcdefghijklmnopqrstuvwxyza";
	retval = performShiftCipher(str12, 1, str13);
	assert(retval == 1);
	assert(strcmp(str13, str14) == 0);

	fprintf(stderr, "testPerformShiftCipher(): All test cases passed!\n");
}

