#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "parser.h"
#include "world.h"

void play_game(struct game* game)
{
	
}

struct game* create_game()
{
	struct game* game = (struct game*)calloc(1, sizeof(struct game));
	game->parser = create_parser();
	game->world = create_world();
	game->current_room = NULL;
	game->backpack = NULL;
	return game;
}

struct game* destroy_game(struct game* game)
{
	destroy_parser(game->parser);
	destroy_world(game->world);
	free(game);
	return NULL;
}

void execute_command(struct game* game, struct command* command)
{
	if(game == NULL){
		return;
	}
	game->state = PLAYING;
	
	if(command == NULL){
		return;
	}
	struct game *new = game;
	
	if(strcmp(command->name, "SEVER") == 0)
	{
		if(new->current_room->north != NULL)
			new->current_room = new->current_room->north;
	}
	else if(strcmp(command->name, "JUH") == 0)
	{
		if(new->current_room->south != NULL)
			new->current_room = new->current_room->south;
	}
	else if(strcmp(command->name, "ZAPAD") == 0)
	{
		if(new->current_room->west != NULL)
			new->current_room = new->current_room->west;
	}
	else if(strcmp(command->name, "VYCHOD") == 0)
	{
		if(new->current_room->east != NULL)
			new->current_room = new->current_room->east;
	}
	else if(strcmp(command->name, "ROZHLIADNI SA") == 0)
	{
		show_room(new->current_room);
	}
	else if(strcmp(command->name, "PRIKAZY") == 0)
	{
		printf("Zoznam prikazov:\n");
		struct container* next_con = NULL;
		for(struct container *cursor = game->parser->commands; cursor != NULL; cursor = next_con)
		{
			next_con = cursor->next;
			printf("%s\t%s\n", cursor->command->name, cursor->command->description);
		}
	}
	else if(strcmp(command->name, "VERZIA") == 0)
	{
		printf("Verzia 1.0.3\n");
	}
	else if(strcmp(command->name, "RESTART") == 0)
	{
		new->state = RESTART;
		destroy_game(new);
		create_game();
	}
	else if(strcmp(command->name, "O HRE") == 0)
	{
		printf("Kracas si ulicou a zrazu bolest a tma.\n");
	}
	else if(strcmp(command->name, "KONIEC") == 0)
	{
		new->state = GAMEOVER;
		destroy_game(new);
	}
}
