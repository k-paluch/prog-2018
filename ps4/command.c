#include"command.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct command* create_command(char* name, char* description, char* pattern, size_t nmatch)
{
	if(name == NULL || description == NULL){
		return NULL;
	}
        size_t nlen = strlen(name);
	size_t dlen = strlen(description);
	if(nlen == 0 || dlen == 0){
		return NULL;
	}
	struct command* command = (struct command*)calloc(1, sizeof(struct command));
	
	command->name = name;
	command->description = description;
	
	return command;
}

struct command* destroy_command(struct command* command)
{
	free(command);
	return NULL;
}
