#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "bmp.h"
#include "playfair.h"
int main(){
	/*char* reversed= reverse("Hello world!");
	printf("%s\n",reversed);
	char* encrypted;
	encrypted = bit_encrypt("Hello world!");
	for(int i=0; i < 12;i++) {
		    printf("%x ", encrypted[i]);
		        //80 9c 95 95 96 11 bc 96 b9 95 9d 10
			}
			free(encrypted);*/
/*char* reversed = reverse("Hello world!");
printf("%s\n", reversed);
// "!DLROW OLLEH"
char* encrypted;

// basic test with long text
encrypted = vigenere_encrypt("CoMPuTeR", "Hello world!");
printf("%s\n", encrypted);
// "JSXAI PSINR!"
unsigned char* encryptedd;

// basic test with long text
encryptedd = bit_encrypt("Hello world!");
for(int i=0; i < 12;i++) {
    printf("%x ", encryptedd[i]);
    //80 9c 95 95 96 11 bc 96 b9 95 9d 10
}
free(encryptedd);*/

char *encrypted, *decrypted;

// even length of string
encrypted = playfair_encrypt("SeCReT", "Hello world");
printf("%s", encrypted);
// "Hello world" --> "HELXLOVORLDX"
// IS JZ JQ XN TK JC
decrypted = playfair_decrypt("SeCReT", encrypted);
printf("%s", decrypted);
// HELXLOVORLDX
free(encrypted);
free(decrypted);

// odd length of string
encrypted = playfair_encrypt("world", "Hello");
printf("%s", encrypted);
// "Hello" --> "HELXLO"
// JB RY DR
decrypted = playfair_decrypt("world", encrypted);
printf("%s", decrypted);
// HELXLO
free(encrypted);
free(decrypted);

// letter 'X' in message
encrypted = playfair_encrypt("Password", "Taxi please");
printf("%s", encrypted);
// "Taxi please" --> "TAXIPLEASE"
// UP YH AK DO OB
decrypted = playfair_decrypt("Password", encrypted);
printf("%s", decrypted);
// TAXIPLEASE
free(encrypted);
free(decrypted);

// multi 'X's in message
encrypted = playfair_encrypt("please", "Taxxxiii");
printf("%s", encrypted);
// "Taxxxiii" --> "TAXXXIIXIX"
// RS EE VJ JV JV
decrypted = playfair_decrypt("please", encrypted);
printf("%s", decrypted);
// TAXXXIIXIX
free(encrypted);
free(decrypted);


	return 0;
}
