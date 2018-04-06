#include<stdio.h>
int main(){
	char c;
	int n =0;
	c= getc(stdin);
	while(c!='\n'){
	n += (c-'0');
	c = getc(stdin);
	}
	int sum=0,temp;
	while(n!=0){
		temp = n%10;
		sum= sum+temp;
		n = n/10;
	}
	printf("%d\n",sum);
}

