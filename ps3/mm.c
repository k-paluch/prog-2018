#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

unsigned int count(unsigned int i) {
	unsigned int ret = 1;
	while(i/=10)ret++;
	return ret;
}



/*unsigned int nthdig(unsigned int n, unsigned int k){
	while(n--){
		k/=10;
	}
	return k%10;
}*/

int main(int argc, char *argv[]){
	//clock_t start,end;
	//double cpu_time_used;
	//start = clock();
	if(argc!=2){
		return 1;
	}
	char filename[20];
	strcpy(filename,argv[1]);
	FILE *fp = NULL;
	fp=fopen(filename,"r");
	if(fp==NULL){
		perror("Error opening file\n");
		return 1;
	}
	unsigned int number;
	unsigned int dig;
	//unsigned int number;
	fscanf(fp,"%d",&number);
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
	printf("%d\n",number);
	fclose(fp);
	//end=clock();
	//cpu_time_used=((double)(end - start));
	//printf("%f\n",cpu_time_used);
	return 0;
}
