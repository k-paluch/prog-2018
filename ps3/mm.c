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
	//unsigned int number;
	scanf("%ld",&number);
	//printf("%d \n",number);
	while((count(number))>1){
	dig= count(number);
	//printf("%d\n",dig);
	char arr[dig];
	int c=0;
	while(dig--){
		arr[dig]=number%10;
		number/=10;
		c++;
	}
	arr[c]='\0';
	int i;
	for(i=0; i<c; i++){
	//printf("%d ",arr[i]);
	}
	//printf("\n");
	number=0;
	for(i=0;i<c;i++){
		number+=arr[i];
	}
	//printf("%d\n",number);
	}
	printf("%ld\n",number);
	//end=clock();
	//cpu_time_used=((double)(end - start));
	//printf("%f\n",cpu_time_used);
	return 0;
}
