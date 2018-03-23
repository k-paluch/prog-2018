#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bmp.h"
#include<math.h>
char* reverse(const char* text){
	if(text == NULL){
		return NULL;
	}
	int i = (int)(strlen(text));
	int j;
	char* help=( char*) malloc ((i+1) *sizeof( char));
	if(help == NULL){
		return NULL;
	}
	if(i!=0){
		for (j = 1; j <= i; j++) {
			help[j-1] = toupper(text[i-j]);
   		}
		help[i]='\0';
	}
	else{
		help[i]='\0';
	}
	return help;
}

char* vigenere_encrypt(const char* key,const char* text){

if(text == NULL || key == NULL) return NULL;
	if(text[0] == '\0' || key[0] == '\0') return NULL;
	
	int check = 0;
	for(int i = 0; i < strlen(text); i++)
		if(isalpha(text[i])){
			check = 1;
			break;
		}
	if(check == 0) return NULL;
	for(int i = 0; i < strlen(key); i++)
		if(!isalpha(key[i])) return NULL;
	
	int dlzka = strlen(text); 
	
	int flag = 0;
	for(int i = 0; i < dlzka; i++){
		if(isalpha(text[i])){
			flag = 1;
			break;
		}
	}
	if(flag == 0) 
		return NULL;
	for(int i = 0; i < strlen(key); i++) if(!isalpha(key[i])) return NULL;
	
	int i;
	char* klucik;
	dlzka = 0;

	for (int i = 0; text[i] != '\0'; i++){
		if(isalpha(text[i])) dlzka++;
	}
	klucik = (char*)calloc(dlzka, dlzka*sizeof(char));
	for(i = 0; i < dlzka; i++){
		klucik[i] = ' ';
	}
	klucik[i] = '\0';
	if(strlen(key) < dlzka){
		for(int i = 0, j = 0; klucik[i] != '\0';i++, j++){
			if(key[j] == '\0'){
				j = 0;
				klucik[i] = toupper(key[j]);	
			}
			else klucik[i] = toupper(key[j]);
		}	
	}
	else{
		for(int i = 0, j = 0; i != dlzka; i++, j++){
			 klucik[i] = toupper(key[j]);
		}	

	}
	

	char* shifr;
	int rasstojanije = 0;
	shifr = (char*)calloc(strlen(text), strlen(text)*sizeof(char));
	strcpy(shifr, text);
	for(int i = 0, j = 0; shifr[i] != '\0'; i++){
		if(isalpha(shifr[i])){
			rasstojanije = toupper(klucik[j]) - 65;
			if((toupper(shifr[i]) + rasstojanije) > 'Z'){
				shifr[i] = 64 + (toupper(shifr[i]) + rasstojanije - 'Z');
			}
			else shifr[i] = toupper(shifr[i]) + rasstojanije;
			j++;
		}
	}
	free(klucik);
	shifr[strlen(text)] = '\0';

	return shifr;
}

char* vigenere_decrypt(const char* key,const char* text){
	if(text == NULL || key == NULL) return NULL;
	if(text[0] == '\0' || key[0] == '\0') return NULL;
	for(int i = 0; i < strlen(key); i++)
		if(!isalpha(key[i]))
			return NULL;
	
	int check = 0;
	for(int i = 0; i < strlen(text); i++)
		if(isalpha(text[i])){
			check = 1;
			break;
		}
	
	if(check == 0)
		return NULL;
	int i;
	char* klucik;
	int dlzka = 0;
	for (i = 0; text[i] != '\0'; i++){
		if(isalpha(text[i])) dlzka++;
	}
	klucik = (char*)calloc(dlzka+1, (dlzka+1)*sizeof(char));
	for(i = 0; i < dlzka; i++)
		klucik[i] = ' ';
	klucik[i] = '\0';
	if(strlen(key) < dlzka){
		for(int i = 0, j = 0; klucik[i] != '\0';i++, j++){
			if(key[j] == '\0'){
				j = 0;
				klucik[i] = toupper(key[j]);	
			}
			else klucik[i] = toupper(key[j]);
		}	
	}
	else{
		for(int i = 0, j = 0; i != dlzka; i++, j++)
			 klucik[i] = toupper(key[j]);	
	}
	dlzka = strlen(text);
	char* decrypted;
	int rasstojanije;
	decrypted = (char*)calloc(dlzka, dlzka*sizeof(char));

	for(int i = 0, j = 0; i < dlzka ; i++){
		if(isalpha(text[i])){
			rasstojanije = klucik[j] - 65;
			if(text[i] - rasstojanije < 'A')
				decrypted[i] = 'Z' - (64 - (text[i] - rasstojanije));
			else decrypted[i] = text[i] - rasstojanije;
			j++;
		}
		else decrypted[i] = text[i];
	}
	free(klucik);
	decrypted[dlzka] = '\0';
	return decrypted;

}

