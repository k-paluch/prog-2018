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
		for(j=0,i=i-1;i>=0; j++){
			help[j]=(char)(toupper(text[i]));
			i--;
		}
		help[j]='\0';
	}
	else{
		help[i]='\0';
	}
	return help;
}

char* viginere_encrypt(const char* key,const char* text){
	if(key ==NULL){
		return NULL;
	}
	if(text == NULL){
		return NULL;
	}
//	int keyl = strlen(key);
	int textl = strlen(text);
	int keyl = strlen(key);
	int k;
	char* help = (char*)malloc((textl+1)*sizeof(char));
	if(textl ==0){
		return NULL;
	}
	if(help == NULL){
		return NULL;
	}
	for(k=0; k<textl;k++){
		if(!isalpha(text[k])){
			free(help);
			return NULL;
		}
	}
	if(keyl==0){
		return NULL;
	}
	int m;
	for(k=0,m=0;k<keyl;k++){
		if(isalpha(text[k])){
			help[k]=(((toupper(text[k])-'A')+(toupper(key[m%keyl])- 'A'))%26) +'A';
			m++;
		}
		else{
			help[k]=text[k];
		}
	}
	help[k]='\0';
	return help;
}

char* viginere_decrypt(const char* key,const char* text){
	if(key ==NULL){
		return NULL;
	}
	if(text == NULL){
		return NULL;
	}
//	int keyl = strlen(key);
	int textl = strlen(text);
	int k,i;
	char* help = (char*)malloc((textl+1)*sizeof(char));
	if(textl ==0){
		return NULL;
	}
	if(help == NULL){
		return NULL;
	}
	for(k=0; k<textl;k++){
		if(!isalpha(text[k])){
			free(help);
			return 0;
		}
	}
//	if(keyl==0){
//		return NULL;
//	}
	int keyl=strlen(key);
	if(keyl==0){
		return NULL;
	}
	for(i =0,k=0;i<textl;i++){
		if(isalpha(text[i])){
			if((toupper(key[k%keyl])-'A')>(toupper(text[i])-'A')){
				help[i]=26-((toupper(key[k%keyl])-'A')-((toupper(text[i]))-'A'))+'A';
			}
			else{
				help[i]=(((toupper(text[i]-'A'))-(toupper(key[k%keyl])-'A'))%26)+'A';
			}
			k++;
		}
		else{
			help[i]=text[i];
		}
	}
	help[i]='\0';
	return help;
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
	char *b;
	char*m;
	unsigned char*p;
	int textl=strlen(text);
	if(textl==0){
		return NULL;
	}
	b = reverse(text);
	if(b==NULL){
		return NULL;
	}
	m=viginere_encrypt(key,b);
	free(b);
	if(m==NULL){
		return NULL;
	}
	p=bit_encrypt(m);
	free(m);
	if(p==NULL){
		return NULL;
	}
	return p;
}

char* bmp_decrypt(const char* key, const unsigned char *text){
	/*if(key==NULL){
		return NULL;
	}
	if(text==NULL){
		return NULL;
	}
	char *help;
	help= text;	
	char *b;
	char *m;
	char *p;
	int textl=strlen((char*)text);
	if(textl==0){
		return NULL;
	}
	b=bit_encrypt(help);
	if(b==NULL){
		return NULL;
	}
	m=vigenere_decrypt(key,b);
	free(b);
	if(m==NULL){
		return NULL;
	}
	p=reverse(m);
	free(m);
	if(p==NULL){
		return NULL;
	}
	return p;*/
	return NULL;
}
