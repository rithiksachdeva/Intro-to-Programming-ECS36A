#include "prog5.h"

int* calculateRowSums(int** vals, int numRows, int* rowWidths)
{
	if(rowWidths == NULL){
		return 0;
	}	
	if(vals == NULL){
		return 0;
	}	
	for(int k =0;k<numRows;k++){
		if(&vals[k]==NULL){
			return 0;
		}
	}
	for(int k =0;k<numRows;k++){
		if(vals[k] == NULL){
			return 0;
		}
	}
	int* arr = malloc(numRows * sizeof(int));
	for(int i=0;i<numRows;i++){
		arr[i] = sumArrays(vals[i],rowWidths[i]);
	}
	return arr;
}

int sumArrays(int *array, int length)
{
	int sum = 0;
	for(int i=0;i<length;i++){
		sum += array[i];
	}
	return sum; 
}

int sumSubsquare(int** arr, int numRows, int numCols, int rowStart,int rowEnd, int colStart, int colEnd, int* result)
{
	if(arr == NULL){
		return 0;
	}
	if(numRows < rowStart || numRows < rowEnd || rowStart > rowEnd){
		return 0;
	}
	if(numCols < colStart || numCols < colEnd || colStart > colEnd){
		return 0;
	}
	if(result == NULL){
		return 0;
	}
	for(int k=0;k<numRows;k++){
		if(&arr[k]==NULL){
			return 0;
		}
	}
	*result = 0;
	for(int i=rowStart;i<=rowEnd;i++){
		for(int j=colStart;j<=colEnd;j++){
			*result+=(int)arr[i][j];
		}
	}
	return 1;
}
int* applyTransformation(char **strings, int numStrings, int (*transform)(char*))
{
	int* x = malloc(numStrings * sizeof(int));
	for(int i=0;i<numStrings;i++){
		x[i] = transform(strings[i]);
	} 
	return x;
}
