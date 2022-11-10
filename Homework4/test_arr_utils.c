#include "arr_utils.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>


void testSumArrs(void)
{
	//Canvas
	int arr1[] = {5, 8, 3}; 
	int arr2[] = {-9, 19, 20};
	int outputArr[3];
	int retval = sumArrs(arr1, arr2, 3, outputArr);
	assert(retval == 1);
	assert(outputArr[0] == -4);
	assert(outputArr[1] == 27);
	assert(outputArr[2] == 23);
	//NULL arr1
	int retval1 = sumArrs(NULL, arr2, 3, outputArr);
	assert(retval1 == 0);
	//NULL arr2
	int retval2 = sumArrs(arr1, NULL, 3, outputArr);
        assert(retval2 == 0);
	//NULL outputARR
        int retval3 = sumArrs(arr1, arr2, 3, NULL);
        assert(retval3 == 0);
	//all positives
	int arr3[] = {1,2,3};
	int arr4[] = {3,4,5};
	int retval4 = sumArrs(arr3, arr4, 3, outputArr);
	assert(retval4 == 1);
	assert(outputArr[0] == 4);
	assert(outputArr[1] == 6);
	assert(outputArr[2] == 8);
	//all negatives
	int arr5[] = {-1,-2,-3};
        int arr6[] = {-3,-4,-5};
        int retval5 = sumArrs(arr5, arr6, 3, outputArr);
        assert(retval5 == 1);
        assert(outputArr[0] == -4);
        assert(outputArr[1] == -6);
        assert(outputArr[2] == -8);
	//mixture of positive and negative
	int arr7[] = {1,-2,3};
        int arr8[] = {-3,4,-5};
        int retval6 = sumArrs(arr7, arr8, 3, outputArr);
        assert(retval6 == 1);
        assert(outputArr[0] == -2);
        assert(outputArr[1] == 2);
        assert(outputArr[2] == -2);
	
	fprintf(stderr, "testSumArrs(): All test cases passed!\n");
}
void testMinAtSameIndex(void)
{
	//Canvas 1 minimum each, same index
	int arr1[] = {5, 19, 20, 4, 3, 5};
	int arr2[] = {700, 200, -1, 53, -89, 70};
	int arr3[] = {53, 44, 22, 19, 18, 19}; 
	int index = -2;
	int retval = minAtSameIndex(arr1, arr2, arr3, 6, &index); 
	assert(retval == 1);
	assert(index == 4);

	//Canvas more than 1 minimum, same index
	int arr4[] = {1, 1, 2, 3};
	int arr5[] = {4, 3, 3, 5}; 
	int arr6[] = {-1, -1, 2, -1};
	int index1 = -2;
	int retval1 = minAtSameIndex(arr4, arr5, arr6, 4, &index1);
	assert(retval1 == 1);
	assert(index1 == 1);
	
	//NULL array
	int retval2 = minAtSameIndex(NULL, arr5, arr6, 4, &index1);
	assert(retval2 == 0);
	int retval3 = minAtSameIndex(arr4, NULL, arr6, 4, &index1);
        assert(retval3 == 0);
	int retval4 = minAtSameIndex(arr4, arr5, NULL, 4, &index1);
        assert(retval4 == 0);
	//NULL output
	int retval5 = minAtSameIndex(arr4, arr5, arr6, 4, NULL);
        assert(retval5 == 0);
	//No matches
	int arr10[] = {5, 5, 5, 5, 5, 5, 5, 5};
        int arr11[] = {10, 1, 1, 1, 10, 1, 1, 1};
        int arr12[] = {1, 10, 10, 10, 1, 10, 10, 10}; 
	int index2 = -2;
        int retval6 = minAtSameIndex(arr10, arr11, arr12, 8, &index2);
	assert(retval6 == 0);
	assert(index2 == -1);
	// Canvas Case 3
	int arr7[] = {5, 0, -1, 13, -1}; 
	int arr8[] = {40, 20, 300, 20, 19};
	int arr9[] = {0, 1, 2, 3, -5};
	int index3 = -2;
	int retval7 = minAtSameIndex(arr7, arr8, arr9, 5, &index3);
	assert(retval == 1);
	assert(index3 == 4);
	
	// minimum at first index
	int arr13[] = {0,4,3,2,1};
	int arr14[] = {2,9,8,7,6};
	int arr15[] = {1,14,13,12,11};
	int index4 = -2;
	int retval8 = minAtSameIndex(arr13,arr14,arr15,5,&index4);
	assert(retval8 == 1);
	assert(index4 == 0);
	
	//minimum at last index
	int arr16[] = {5,8,5,7,1};
        int arr17[] = {10,9,8,7,6};
        int arr18[] = {15,16,17,18,11};
        int index5 = -2;
        int retval9 = minAtSameIndex(arr16,arr17,arr18,5,&index5);
        assert(retval9 == 1);
        assert(index5 == 4);

	int arr19[] = {5,5,5,5,5};
        int arr20[] = {10,10,10,10,10};
        int arr21[] = {1,1,1,1,1};
        int index6 = -2;
        int retval10 = minAtSameIndex(arr19,arr20,arr21,5,&index6);
        assert(retval10 == 1);
        assert(index6 == 0);

	fprintf(stderr, "testMinAtSameIndex(): All test cases passed!\n");
}
int main()
{
	testSumArrs();
	testMinAtSameIndex();
}
