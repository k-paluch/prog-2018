#include <stdio.h>
#include <stdlib.h>
#include "container.h"
#include "room.h"
#include "command.h"
#include "item.h"

struct container* create_container(struct container* first, enum container_type type, void* entry)
{	
	struct container* container = first;
	
	if(first != NULL)
	{
		while(container->next != NULL)
			container = container->next;
			
		container->next = (struct container*)malloc(sizeof(struct container));
		container = container->next;
	}
	else
		container = (struct container*)malloc(sizeof(struct container));
	
	container->type = type;
	if(container->type == ROOM)
		container->room = entry;
	else if(container->type == ITEM)
		container->item = entry;
	else if(container->type == COMMAND)
		container->command = entry;
	else if(container->type == TEXT)
		container->text = entry;
		
	if(first == NULL){
		return container;
	}
	else{
		return container;
	}
}


struct container* destroy_containers(struct container* first, enum container_type type)
{
	if(first == NULL){
		return NULL;
	}
	struct container* container = NULL;
	
	for(struct container *cursor = first; cursor != NULL; cursor = container)
	{
		container = cursor->next;
		free(cursor);
	}
	
	return NULL;
}

void* get_from_container_by_name(struct container* first, enum container_type type, const char* name)
{
	return NULL;
}

struct container* delete_from_container(struct container* first, enum container_type type, void* entry)
{
	return NULL;
}
