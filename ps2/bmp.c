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
	
	for(int i = 0; i < strlen(key); i++)
		if(!isalpha(key[i])) return NULL;
	
	int textl = strlen(text); 
	int keyl=strlen(key);
	for(int i = 0; i < keyl; i++) if(!isalpha(key[i])) return NULL;
	
	int i;
	char* help;
	int pomoc = 0;

	for (int i = 0; text[i] != '\0'; i++){
		if(isalpha(text[i])) pomoc++;
	}
	help = (char*)calloc(pomoc, pomoc*sizeof(char));
	for(i = 0; i < pomoc; i++){
		help[i] = ' ';
	}
	help[i] = '\0';
	if(keyl < pomoc){
		for(int i = 0, j = 0; help[i] != '\0';i++, j++){
			if(key[j] == '\0'){
				j = 0;
				help[i] = toupper(key[j]);	
			}
			else help[i] = toupper(key[j]);
		}	
	}
	else{
		for(int i = 0, j = 0; i != pomoc; i++, j++){
			 help[i] = toupper(key[j]);
		}	

	}
	

	char* encrypt;
	int helpp = 0;
	encrypt = (char*)calloc(textl, textl*sizeof(char));
	strcpy(encrypt, text);
	for(int i = 0, j = 0; encrypt[i] != '\0'; i++){
		if(isalpha(encrypt[i])){
			helpp = toupper(help[j]) - 65;
			if((toupper(encrypt[i]) + helpp) > 'Z'){
				encrypt[i] = 64 + (toupper(encrypt[i]) + helpp - 'Z');
			}
			else encrypt[i] = toupper(encrypt[i]) + helpp;
			j++;
		}
	}
	free(help);
	encrypt[textl] = '\0';

	return encrypt;

}

char* vigenere_decrypt(const char* key,const char* text){
	if(text == NULL || key == NULL) return NULL;
	if(text[0] == '\0' || key[0] == '\0') return NULL;
	for(int i = 0; i < strlen(key); i++)
		if(!isalpha(key[i]))
			return NULL;
	
	int i;
	char* help;
	int dlzka = 0;
	for (i = 0; text[i] != '\0'; i++){
		if(isalpha(text[i])) dlzka++;
	}
	help = (char*)calloc(dlzka+1, (dlzka+1)*sizeof(char));
	for(i = 0; i < dlzka; i++)
		help[i] = ' ';
	help[i] = '\0';
	int keyl = strlen(key);
	if(keyl < dlzka){
		for(int i = 0, j = 0; help[i] != '\0';i++, j++){
			if(key[j] == '\0'){
				j = 0;
				help[i] = toupper(key[j]);	
			}
			else help[i] = toupper(key[j]);
		}	
	}
	else{
		for(int i = 0, j = 0; i != dlzka; i++, j++)
			 help[i] = toupper(key[j]);	
	}
	int textl = strlen(text);
	char* decrypted;
	int helpp;
	decrypted = (char*)calloc(textl, textl*sizeof(char));

	for(int i = 0, j = 0; i < textl ; i++){
		if(isalpha(text[i])){
			helpp = help[j] - 65;
			if(text[i] - helpp < 'A')
				decrypted[i] = 'Z' - (64 - (text[i] - helpp));
			else decrypted[i] = text[i] - helpp;
			j++;
		}
		else decrypted[i] = text[i];
	}
	free(help);
	decrypted[textl] = '\0';
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
