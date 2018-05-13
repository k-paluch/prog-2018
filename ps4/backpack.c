#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"backpack.h"
bool is_backpack_full(struct backpack* backpack){
	int count=0;
	while (backpack->items!= NULL){
		count++;
	}
	if(backpack->capacity > count){
		return false;
	}
	return true;
}
struct backpack* create_backpack(const int capacity){
	struct backpack* backpack = (struct backpack*)malloc(sizeof(struct backpack));
	backpack->capacity = capacity;
	return backpack;
}

struct backpack* destroy_backpack(struct backpack* backpack){
	//struct backpack* backpack = (struct backpack*)malloc(sizeof(struct backpack));
	backpack = NULL;
	free(backpack);
	return NULL;	
}

bool add_item_to_backpack(struct backpack* backpack, struct item* item){
	if (item==NULL||backpack==NULL)return false;
	backpack->items->item = item;
	return true;
}

void delete_item_from_backpack(struct backpack* backpack, struct item* item){
	backpack->items->item=NULL;
	free(backpack->items->item);
}

struct item* get_item_from_backpack(const struct backpack* backpack, char* name){
	struct item* item = (struct item*)malloc(sizeof(struct item));
	while(item !=NULL){
		if(backpack->items->item->name==name){
			return item;
		}
	}
	return NULL;
}
