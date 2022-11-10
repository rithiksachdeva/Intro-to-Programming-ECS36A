#include "prog5.h"

void testCalculateRowSums(void)
{
	int row1[] = {1, 2, 3};
	int row2[] = {4, 5};
	int row3[] = {6, 7, 8, 9, 9};
	int rowWidths[] = {3, 2, 5};
	int numRows = 3;
	int *rows[] = {row1, row2, row3};
	int* sums = calculateRowSums(rows, numRows, rowWidths);
	assert(sums[0] == 6);
	assert(sums[1] == 9);
	assert(sums[2] == 39);

	int row4[] = {10,11,12,56,72};
	int row5[] = {4,6,7,8,9,10};
	int row6[] = {4,5};
	int rowWidths1[] = {5,6,2};
	int *rows1[] = {row4,row5,row6};
	int *sums3 = calculateRowSums(rows1, numRows, rowWidths1);
	assert(sums3[0] == 161);
	assert(sums3[1] == 44);
	assert(sums3[2] == 9);
	//NULL array
	int* sums1 = calculateRowSums(NULL, numRows, rowWidths);
	assert(sums1 == 0);
	//NULL width	
	int* sums2 = calculateRowSums(rows, numRows, NULL);
	assert(sums2 == 0);
	
	free(sums);
	free(sums3);
	fprintf(stderr, "testCalculateRowSums(): All test cases passed!\n");
}
void testSumSubSquare(void)
{
	//square-normal
	{
		int nr = 5;
		int nc = 5;
		int** arr = malloc(nr * sizeof(int*));
		for (int r = 0; r < nr; ++r)
			arr[r] = malloc(nc * sizeof(int));
		arr[0][0] = 1;
		arr[0][1] = 2;
		arr[0][2] = 3;
		arr[0][3] = 4;
		arr[0][4] = 5;
		arr[1][0] = 1;
		arr[1][1] = 2;
		arr[1][2] = 3;
		arr[1][3] = 4;
		arr[1][4] = 5;
		arr[2][0] = 1;
		arr[2][1] = 2;
		arr[2][2] = 3;
		arr[2][3] = 4;
		arr[2][4] = 5;
		arr[3][0] = 1;
		arr[3][1] = 2;
		arr[3][2] = 3;
		arr[3][3] = 4;
		arr[3][4] = 5;
		arr[4][0] = 1;
		arr[4][1] = 2;
		arr[4][2] = 3;
		arr[4][3] = 4;
		arr[4][4] = 5;
		int result = -1;
		int sum1 =sumSubsquare(arr,nr,nc,1,2,1,2,&result); 
		assert(sum1 == 1);
		assert(result==10);
		for (int r = 0; r < nr; ++r)
			free(arr[r]);
		free(arr);
	}

	//whole thing
	{
		int nr = 5;
		int nc = 5;
		int** arr = malloc(nr * sizeof(int*));
		for (int r = 0; r < nr; ++r)
			arr[r] = malloc(nc * sizeof(int));
		arr[0][0] = 1;
		arr[0][1] = 2;
		arr[0][2] = 3;
		arr[0][3] = 4;
		arr[0][4] = 5;
		arr[1][0] = 1;
		arr[1][1] = 2;
		arr[1][2] = 3;
		arr[1][3] = 4;
		arr[1][4] = 5;
		arr[2][0] = 1;
		arr[2][1] = 2;
		arr[2][2] = 3;
		arr[2][3] = 4;
		arr[2][4] = 5;
		arr[3][0] = 1;
		arr[3][1] = 2;
		arr[3][2] = 3;
		arr[3][3] = 4;
		arr[3][4] = 5;
		arr[4][0] = 1;
		arr[4][1] = 2;
		arr[4][2] = 3;
		arr[4][3] = 4;
		arr[4][4] = 5;
		int result = -1;
		int sum1 =sumSubsquare(arr,nr,nc,0,4,0,4,&result);
		assert(sum1 == 1);
		assert(result==75);
		for (int r = 0; r < nr; ++r)
			free(arr[r]);
		free(arr);
	}
	
	//1 element subsquare
	int nr = 1;
	int nc = 1;
	int** arr = malloc(nr * sizeof(int*));
	for (int r = 0; r < nr; ++r)
		arr[r] = malloc(nc * sizeof(int));
	arr[0][0] = 1;
	int result = -1;
	int sum1 =sumSubsquare(arr,nr,nc,0,0,0,0,&result);
	assert(sum1 == 1);
	assert(result == 1);
	for (int r = 0; r < nr; ++r)
		free(arr[r]);
	free(arr);
	//NULL arr
	{
		int result = -1;
		int sum1 =sumSubsquare(NULL,1,1,0,4,0,4,&result);
		assert(sum1 == 0);
	}
	//NULL result
	{
		int nr = 1;
		int nc = 1; 
		int** arr = malloc(nr * sizeof(int*));
		for (int r = 0; r < nr; ++r)
			arr[r] = malloc(nc * sizeof(int));
		arr[0][0] = 1;
		int sum1 =sumSubsquare(arr,nr,nc,0,0,0,0,NULL);
		assert(sum1 == 0);
		for (int r = 0; r < nr; ++r)
			free(arr[r]);
		free(arr);
	}

	//rowEnd > nr
	{
		int nr = 1;
		int nc = 1;
		int** arr = malloc(nr * sizeof(int*));
		for (int r = 0; r < nr; ++r)
			arr[r] = malloc(nc * sizeof(int));
		arr[0][0] = 1;
		int result = -1;
		int sum1 =sumSubsquare(arr,nr,nc,0,2,0,0,&result);
		assert(sum1 == 0);
		for (int r = 0; r < nr; ++r)
			free(arr[r]);
		free(arr);
	}
	
	fprintf(stderr, "testSumSubSquare(): All test cases passed!\n");
}
static int testTransform1(char* str)
{
        if (!strcmp(str, "abc")) return 0;
        else if (!strcmp(str, "def")) return 1;
        else return 2;
}

static int testTransform2(char* str)
{
        if (strlen(str) < 3) return 0;
        else return str[2];
}
static int testTransform3(char* str)
{
        if(strlen(str) < 6) return 1;
        else return 0;
}

void testApplyTransformation(void)
{
	//testtransform1
	{
		int len = 4;
		char *terms[] = {"abc", "def", "ghi", "def"};
		int* arr = applyTransformation(terms, len, testTransform1);
		assert(arr[0] == 0);
		assert(arr[1] == 1);
		assert(arr[2] == 2);
		assert(arr[3] == 1);
		free(arr);
	}
	//testtransform2
	{
		int len = 5;
		char *terms[] = {"ab", "cde", "efgh", "", "ijk"};
		int* arr = applyTransformation(terms, len, testTransform2);
		assert(arr[0] == 0);
		assert(arr[1] == 101);
		assert(arr[2] == 103);
		assert(arr[3] == 0);
		assert(arr[4] == 107);
		free(arr);
	}
	//testtransform3
	{
		int len = 7;
		char *terms[] = {"corona", "quarantine", "I", "want", "to", "go", "outside"};
		int* arr = applyTransformation(terms, len, testTransform3);
		assert(arr[0] == 0);
		assert(arr[1] == 0);
		assert(arr[2] == 1);
		assert(arr[3] == 1);
		assert(arr[4] == 1);
		assert(arr[5] == 1);
		assert(arr[6] == 0);
		free(arr);
	}
	fprintf(stderr, "testApplyTransformation(): All test cases passed!\n");
}
int main()
{
	testCalculateRowSums();
	testSumSubSquare();	
	testApplyTransformation();
}
