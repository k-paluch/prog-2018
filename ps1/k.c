#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "k.h"

void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}

bool update(struct game *game, int dy, int dx){
	int scoreplus[11] = {2,4,8,16,32,64,128,256,512,1024,2048};
	bool hodnota;
	if(dy == -1){
		for (int i=0; i < SIZE;i++){
			for(int j=0; j < SIZE;j++){
				for(int prechadzat =j; prechadzat >0; prechadzat--){
					if(game->board[prechadzat+1][i]== ' '){
						break;
					}
					if(game->board[prechadzat][i]== ' ' && game->board[prechadzat+1][i] != ' '){
						game->board[prechadzat][i] = game->board[prechadzat+1][i];
						game->board[prechadzat+1][i]= ' ';
						hodnota = true;
					}
					else if(game->board[prechadzat+1][i]!=' ' && game->board[prechadzat][i] == game->board[prechadzat+1][i]){
						game->board[prechadzat+1][i] = ' ';
						game->board[prechadzat][i]++;
						game->score += scoreplus[(game->board[prechadzat][i])-65];
						hodnota =true;
						break;
					}
				}
			}
		}
	}

	if(dy == 1){
		for(int i=0; i<SIZE;i++){
			for(int j=SIZE-2;j<SIZE;j--){
				for(int prechadzat=0; prechadzat<SIZE-1;prechadzat++){
					if(game->board[prechadzat-1][i]== ' '){
						break;
					}
					if(game->board[prechadzat][i]== ' ' && game->board[prechadzat-1][i] != ' '){
						game->board[prechadzat][i] = game->board[prechadzat-1][i];
						game->board[prechadzat-1][i]= ' ';
						hodnota = true;
					}
					else if(game->board[prechadzat][i]!=' ' && game->board[prechadzat][i] == game->board[prechadzat-1][i]){
						game->board[prechadzat-1][i] = ' ';
						game->board[prechadzat][i]++;
						game->score += scoreplus[(game->board[prechadzat][i])-65];
						hodnota =true;
						break;
					}
				}
			}
		}
	}

	if(dx ==1){
		for(int i=0; i < SIZE; i++){
			for(int j=SIZE-1; j>0;j--){
				for(int prechadzat=j; prechadzat<SIZE-1; prechadzat++){
					if(game->board[i][prechadzat-1]== ' '){
						break;
					}
					if(game->board[i][prechadzat]== ' ' && game->board[i][prechadzat-1] != ' '){
						game->board[i][prechadzat] = game->board[i][prechadzat-1];
						game->board[i][prechadzat-1]= ' ';
						hodnota = true;
					}
					else if(game->board[i][prechadzat]!=' ' && game->board[i][prechadzat] == game->board[i][prechadzat-1]){
						game->board[i][prechadzat-1] = ' ';
						game->board[i][prechadzat]++;
						game->score += scoreplus[(game->board[i][prechadzat])-65];
						hodnota =true;
						break;
					}
				}
			}
		}
	}

	if(dx == -1){
		for(int i =0; i<SIZE; i++){
			for(int j=0; j<SIZE-1;j++){
				for(int prechadzat=j; prechadzat > 0; prechadzat++){
					if(game->board[i][prechadzat+1]== ' '){
						break;
					}
					if(game->board[i][prechadzat]== ' ' && game->board[i][prechadzat-1] != ' '){
						game->board[i][prechadzat] = game->board[i][prechadzat+1];
						game->board[i][prechadzat+1]= ' ';
						hodnota = true;
					}
					else if(game->board[i][prechadzat]!=' ' && game->board[i][prechadzat] == game->board[i][prechadzat+1]){
						game->board[i][prechadzat+1] = ' ';
						game->board[i][prechadzat]++;
						game->score += scoreplus[(game->board[i][prechadzat])-65];
						hodnota =true;
						break;
					}
				}
			}
		}
	}
	return hodnota;
}

bool is_move_possible(const struct game game){
	for (int i=0;i<SIZE; i++){
	       for (int j=0; j <SIZE; j++){
		       if (j<(SIZE-1) && i <(SIZE-1)){
			       if(game.board[i][j] == game.board[i][j+1] || game.board[i][j] == game.board[i+1][j]){
				       return true;
			       }
		       }
		       else if(j ==(SIZE-1) && i < (SIZE-1)){
			       if(game.board[i][j] == game.board[i+1][j]){
				       return true;
			       }
		       }
		       else if(i == (SIZE-1) && j < (SIZE-1)){
			       if(game.board[i][j] == game.board [i][j+1]){
				       return true;
			       }
		       }
	       }
	}
	return false;
}

bool is_game_won(const struct game game){
	for (int i=0; i < SIZE; i++){
		for (int j=0; j < SIZE; j++){
			if(game.board[i][j]== 'K'){
				return true;
			}
		}
	}
	return false;
}
