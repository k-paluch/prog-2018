#include "parser.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"container.h"
struct parser* create_parser(){
	struct parser* parser = (struct parser*)malloc(sizeof(struct parser));
	//if (parser!= NULL){
	//	return NULL;
	//}
	parser->history = NULL;
	parser->commands = NULL;
	return parser;
}

struct parser* destroy_parser(struct parser* parser){
	parser->history=NULL;
	parser->commands=NULL;
	free(parser);
	return NULL;
}

struct command* parse_input(struct parser* parser, char* input){
	/*if(input == parser->commands->command){
		return parser->commands->command;
	}*/	
	return NULL;
}
