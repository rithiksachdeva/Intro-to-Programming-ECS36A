#include "my_strtok.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static char* string;


char* myStrtok(const char* str, const char* delims)
{
	int len = 0;
	char *retStr = NULL;
	char *startStr = (char*) str;
	int szAlloc = 0, i;
	if(delims != NULL){
		len = strlen(delims);
	} else {
		return NULL;
	}
	if((str == NULL) && (string == NULL)) {
		return NULL;
	}
	if(str == NULL){
		i = 0;
		while(i < len) {
			if(*string == delims[i]){
				++string;
				i = 0;
			} else {
				i++;
			}
		}
		startStr = string;
	} else {
		string = (char *)str;
	}
	for ( ; *string; ++string){
		for(i = 0;i<len;i++){
			if(*string == delims[i]){
				string++;
				szAlloc = string - startStr;
				retStr = calloc(1, szAlloc);
				memcpy(retStr, startStr, szAlloc-1);
				return (retStr);
			}
		}
	}
	szAlloc = string-startStr;
	if (szAlloc > 1) {
		retStr = calloc(1,szAlloc);
		memcpy(retStr, startStr, szAlloc);
	}
	return (retStr);
}