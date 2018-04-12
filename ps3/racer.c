#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main(void){
	int n,t;
	scanf("%d %d",&n,&t);
	int s[n];
	int v[n];
	int x=0;
	for(int i =0; i<n; i++){
		scanf("%d %d",&s[i],&v[i]);
	}
	int sum=0;
	for(int i =0; i<n;i++){
		sum = s[i]/(x+v[i]);
	}
	//if(sum == t)break;
	return 0;
}
