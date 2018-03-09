#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hof.h"

int load(struct player list[]){
	FILE *fp = fopen(HOF_FILE, "r");
	if(fp==NULL){return -1;}

	int rank =0;
		while(fscanf(fp,"%29s %d", list[rank].name, &list[rank].score)!= EOF&&rank < 10){
			rank++;
		}
//		fscanf(fp,"%29s %d", list[rank].name, &list[rank].score);
	char temp[29];
	for(int i=0; i<9;i++){
		for(int j=i+1; j<10;j++){
			if(strcmp(list[i].name,list[j].name)){
				strcpy(temp,list[i].name);
				strcpy(list[i].name,list[j].name);
				strcpy(list[j].name,temp);
			}
		}
	}
	fclose(fp);
	return rank;
}

bool save(const struct player list[],const int size){
	FILE *fp = fopen(HOF_FILE, "w");
	if(fp == NULL){return false;}
	for(int i=0; i<size;i++){
		fprintf(fp, "%s %d\n",list[i].name,list[i].score);
	}
	fclose(fp);
	return true;
}

bool add_player(struct player list[], int *size, const struct player player){
	bool help = false;
	int rank =280798;
	int i;
//	struct player listhelp;
	for(i =0; i<= *size; i++){
		if(list[i].score < player.score){
			rank =i;
			break;
		}
	}
	if(rank==280798 && *size <10){
		list[*size] = player;
		(*size)+=1;
		help = true;
	}
	if(rank!=280798){
		for(i=(*size); i > rank; i--){
			if(i == 10){
				continue;
			}
			list[i]= list[i-1];
		}
		list[i] = player;
		if(*size <10){
			(*size) +=1;
		}
		help = true;
	}
	char temp[29];
//	int zmena=0;	
//	do{
		for(int i=0; i<*size-1;i++){
			if(list[i].score==list[i+1].score){
					if(strcmp(list[i].name,list[i+1].name) >0){
					/*listhelp = list[i+1];
					list[i+1] = list[i];
					list[i] = listhelp;
					listhelp=player;
					zmena = 1;*/
					strcpy(temp,list[i].name);
					strcpy(list[i].name,list[i+1].name);
					strcpy(list[i+1].name,temp);
				}
			}
		}
//	}while(zmena==1);
	return help;
}
