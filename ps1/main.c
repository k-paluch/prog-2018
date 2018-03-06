#include "hof.h"
#include "k.h"
#include <time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include "ui.h"
int main(){
	struct game game;
		for (int i =0; i<SIZE; i++){
			for (int j=0; j < SIZE; j++){
				game.board[i][j] = ' ';
			}
		};
		game.score = 0;
		
	do{
		add_random_tile(&game);
		render(game);
		if(is_move_possible(game) == false){printf("GAME OVER\n"); return 0;};
		if(is_game_won(game) == true){printf("Congratulation you win!!!\n"); return 0;};
		printf("Where to go: ");
		char move[1];
		scanf("%c", &move[0]);
		printf("\n");
		/*if (move[0]=='w'|| move[0] =='W'){
			update(&game, -1, 0);
		}
		if (move[0]=='a'|| move[0] =='A'){
			update(&game, 0, -1);
		}
		if (move[0]=='s'|| move[0] =='S'){
			update(&game, 1, 0);
		}
		if (move[0]=='d'|| move[0] =='D'){
			update(&game, 0, 1);
		}*/
	}while(!is_game_won(game) || is_move_possible(game));
	return 0;
}
