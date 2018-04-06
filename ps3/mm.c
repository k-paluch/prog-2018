#include<stdio.h>
#include<inttypes.h>
uintmax_t digit(uintmax_t n);
int main(){
	char c;
	uintmax_t n =0;
	c= getc(stdin);
	while(c!='\n'){
	n += (c-'0');
	c = getc(stdin);
	}
	n = digit(n);
	printf("%ju\n",n);
}

uintmax_t digit(uintmax_t n){
	uintmax_t temp=0;
	do{
		while(n){
			temp += (n%10);
			n/=10;
		}
		n = temp;
		temp =0;
	}while(n/10!=0);
	return n;
}
