#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "container.h"
#include "room.h"
#include "parser.h"
#include "world.h"
#include "game.h"

int main()
{
/*	struct room* start = create_room("start", "Nic nevidis, no na zemi je baterka.");
	struct room* library = create_room("library", "Vsade len same knihy, no ziadne dvere.");
		
	set_exits_from_room(start, library, NULL, NULL, NULL);
	set_exits_from_room(library, NULL, start, NULL, NULL);
	
	show_room(start);
	show_room(library);
	
	
	printf("start %s _|||_ %s\n", start->name, start->description);
		
	struct container* first = NULL;
	
	first = create_container(first, ROOM, start);
	printf("first %s _|||_ %s\n", first->room->name, first->room->description);
	first = create_container(first, ROOM, library);
	printf("first %s _|||_ %s\n", first->next->room->name, first->next->room->description);
	
	set_exits_from_room(first->room, first->next->room, NULL, NULL, NULL);
	set_exits_from_room(first->next->room, NULL, first->room, NULL, NULL);
	
	destroy_room(start);
	destroy_room(library);
	destroy_containers(first);
	
	
	struct parser *balik = create_parser();
	
	printf("north %s\n", balik->commands->next->next->command->description);
	
	char* input = " SEVER                         ";
	struct command* cmd = parse_input(balik, input);
	if(cmd != NULL)
	{
		printf("HAAAALELUJA\n");
	}
	
	balik = destroy_parser(balik);
	
	struct game *gamee = create_game();
	gamee = destroy_game(gamee);
	struct container* world = create_world();
	world = destroy_world(world);
	
	struct game* game = create_game();
	struct room* severna = create_room("north room", "Tato miestnost je na severe.");
	struct room* juzna = create_room("south room", "Tato miestnost je na juhu.");
	set_exits_from_room(severna, NULL, juzna, NULL, NULL);
	set_exits_from_room(juzna, severna, NULL, NULL, NULL);
	game->current_room = severna;
	printf("current room %s\n", game->current_room->name);
	struct command* command = parse_input(game->parser, "  Commands  ");
	execute_command(game, command);
	printf("current room after %s\n", game->current_room->name);
	destroy_game(game);
	free(severna);
	free(juzna);*/
	return 0;
}
