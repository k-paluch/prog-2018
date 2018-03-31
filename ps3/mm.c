#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

unsigned long int count(unsigned long int i) {
	unsigned long int ret = 1;
	while(i/=10)ret++;
	return ret;
}



/*unsigned int nthdig(unsigned int n, unsigned int k){
	while(n--){
		k/=10;
	}
	return k%10;
}*/

int main(){
	unsigned long int number;
	unsigned long int dig;
	scanf("%ld",&number);
	while((count(number))>1){
	dig= count(number);
	char arr[dig];
	int c=0;
	while(dig--){
		arr[dig]=number%10;
		number/=10;
		c++;
	}
	arr[c]='\0';
	int i;
	number=0;
	for(i=0;i<c;i++){
		number+=arr[i];
	}
	}
	printf("%ld\n",number);
	return 0;
}
