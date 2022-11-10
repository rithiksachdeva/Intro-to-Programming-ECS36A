#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "str_utils.h"

char *strrpbrk(char *str, char *targets)
{
	if(str != NULL && targets != NULL){
		int len = strlen(targets);
		int len2 = strlen(str);
		int index = -1;

		for(int i = 0;i<len; i++){
			for(int j = 0;j<len2; j++){
				if(str[j] == targets[i]){
					if(j > index){
						index = j;
					}
				}
			}
		}
		if(index!=-1){
			str = &str[index];

			return str;
		}
		else{
			return NULL;
		}
	}
	else{
		return NULL;
	}
}
int parseForHighest(char *input, int *highest)
{
	if(input != NULL && highest != NULL){
		char *split = strtok(input, ";");
		*highest = atoi(split);
		while( split != NULL ) {
			if(atoi(split) > *highest){
				*highest = atoi(split);
			} 	
			split = strtok(NULL, ";");
		}	

		return 1;
	}
	else{
		return 0;
	}
}
