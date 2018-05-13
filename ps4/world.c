#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "world.h"

struct container* create_world()
{
	struct container *world = NULL;
	struct room *begin = create_room("Begin", "Otvaras oci, ktore si len pomaly zvykaju na slabe svetlo. Ked uz vidis, uvedomis si, ze sa nachadzas v zatvorenej miestnosti bez okien. Mozes ist len cez dvere, ktore su na juhu");
	world = add_room_to_world(world, begin);
	struct room *predsien = create_room("Predsien", "Si v uzkej miestnosti osvetlenej slabym zelenym svetlom. Nic extra tu nie je.");
	world = add_room_to_world(world, predsien);
	set_exits_from_room(begin, NULL, predsien, NULL, NULL);
	set_exits_from_room(predsien, begin, NULL, NULL, NULL);
	return world;
}

struct container* add_room_to_world(struct container* world, struct room* room)
{
	struct container* next_con = NULL;
	for(struct container *cursor = world; cursor != NULL; cursor = next_con)
	{
		next_con = cursor->next;
		if((strcmp(cursor->room->name, room->name) == 0))
			return NULL;
	}
	
	world = create_container(world, ROOM, room);
	return world;
}

struct container* destroy_world(struct container* world)
{
	struct container* next_con = NULL;
	for(struct container *cursor = world; cursor != NULL; cursor = next_con)
	{
		next_con = cursor->next;
		cursor->room = destroy_room(cursor->room);
	}
	
	destroy_containers(world);
	return NULL;
}

struct room* get_room(struct container* world, char* name)
{
	return NULL;
}