unsigned char* bit_encrypt(const char* text){
	if(text==NULL){
		return NULL;
	}
	int textl=strlen(text);
	unsigned char* help = (unsigned char*)malloc((textl+1)*sizeof(unsigned char));
	char bin[8]= {2^7,2^6,2^5,2^4,2^3,2^2,2^1,2^0};
	char bits[8];
	char firsthalf[4];
	char secondhalf[4];
	char first[4];
//	if(textl==0){
//		return NULL;
//	}
	if(help==0){
		return NULL;
	}
	char temp;
	int i;
	for(i=0; i<textl; i++){
		temp=text[i];
		for(int j=0; j<8;j++){
			bits[j]=temp%2;
			temp = temp/2;
		}
		firsthalf[0]=bits[6];
		firsthalf[1]=bits[7];
		firsthalf[2]=bits[4];
		firsthalf[3]=bits[5];
		secondhalf[0]=bits[3];
		secondhalf[1]=bits[2];
		secondhalf[2]=bits[1];
		secondhalf[3]=bits[0];
		for(int j=0; j<4;j++){
			first[j]=firsthalf[j];
			if(firsthalf[j]==secondhalf[j]){
				firsthalf[j]='0';
			}
			else{
				firsthalf[j]='1';
			}
		}
		for(int j=0; j<4; j++){
			bits[j]=first[j];
			bits[j+4]=firsthalf[j];
		}
		help[i]=0;
		for(int j =0;j<8; j++){
			help[i]= help[i]+(bits[j]*bin[j]);
		}
	}
	help[i]='\0';
	return help;
}

char* bit_decrypt(const unsigned char* text){
	if(text ==NULL){
		return NULL;
	}
	int textl=strlen((char*)text);
	char* help = (char*)malloc((textl+1)*sizeof(char));
	unsigned char bin[8]= {2^7,2^6,2^5,2^4,2^3,2^2,2^1,2^0};
	unsigned char bits[8];
	unsigned char firsthalf[4];
	unsigned char secondhalf[4];
	unsigned char first[4];
	if(help==0){
		return 0;
	}
	int i;
	unsigned char temp;
	for(i=0; i< textl; i++){
		temp=text[i];
		for(int j=0; j<8;j++){
			bits[j]= temp%2;
			temp = temp/2;
		}
		for(int j = 0; j <4; j++)
		{
			firsthalf[j] = bits[7-j];
			secondhalf[j] = bits[3-j];
		}
		first[0]=firsthalf[1];
		first[1]=firsthalf[0];
		first[2]=firsthalf[3];
		first[3]=firsthalf[2];
		for(int j=0; j<4; j++){
			if(secondhalf[j]==0){
				firsthalf[j]=secondhalf[j];
			}
			else{
				if(firsthalf[j]==0){
					secondhalf[j]=0;
				}
				else{
					secondhalf[j]=1;
				}
			}
		}
		for (int j=0; j<4; j++){
			bits[j]=first[j];
			bits[j+4]=secondhalf[j];
		}
		help[i]=0;
		for(int j =0; j<8; j++){
			help[i]= help[i]+(bin[j]*bits[j]);
		}
	}
	help[i]='\0';
	return help;
}

unsigned char* bmp_encrypt(const char* key, const char* text){
	if(key==NULL){
		return NULL;
	}
	if(text==NULL){
		return NULL;
	}
	char *r=reverse(text);
	char *vigen = vigenere_encrypt(key,r);
	unsigned char *returnn= bit_encrypt(vigen);
	free(r);
	free(vigen);
	return returnn;
}

char* bmp_decrypt(const char* key, const unsigned char *text){
	if(key==NULL){
		return NULL;
	}
	if(text==NULL){
		return NULL;
	}
	char* b=bit_decrypt(text);
	char* vigen=vigenere_decrypt(key,b);
	char* returnn=reverse(vigen);
	free(b);
	free(vigen);
	return returnn;
}
