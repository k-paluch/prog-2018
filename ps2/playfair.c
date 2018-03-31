
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "playfair.h"

#define tableDef 5;


bool hasCharacter(const char* text, const char find, int position, const int size) {
    for (int i = 0; i < size; i++) {
         if (position != -1 && i == position) continue;
        if (text[i] == find) return true;

    }
 return false;

}


void toUpperString (char *text) {
    while (*text != '\0') {
    if (islower(*text)) *text &= ~0x20;
    text++;

    }
}


char* strdup_p (const char *s) {
    char* d = (char*)calloc((strlen(s) + 1), sizeof(char));
    if (d != NULL) strcpy(d, s);
        return d;
}

void deleteCharacter(char *str, char garbage) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;

    }

    *dst = '\0';

}

void replaceWithX(char* text, const int position, const int size) {
    int i;

    for (i = size; i >= 0; i--) {
        if (i == position) {
            text[i] = 'X';
            break;
        } else
            text[i] = text[i-1];
    }

    text[size+1] = '\0';

}

void replace_char(char* text, const char find, const char replace) {
    if (hasCharacter(text, find, -1, (int)strlen(text))) {
        for (int i = 0; i < (int)strlen(text); i++) {
            if (text[i] == find)
                text[i] = replace;

        }

    }

}

void createtable(char** table, const char* word) {
    int d = 0;

    int deftable = tableDef;
    for (int i = 0; i < deftable; i++) {
        table[i] = (char*)calloc(deftable+1, sizeof(char));
        for (int s = 0; s < deftable; s++) {
            table[i][s] = word[d];
            d++;

        }

    }

}


char* playfair_encrypt(const char* key, const char* text) {
    if (key == NULL || text == NULL) return NULL;
    if ((int)strlen(key) < 1) return NULL;


    for (int i = 0; i < (int)strlen(key); i++) {
        if (!isalpha(key[i])){
            return NULL;
        }
    }



    int deftable = tableDef;

    char* new_key = strdup_p(key);



    char* word = (char*)calloc((deftable*deftable)+1, sizeof(char));
    if (word == NULL) {
        free(new_key);

        return NULL;

    }


    toUpperString(new_key);
    replace_char(new_key, 'W', 'V');

    int keyLen = (int)strlen(new_key);

    int minus = 0;
    for (int i = (keyLen-1); i >= 0; i--)
        if (hasCharacter(new_key, new_key[i], i, (int)strlen(new_key))) {
            minus++;
            new_key[i] = ' ';

        }

    deleteCharacter(new_key, ' ');
    keyLen = keyLen - minus + 1;
    new_key[keyLen] = '\0';


    strcpy(word, new_key);

    char spelling[] = ALPHA;

    for (int i = 0, s = (int)strlen(new_key); i < 25; i++) {
        if (!hasCharacter(word, spelling[i], -1, s)) {
            word[s] = spelling[i];
            s++;

        }

    }

    word[25] = '\0';


    char** table = (char**)calloc(deftable, sizeof(char*));
    if (table == NULL) return NULL;
    createtable(table, word);



    int textLen = (int)strlen(text);

    int d = 0;
    for (int a = 0; a <20; a++) {}

    for (int i = 0; i < textLen; i += 2) if (text[i] == text[i+1] && text[i+1] != 'X') d++;

    char* dest = (char*)calloc((textLen + d)+1, sizeof(char));

    if (dest == NULL) {
        free(word);
        free(new_key);

        for (int i = 0; i < deftable; i++) free(table[i]);
        free(table);
        return NULL;

    }



    strcpy(dest, text);

    deleteCharacter(dest, ' ');

    toUpperString(dest);


    replace_char(dest, 'W', 'V');
//pridanie x
    for (int i = 0; i < textLen; i += 2) {
        if (dest[i] == dest[i+1] && dest[i+1] != 'X') {
            replaceWithX(dest, i+1, textLen);

        }

    }
    
    int destLen = (int)strlen(dest);
    if (!(destLen % 2 == 0)) {

        dest[destLen] = 'X';

        dest[destLen+1] = '\0';

    }

    int* first = (int*)calloc(2, sizeof(int));
    int* second = (int*)calloc(2, sizeof(int));

    int countDest = 0;

    char* returnDest = (char*)calloc(((int)strlen(dest)+1), sizeof(char));

    int retDest = 0;

    while (dest[countDest] != '\0') {

        for (int i = 0; i < deftable; i++) {
            for (int s = 0; s < deftable; s++) {

                if ((int)dest[countDest] == (int)table[i][s]) {

                    first[0] = i;

                    first[1] = s;

                }

              

                if (dest[countDest+1] == table[i][s]) {
                    second[0] = i;
                    second[1] = s;

                }
            }
        }

        countDest += 2;

        if (first[0] != second[0] && first[1] != second[1]) { 

            returnDest[retDest++] = table[first[0]][second[1]];
            returnDest[retDest++] = table[second[0]][first[1]];



        } else if (first[0] == second[0] && first[1] != second[1]) { 
            int f = (first[1] == deftable-1 ? 0 : first[1]+1);
            int sec = (second[1] == deftable-1 ? 0 : second[1]+1);


            returnDest[retDest++] = table[first[0]][f];
            returnDest[retDest++] = table[second[0]][sec];





        } else if ((first[0] != second[0] && first[1] == second[1]) || (first[0] == second[0] && first[1] == second[1])) { 
            int f = (first[0] == deftable-1 ? 0 : first[0]+1);
            int sec = (second[0] == deftable-1 ? 0 : second[0]+1);


            returnDest[retDest++] = table[f][first[1]];
            returnDest[retDest++] = table[sec][second[1]];

        }
    }

    returnDest[retDest] = '\0';

    free(first);
    free(second);
    free(word);
    free(new_key);

    for (int i = 0; i < deftable; i++) free(table[i]);
    free(table);
    free(dest);

    return returnDest;

}

