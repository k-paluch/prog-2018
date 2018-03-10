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
	char riadok[SIZE];
	int  points[10] = { 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048 };
	int  i,j,k,m;
	if( dx == -1 && dy == 0)
	{
		for( m = 0, i = 0; i < SIZE; i++)
		{
			for( k = 0; k < SIZE; k++)
			{
				riadok[ k ] = '0';
			}
			for( k = 0, j = 0; j < SIZE; j++ )
			{
				if( game->board[i][j] != ' ' )
				{
					if( j == 0)
					{
						riadok[k] = game->board[i][j];
					}
					else
					{
					if( riadok[ k ] == game->board[i][j] )
					{
						game->score = game->score + points[ riadok[k] - 'A' ];
						riadok[k]++;
						k++;
					}
					else
					{
						k++;
						riadok[k] = game->board[i][j];

					}
					}

				}

			}
			for( k =0 ,j = 0 ; j < SIZE; j++)
			{
				if( riadok[j] != '0' )
				{
					game->board[i][k] = riadok[j];
					k++;
				}

			}
			if( k == SIZE)
			{
				m++;
			}
			for (;k < SIZE; k++)
			{
				game->board[i][k] = ' ';
			}
		}
		if ( m > SIZE-1)
		{
			return false;
		}
		return true;
	}
	if( dx == 1 && dy == 0)
	{
		for( m = 0, i = 0; i < SIZE; i++)
		{
			for( k = 0; k < SIZE; k++)
			{
				riadok[ k ] = '0';
			}
			for( k = SIZE-1, j = SIZE-1; j >= 0; j-- )
			{
				if( game->board[i][j] != ' ' )
				{
					if( j == SIZE-1)
					{
						riadok[k] = game->board[i][j];
					}
					else
					{
					if( riadok[ k ] == game->board[i][j] )
					{
						game->score = game->score + points[ riadok[k] - 'A' ];
						riadok[k]++;
						k--;
					}
					else
					{
						k--;
						riadok[k] = game->board[i][j];

					}
					}

				}

			}
			for( k = SIZE-1 ,j = SIZE-1 ; j >= 0; j--)
			{
				if( riadok[j] != '0' )
				{
					game->board[i][k] = riadok[j];
					k--;
				}

			}
			if( k == -1)
			{
				m++;
			}
			for (;k >=0 ; k--)
			{
				game->board[i][k] = ' ';
			}
		}
		if ( m > SIZE-1)
		{
			return false;
		}
		return true;
	}
	if( dx == 0 && dy == 1)
	{
		for( m = 0, j = 0; j < SIZE; j++)
		{
			for( k = 0; k < SIZE; k++)
			{
				riadok[ k ] = '0';
			}
			for( k = SIZE-1, i = SIZE-1; i >= 0; i-- )
			{
				if( game->board[i][j] != ' ' )
				{
					if( i == SIZE-1)
					{
						riadok[k] = game->board[i][j];
					}
					else
					{
					if( riadok[ k ] == game->board[i][j] )
					{
						game->score = game->score + points[ riadok[k] - 'A' ];
						riadok[k]++;
						k--;
					}
					else
					{
						k--;
						riadok[k] = game->board[i][j];

					}
					}

				}

			}
			for( k =SIZE-1 ,i = SIZE-1 ; i >= 0; i--)
			{
				if( riadok[i] != '0' )
				{
					game->board[k][j] = riadok[i];
					k--;
				}

			}
			if( k == -1)
			{
				m++;
			}
			for (;k >= 0; k--)
			{
				game->board[k][j] = ' ';
			}
		}
		if ( m > SIZE-1)
		{
			return false;
		}
		return true;
	}
	if( dx == 0 && dy == -1)
	{

			for( m = 0, j = 0; j < SIZE; j++)
			{
				for( k = 0; k < SIZE; k++)
				{
					riadok[ k ] = '0';
				}
				for( k = 0, i = 0; i < SIZE; i++ )
				{
					if( game->board[i][j] != ' ' )
					{
						if( i == 0)
						{
							riadok[k] = game->board[i][j];
						}
						else
						{
						if( riadok[ k ] == game->board[i][j] )
						{
							game->score = game->score + points[ riadok[k] - 'A' ];
							riadok[k]++;
							k++;
						}
						else
						{
							k++;
							riadok[k] = game->board[i][j];

						}
						}

					}

				}
				for( k =0 ,i = 0 ; i < SIZE; i++)
				{
					if( riadok[i] != '0' )
					{
						game->board[k][j] = riadok[i];
						k++;
					}

				}
				if( k == SIZE)
				{
					m++;
				}
				for (;k < SIZE; k++)
				{
					game->board[k][j] = ' ';
				}
			}
			if ( m > SIZE-1)
			{
				return false;
			}
			return true;
	}
	return false;
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
