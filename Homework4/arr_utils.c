#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "arr_utils.h"


int sumArrs(int *arr1, int *arr2, int len, int *outputArr) 
{
	if(outputArr != NULL && arr1 != NULL && arr2 != NULL){
		for(int i = 0;i<len;i++){
			outputArr[i] = arr1[i] + arr2[i];
		}
		return 1;
	}
	else{
		return 0;
	}
	return 0;
}

int minAtSameIndex(int *arr1, int *arr2, int *arr3, int len, int *index)
{
	if(arr1 == NULL || arr2 == NULL || arr3 == NULL){
		return 0;
	}

	int minloc1=0;
	int minloc2=0;
	int minloc3=0;
	if(index != NULL){
		for(int i=1;i<len;i++){
			if(arr1[i] <= arr1[minloc1]){
				minloc1 = i;
			}
			if(arr2[i] <= arr2[minloc2]){
				minloc2 = i;
			}
			if(arr3[i] <= arr3[minloc3]){
				minloc3 = i;
			}
			if((minloc1 == minloc2) && (minloc2 == minloc3)){
				if (*index <= 0 || *index > minloc1) {
					*index = minloc1;
				}
			}
		//printf("%d %d ||  %d %d %d ||  %d %d %d\n", *index, i, arr1[i], arr2[i], arr3[i], minloc1, minloc2, minloc3);
		}
		if (*index >= 0 && *index <= len) {
			//printf("=================\n");
			return 1;
		} else {
			*index = -1;
			//printf("=================\n");
			return 0;
		}
	}
	//printf("=================\n");
	return 0;
}
