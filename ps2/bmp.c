#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bmp.h"
#include<math.h>
#include <assert.h>
char* reverse(const char* text){
	if(text == NULL){
		return NULL;
	}
	int i = (int)(strlen(text));
	int j;
	char* help=( char*) malloc ((i) *sizeof( char));
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
	
   if( text == NULL)
	{
		return NULL;
	}
	
	char binary[8]={128, 64, 32, 16, 8,4,2,1};
	int textl;
	unsigned char *help;
	char bity[8];
	char first[4];
	char second[4];
	char temp[4];
	char doc;
	int i,j;

	textl =strlen(text);
	if( textl == 0)
	{
		return NULL;
	}
	help= (unsigned char*) malloc ( (textl+1)* (sizeof(unsigned char)));
	if( help == NULL)
	{
		return NULL;
	}
	for( i = 0; i < textl;i++)
	{
		doc = text[i];
		for(j= 0; j < 8; j++)
		{
			bity[j] = doc % 2;
			doc = doc / 2;
		}
		first[0] = bity[6];
		first[1] = bity[7];
		first[2] = bity[4];
		first[3] = bity[5];
		second[0]= bity[3];
		second[1]= bity[2];
		second[2]= bity[1];
		second[3]= bity[0];
		for( j =0; j < 4; j++)
		{
			temp[j]=first[j];
			if( first[j] == second[j] )
			{
				first[j] = 0;
			}
			else
			{
				first[j] = 1;
			}
		}
		for( j = 0; j < 4; j++)
		{
			bity[j] =temp[j];
			bity[j+4] = first[j];
		}
		help[i]=0;
		for( j=0; j < 8;j++)
		{
			help[i]= help[i]+ (bity[j] * binary[j]);
		}

	}
	help[ i ] = '\0';

	return help;

}

char* bit_decrypt(const unsigned char* text){
	
	 if( text == NULL )
	{
		return NULL;
	}
	
	int textl ;
	unsigned char binary[8]={ 128,64,32,16,8,4,2,1};
	char *help;
	int i,j;
	unsigned char bits[8];
	unsigned char first[4];
	unsigned char second[4];
	unsigned char temp[4];
	unsigned char doc;

	textl = strlen( (char*)text);
	if( textl == 0)
	{
		return NULL;
	}
	help = (char*) malloc ((textl+1) * ( sizeof( char )));
	if( help == NULL)
	{
		return NULL;
	}
	for( i = 0; i < textl; i++ )
	{
		doc = (unsigned char)text[i];
		for( j= 0; j < 8; j++)
		{
			bits[j] = doc % 2;
			doc = doc /2;
		}
		for( j = 0; j <4; j++)
		{
			first[j] = bits[7-j];
			second[j] = bits[3-j];
		}
		temp[0] = first[1];
		temp[1] = first[0];
		temp[2] = first[3];
		temp[3] = first[2];
		for( j = 0; j < 4; j++)
		{
			if ( second[j] == 0)
			{
				second[j] = first[j];
			}
			else
			{
				if( first[j] == 1)
				{
					second[j]=0;
				}
				else
				{
					second[j]=1;
				}
			}
		}
		for(j = 0; j < 4; j++)
		{
			bits[j] = temp[j];
			bits[4+j] = second[j];

		}
		help[i]=0;
		for(j = 0; j < 8; j++)
		{
			help[i] = help[i] + (binary[j]*bits[j]);
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
	/*return (key==NULL || text==NULL) ? NULL : bit_encrypt(vigenere_encrypt(key, reverse(text)));
*/}

char* bmp_decrypt(const char* key, const unsigned char *text){
	if(key==NULL||text==NULL){
		return NULL;
	}
	char* b=bit_decrypt(text);
	char* vigen=vigenere_decrypt(key,b);
	char* returnn=reverse(vigen);
	free(b);
	free(vigen);
	return returnn;
	/*return (key==NULL || text==NULL) ? NULL : reverse(vigenere_decrypt(key,bit_decrypt(text)));
*/
}
