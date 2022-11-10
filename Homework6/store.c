#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "store.h"

struct Store* initStore(const char* storeName, const char* fileName)
{
	FILE* fp = fopen(fileName, "r");
	if(fp == NULL){
		return NULL;
	}
	struct Store* s = malloc(sizeof(struct Store));
	s->storeName = (char*)storeName;
	char x[MAX_LINE_LEN];
	fgets(x,MAX_LINE_LEN,fp);
	s->numItems = atoi(x);
	struct Item* arr_items = malloc(s->numItems * sizeof(struct Item));
	for(int i = 0; i<s->numItems; i++){
		char buf[MAX_LINE_LEN] = "";
		fgets(buf, MAX_LINE_LEN, fp);
		char* tmp = strtok(buf," ");
		int num = strlen(tmp);
		arr_items[i].name = malloc((num+1) * sizeof(char));
		strcpy(arr_items[i].name,tmp);
		arr_items[i].price = atoi(strtok(NULL, " "));
		arr_items[i].numInStock = atoi(strtok(NULL, "\\n"));
	}
	s->items = arr_items;
	fclose(fp);
	return(s);		
}

struct Item* getCheapestItem(struct Store* store)
{
	int index = 0;
	int comparePriceOrig = store->items[0].price;
	for(int i = 1;i<store->numItems; i++){
		int comparePrice = store->items[i].price;
		if(comparePrice < comparePriceOrig){
			index = i;
			comparePriceOrig = comparePrice;
		}
	}
	struct Item *cheapest = &store->items[index];
	return(cheapest);
}

void deallocateStore(struct Store* store)
{
	for(int i=0;i<store->numItems;i++){
		free(store->items[i].name);
	}
	free(store->items);
	free(store);
}

void printStoreItems(const struct Store* store)
{
	printf("%s has the following items:\n", store->storeName);
	for(int i=0;i<store->numItems;i++){
		printf("Item #%d: %s, Price: %d, Number in stock: %d\n",i+1, store->items[i].name, store->items[i].price,store->items[i].numInStock);
	}
}