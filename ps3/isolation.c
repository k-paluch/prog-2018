#include<stdio.h>
#include <stdlib.h>
#include<math.h>
struct uzol{
	int vetva;
	struct uzol *left;
	struct uzol *right;
};

int compare(struct uzol* help1, struct uzol* help2);
struct uzol* create(int vetva);
void connect(struct uzol* vetva, struct uzol* next);
struct uzol* create (int vetva);
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
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
	int rozdiel=n;
	int compared=0;

	for(int i=0;i<n;i++){
		for(int j =i; j<n; j++){
			if(i==j)continue;
			compared=compare(tree[i],tree[j]);
			if(compared ==0){
				rozdiel--;
				break;
			}
		}
	}

	printf("%d\n",rozdiel);
}

struct uzol* create(int vetva){
	struct uzol* help = (struct uzol*) calloc(1,sizeof(struct uzol));
	help->left=NULL;
	help->right=NULL;
	help->vetva=vetva;
	return help;
}

void connect(struct uzol* vetva, struct uzol* next){
	struct uzol* help= vetva ;
	if(next->vetva>help->vetva){
		if(help->right==NULL){
			help->right=next;
		}
		else{
			connect(help->right,next);
		}
	}
	else if(next->vetva<help->vetva){
		if(help->left==NULL){
			help->left=next;
		}
		else{
			connect(help->left,next);
		}
	}
}

int compare(struct uzol* help1, struct uzol* help2){
	int help=0;
	if((help1!=help2)&&(help1==NULL||help1==NULL)){
		return 1;
	}

	if(help1->left!=NULL){
		if(help2->left!=NULL){
			help=compare(help1->left,help2->left);
			if(help==1)return 1;
		}
		else return 1;
	}

	if(help1->right!=NULL){
		if(help2->right!=NULL){
			help=compare(help1->right,help2->right);
			if(help==1)return 1;
		}
		else return 1;
	}

	return 0;
}