char* playfair_decrypt(const char* key, const char* text) {
    if (key == NULL || text == NULL) return NULL;
    if ((int)strlen(key) < 1) return NULL;


    for (int i = 0; i < (int)strlen(key); i++) {
        if (!isalpha(key[i])){
            return NULL;
        }
    }



    if (hasCharacter(text, 'W', -1, (int)strlen(text))) return NULL;

    int deftable = tableDef;

    char* new_key = strdup_p(key);


    char* word = (char*)calloc((deftable*deftable)+1, sizeof(char));

    if (word == NULL) {

        free(new_key);

        return NULL;

    }


    toUpperString(new_key);

    replace_char(new_key, 'W', 'V');


    int keyLen = (int)strlen(new_key);

    int minus = 0;

    for (int i = (keyLen-1); i >= 0; i--)
        if (hasCharacter(new_key, new_key[i], i, (int)strlen(new_key))) {
            minus++;
            new_key[i] = ' ';

        }

    deleteCharacter(new_key, ' ');

    keyLen = keyLen - minus + 1;

    new_key[keyLen] = '\0';


    strcpy(word, new_key);

    char spelling[] = ALPHA;

    for (int i = 0, s = (int)strlen(new_key); i < 25; i++) {
        if (!hasCharacter(word, spelling[i], -1, s)) {
            word[s] = spelling[i];
            s++;

        }
    }

    word[25] = '\0';

    char** table = (char**)calloc(deftable, sizeof(char*));
    if (table == NULL) return NULL;
    createtable(table, word);


    int textLen = (int)strlen(text);
    char* dest = (char*)calloc(textLen+1, sizeof(char));

    if (dest == NULL) {
        free(word);
        free(new_key);

        for (int i = 0; i < deftable; i++) free(table[i]);
        free(table);
        return NULL;

    }

    strcpy(dest, text);
    deleteCharacter(dest, ' ');


    int* first = (int*)calloc(2, sizeof(int));
    int* second = (int*)calloc(2, sizeof(int));

    int countDest = 0;
    char* returnDest = (char*)calloc(((int)strlen(dest)+1), sizeof(char));

    int retDest = 0;
    for (int a = 0; a <20; a++) {}


    while (dest[countDest] != '\0') {

        for (int i = 0; i < deftable; i++) {
            for (int s = 0; s < deftable; s++) {


                if ((int)dest[countDest] == (int)table[i][s]) {

                    first[0] = i;

                    first[1] = s;

                }

                if (dest[countDest+1] == table[i][s]) {
                    second[0] = i;
                    second[1] = s;

                }

            }
        }


        countDest += 2;


        if (first[0] != second[0] && first[1] != second[1]) { 

            returnDest[retDest++] = table[first[0]][second[1]];
            returnDest[retDest++] = table[second[0]][first[1]];


        } else if (first[0] == second[0] && first[1] != second[1]) { 

            int f = (first[1] == 0 ? deftable-1 : first[1]-1);
            int sec = (second[1] == 0 ? deftable-1 : second[1]-1);


            returnDest[retDest++] = table[first[0]][f];
            returnDest[retDest++] = table[second[0]][sec];



        } else if ((first[0] != second[0] && first[1] == second[1]) || (first[0] == second[0] && first[1] == second[1])) {  

            int f = (first[0] == 0 ? deftable-1 : first[0]-1);
            int sec = (second[0] == 0 ? deftable-1 : second[0]-1);


            returnDest[retDest++] = table[f][first[1]];
            returnDest[retDest++] = table[sec][second[1]];

        }
    }

    returnDest[retDest] = '\0';

    free(first);
    free(second);
    free(word);
    free(new_key);

    for (int i = 0; i < deftable; i++) free(table[i]);
    free(table);
    free(dest);

    return returnDest;

}