#include<stdio.h>
#include<inttypes.h>
int main(){
	char c;
	uintmax_t n =0;
	c= getc(stdin);
	while(c!='\n'){
	n += (c-'0');
	c = getc(stdin);
	}
	uintmax_t temp;
	do{
		while(n!=0){
			temp+=(n%10);
			n/=10;
		}
		n=temp;
		temp=0;
	}while(n/10!=0);
	printf("%ju\n",n);
}
