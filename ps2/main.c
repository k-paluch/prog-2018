#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "bmp.h"
#include "playfair.h"
int main(){

char* reversed = reverse("Hello world!");
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
free(encryptedd);




	return 0;
}
