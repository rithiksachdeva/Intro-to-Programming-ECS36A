#include "str_utils.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void teststrrpbrk(void)
{       
	//Canvas 1
        char str[] = "Hi, how are you?";
	char *ptr = strrpbrk(str, "yeo");
	int ans = strcmp(ptr, "ou?");
	assert(ans == 0);
	
	//Canvas 2
	char str2[] = "AA BBB C DDD EE";
        char *ptr2 = strrpbrk(str2, " ");
        int ans2 = strcmp(ptr2, " EE");
        assert(ans == 0);	
	
	//Case 6 autograder
        char str3[] = "ABCDABCDABCD";
        char *ptr3 = strrpbrk(str3, "BCA");
	int ans3 = strcmp(ptr3, "CD");
        assert(ans == 0);

	//Null input
	char *ptr4 = strrpbrk(NULL, " ");
	assert(ptr4 == 0);	

	//No matches
	char str5[] = "ABCDABCDABCD";
        char *ptr5 = strrpbrk(str5, "EFG");
        assert(ptr5 == 0);

	//1 Target
	char str6[] = "I have been working on this all day";
	char *ptr6 = strrpbrk(str6,"a");
	int ans6 = strcmp(ptr6, "ay");
	assert(ans6 == 0);
	//Many targets
	char str7[] = "I have been working on this all day";
        char *ptr7 = strrpbrk(str7,"dsl");
        int ans7 = strcmp(ptr7, "day");
        assert(ans7 == 0);	

	fprintf(stderr, "teststrrpbrk(): All test cases passed!\n");
}

void testparseForHighest(void)
{
	//NULL input
	int highest=0;
	int hi1 = parseForHighest(NULL,&highest);
	assert(hi1 == 0);
	//NULL highest
	char input1[] = "5;6;7;8";
	int hi2 = parseForHighest(input1, NULL);
	assert(hi2 == 0);
	//Canvas 1
	char str1[] = "5;83;22;42";
	int highest1 = -1;
	int retval1 = parseForHighest(str1, &highest1);
	assert(retval1 == 1);
	assert(highest1 == 83);
	//negatives
	char str2[] = "-60;-67;-23;-72";
        int highest2 = -1;
        int retval2 = parseForHighest(str2, &highest2);
        assert(retval2 == 1);
        assert(highest2 == -23);
	//negatives and positives
	char str3[] = "5;-67;89;-72";
        int highest3 = -1;
        int retval3 = parseForHighest(str3, &highest3);
        assert(retval3 == 1);
        assert(highest3 == 89);

	fprintf(stderr, "testparseForHighest(): All test cases passed!\n");

}




int main()
{
	teststrrpbrk();
	testparseForHighest();
}
