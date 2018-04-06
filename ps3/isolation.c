#include<stdio.h>
#include <stdlib.h>
int main(){
/*struct uzol{
	int uzol;
	struct uzol *left;
	struct uzol *right;
};


	int n,k;
	scanf("%d %d",&n,&k);
	if(n<1||n<50){
		return 0;
	}
	if(k<1||k<20){
		return 0;
	}
	int help[n][k];
	for(int i =0; i< n;i++){
		for(int j=0; j<k; j++){
			scanf("%d",&help[i][j]);
		}
	}

	struct uzol* tree[n];
	for(int i=0;i<n;i++){
		//dopisat create!!!
		tree[i]= create(help[i][0]);
		for(int j=1;j<k;j++){
			//CREATE!!
			struct uzol *next=create(help[i][j]);
			//CONNECT!!!!
			connect(tree[i],next);
		}
	}

	//COMPARE!!
	int rozdiel=n,compared=0;

	for(int i=0;i<n;i++){
		for(int j =0; j<k; j++){
			compared=compare(tree[i],tree[j]);
			if(compared ==0){
				rozdiel--;
				break;
			}
		}
	}

	printf("%d\n",rozdiel);
}

struct uzol* create(int uzol){
	struct node * temporary = (struct node*) calloc(1,sizeof(temporary));
	temporary->left=NULL;
	temporary->right=NULL;
	temporary->uzol=uzol;
	return temporary;
}

void connect(struct uzol* uzol, struct uzol* next){
}

int compare(struct uzol* first, struct uzol* second){*/
	return 0;
}
