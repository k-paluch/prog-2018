#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playfair.h"
#include <stdbool.h>


char* playfair_encrypt(const char* key, const char* text) {

	if (strlen(key) == 0 || strlen(text) == 0){
		return NULL;
	}
	if (key == NULL || text == NULL){
		return NULL;
	}

	for (int i = 0; i < strlen(key); i++) {
		if (!(isalpha(key[i]))) {
			return NULL;
		}
	}

	for (int i = 0; i < strlen(text); i++){
		if (!(isalpha(text[i]) || text[i] == ' ')) {
			return NULL;
		}
	}

	char board[5][5];
	for(int i=0; i<5;i++){
		for(int j =0; j<5; j++){
			board[j][i]=' ';
		}
	}

	char alpha = 65;
	int i = -1, j, k=1 , o = 0;
	bool flag = true;

    	while(flag){
    		i++;
    		k--;
    		j = -1;
    		while(j < 5 && flag){
    			j++;
    			if (isalpha(key[k])){
    				o = 0;
    				while(o < k){
    					if(key[k] == key[o]){
    						flag = false;
    						j--;
    						break;
    					}
    					o++;
    				}
    				if (flag){
    					board[i][j] = toupper(key[k]);
    					if(board[i][j] == 'W') board[i][j] = 'V';
    				}
    				flag = true;
    			}
    			k++;
    			if (key[k] == '\0')
    				flag = false;
    		}
    	}

	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if(board[i][j] != ' ') continue;
			else{
				do{
					if(alpha == 'W') alpha++;
					flag = false;
					for (int k = 0; k < 5; k++)
						for(int o = 0; o < 5; o++)
							if (board[k][o] == alpha){
								alpha++;
								flag = true;
								break;
							}
				}while(flag != false);
				board[i][j] = alpha;
				alpha++;
			}
		}
	}


	int b = 0;

	char* help= (char*)calloc(strlen(text), strlen(text)*sizeof(char));
 	 k = 0;

	for(int i = 0; i < strlen(text); i++){
		if(isalpha(text[i])){
			if(toupper(text[i]) == 'W') help[k] = 'V';
			else help[k] = toupper(text[i]);
			k++;
		}
		if(text[i] == ' '){
			while(text[i] == ' '){
				i++;
				b--;
			}
			if(toupper(text[i]) == 'W') help[k] = 'V';
			else help[k] = toupper(text[i]);
			k++;
		}
	}
	help[k] = '\0';
	
		int a = 0;
	char* rip=(char*)calloc(2*strlen(help)+1, (2*strlen(help)+1)*sizeof(char)); 
	for(int i = 0; i < strlen(help); i=i+2){
		if(help[i] == help[i+1] && help[i] != 'X'){
			k = i+1;
			a = 0;
			while(help[k] != '\0'){
				rip[a] = rip[k];
				k++;
				a++;
			}
			rip[a] = '\0';
			k = i+2;
			a = 0;
			help[i+1] = 'X';
			while(rip[a] != '\0'){
				help[k] = rip[a];
				k++;
				a++;
			}
			b++;
			
		}
	}
	int length = strlen(text);
	help[length+b] = '\0';
	if(strlen(help) % 2 != 0){
		help[length+b] = 'X';
		b++;
		help[length+b] = '\0';
	}
	
	free(rip);

	length = strlen(help);
	char* encrypted = (char*)calloc(length+(length/2-1), (length+(length/2-1))*sizeof(char));
	int pomoc, x, y, x1, y1;
	for(int n = 0; n < length/2; n++){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				if(board[i][j] == help[2*n]){
					x = i;
					y = j;
				}
				if(board[i][j] == help[2*n + 1]){
					x1 = i;
					y1 = j;
				}
			}
		}

		if(x == x1 && y == y1){
			if(x == 4){
				x = 0;
				x1 = 0;
				help[2*n] = board[x][y];
				help[2*n + 1] = board[x1][y1];
			}
		}

		else if(x != x1 && y == y1){
			if(x == 4) x = 0;
			else x++;
			if(x1 == 4) x1 = 0;
			else x1++;
			help[2*n] = board[x][y];
			help[2*n + 1] = board[x1][y1];
		}
		else if(x != x1 && y != y1){
			pomoc = y1;
			y1 = y;
			y = pomoc;
			help[2*n] = board[x][y];
			help[2*n + 1] = board[x1][y1];
		}
		else if(x == x1 && y != y1){
			if(y == 4) y = 0;
			else y++;
			if(y1 == 4) y1 = 0;
			else y1++;
			help[2*n] = board[x][y];
			help[2*n + 1] = board[x1][y1];
		}

		
	}
	i = 0;
	for (int n = 0; n < length/2; n++)
	{
		encrypted[i] = help[2*n];
		encrypted[i+1] = help[2*n + 1];
		encrypted[i+2] = ' ';
		i = i + 3;
	}
	encrypted[i+1] = '\0';

	free(help);
	return encrypted;


}

char* playfair_decrypt(const char* key, const char* text) {

	if (key == NULL || text == NULL){
		return NULL;
	}
	if(strlen(key)==0||strlen(text)==0){
	        return NULL;
        }
    	for (int i = 0; i < strlen(key); i++) {
		if (!(isalpha(key[i]))) {
			return NULL;
		}
	}
	for (int i = 0; i < strlen(text); i++){
		if (!(isalpha(text[i]) || text[i] == ' ')) {
			return NULL;
		}
	}
    return NULL;

}

