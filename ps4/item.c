#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"item.h"
struct item* create_item(char* name, char* description, int properties){
	struct item* item = (struct item*)malloc(sizeof(struct item));
	item->name= name;
	item->description= description;
	item->properties=properties;
	return item;
}

struct item* destroy_item(struct item* item){
	item =NULL;
	free(item);
	return NULL;
}
