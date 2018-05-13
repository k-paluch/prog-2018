#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
#include"room.h"

struct room* create_room(char* name, char* description){
	struct room* room= (struct room*)malloc(sizeof(struct room));
	room->name = name;
	room->description= description;
	return room;
}

struct room* destroy_room(struct room*room){
	room=NULL;
	free(room);
	return NULL;
}

void set_exits_from_room(struct room* room, struct room* north, struct room* south, struct room *east,struct room* west){
	if(north==NULL){
		room->north=NULL;
	}
	else{
		room->north = north;
	}

	if(east==NULL){
		room->east=NULL;
	}
	else{
		room->east=east;
	}
	
	if(west==NULL){
		room->west=NULL;
	}
	else{
		room->west=west;
	}

	if(south==NULL){
		room->south=NULL;
	}
	else{
		room->south=south;
	}
}

void show_room(const struct room* room){
	printf("%s\n", room->description);
	printf("--------------\nExits\n");
	if(room->north != NULL)
		printf("    sever\n");
	if(room->south != NULL)
		printf("    juh\n");
	if(room->east != NULL)
		printf("    vychod\n");
	if(room->west != NULL)
		printf("    zapad\n");
	printf("++++++++++++++\n");
}

void delete_item_from_room(struct room* room, struct item* item){
	
}

struct item* get_item_from_room(const struct room* room , const char* name){
/*	while(room->items->item!=NULL){
		if(room->items->item==name){
			return room->items->item;
		}
		room->items->item = room->next->item;
	}*/
	return NULL;
}
