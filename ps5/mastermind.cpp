#include<Arduino.h>
//#include<stdio.h>
#include<math.h>
#include"mastermind.h"
#include"lcd_wrapper.h"
#include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcdd(0x27,16,2);
 
char* generate_code(bool repeat, int length){
  char* secret = (char*)malloc((length+1)*sizeof(char));
  secret[0] = random(0, 10);
  secret[1] =  random(0, 10);  
  secret[2] =  random(0, 10);
  secret[3] =  random(0, 10);
  if(repeat && (secret[0] == secret[1])){
    do{
      secret[1] =  random(0, 10);
    }while(secret[0] == secret[1]);
  }
  if(repeat &&(secret[0] == secret[2] || secret[1] == secret[2])){
    do{
      secret[1] =  random(0, 10);
    }while(secret[0] == secret[2] || secret[1] == secret[2]);
  }
  if(repeat &&(secret[0] == secret[3] || secret[1] == secret[3] || secret[2] == secret[3])){
    do{
      secret[1] =  random(0, 10);
    }while(secret[0] == secret[3] || secret[1] == secret[3] || secret[2] == secret[3]);
  }
  secret[length]='\0';
	return secret;
}

void play_game(char* secret){
  lcdd.backlight();
int i,isWon=0;
int peg_a=0,peg_b=0;
  turn_off_leds();
  int attemp=0;
  
  int in1, in2, in3, in4,s1,s2,s3,s4,s;
for(i=0;i<10; i++){
     int i=0;
lcdd.clear();
char n[] = {"Attemp:"};
  for (i = 0; i < strlen(n); i++){
    lcdd.setCursor(i, 0);
    lcdd.print(n[i]);
  }  
     
 lcdd.setCursor(i+1, 0);
lcdd.print((int)attemp+1);
  delay(2000);
  in1=in2=in3=in4=0;
  int pole[] = {0,0,0,0};
  while(digitalRead(A0)!=HIGH){
   if(digitalRead(5) == HIGH){
      pole[0] = (int)pole[0] + 1;
      if(pole[0] > 9){
        pole[0] = 0;
      }
   }
    if(digitalRead(4) == HIGH){
     pole[1] = (int)pole[1] + 1;
      if(pole[1] > 9){
        pole[1] = 0;
      }
   }
   if(digitalRead(3) == HIGH){
      pole[2] = (int)pole[2] + 1;
      if(pole[2] > 9){
        pole[2] = 0;
      }
   }
   if(digitalRead(2) == HIGH){
      pole[3] = (int)pole[3] + 1;
      if(pole[3] > 9){
        pole[3] = 0;
      }
   }
  // lcdd.clear();
  // for (int i = 0; i < 4; i++) {
   // lcdd.print((int)pole[i]);
  //}
lcdd.clear();
   for (int i = 0; i < 4; i++) {
    lcdd.print((int)pole[i]);
  }
  delay(100);
   if(digitalRead(A0)==HIGH){
     //char n[] = {"blaaa"};
   // for (int i = 0; i < strlen(n); i++) {
  //  lcdd.setCursor(i, 0);
   // lcdd.print(n[i]);
 // }      

    attemp++;
    break;
   }
   }
   for(int f=0; f<4; f++){
    if(secret[f]==pole[f]){
      peg_a++;
    }  
    else{
        for(int a=f; a=0;a--){
          if(secret[a]==pole[f]){
            peg_b++;
          }
        }
        
      }
      if(peg_a==4){
        isWon=1;
      }
      }
    
  
   render_leds(peg_a,peg_b);
   if(isWon){
    break;
   }
}
if(!isWon){
    lcdd.clear();
        char n[] = {"YOU LOOSE"};
    for (int i = 0; i < strlen(n); i++) {
    lcdd.setCursor(i, 0);
    lcdd.print(n[i]);
  }
  lcdd.setCursor(0, 1);
    char e[] = {"SECRET WAS "};
    for (int i = 0; i < strlen(n); i++) {
    lcdd.setCursor(i, 0);
    lcdd.print(e[i]);
  }
  for (int i = 0; i < strlen(n); i++) {
    lcdd.setCursor(i, 0);
    lcdd.print(secret[i]);
  }
  delay(2000);
  }
  else if(isWon){
    lcdd.clear();
        char n[] = {"YOU WON!"};
         for (int i = 0; i < strlen(n); i++) {
      lcdd.setCursor(i, 0);
      lcdd.print(n[i]);
  }  
  delay(2000);
  }
  
}

void render_leds(const int peg_a, const int peg_b){
   for(int i=0; i<peg_a+peg_b; i++){
     if(i<=peg_a) {
      digitalWrite((7+(i*2)),HIGH);
    }
     else{
      digitalWrite((6+(i*2)),HIGH);
    }
   }

}

void turn_off_leds(){
 for(int i=6; i<=13; i++){
    digitalWrite(i,LOW);
  }

}

void get_score(const char* secret, const char* guess, int* peg_a, int* peg_b){
	  *peg_a=0;
    *peg_b=0;
    int l=strlen(secret),i,j;
    for(i=0;i<l;i++){
        if(secret[i]==guess[i])
             *peg_a= *peg_a+1;
        for(j=0;j<l;j++){
                if(i!=j && secret[i]==guess[j])
                    *peg_b= *peg_b+1;            
             }
    }
}
