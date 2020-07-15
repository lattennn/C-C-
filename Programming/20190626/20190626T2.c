#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int key;
struct node* left;
struct node* right;
}node_t;

int height (node_t*root);
void pathwrite (node_t*,int,int,int*,node_t**,node_t**);

void longestpath(node_t *root){
int i,k,max=0,h;
node_t**vet,**best;

 h=height(root);//h=height(node_t*root); 调用的时候不要传类型！！讲多少次了！！！！
 printf("Height:%d",h);

 vet=(node_t**)malloc(h*sizeof(node_t*));
 best=(node_t**)malloc(h*sizeof(node_t*));

 for(i=0;i<h;i++){
    vet[i]=NULL;
    best[i]=NULL;
 }
    pathwrite(root,h,0,&max,vet,best);
    fprintf(stdout,"\nThe longest path has length:%d\nThe longest path:",max+1);
    for(k=0;k<=max;k++){//best[k]!=NULL;k++){
        fprintf(stdout,"%d ",best[k]->key);
    }
    printf("\n");
    free(vet);
    free(best);
    return;
}


int height(node_t*root) {
int u,v;
if(root==NULL){
    return 0;
}
u=height(root->left);
v=height(root->right);
if(u>v){
    return(u+1);
}
return (v+1);

}


void pathwrite(node_t*root,int h,int level,int*maxlength,node_t**vet,node_t**best) {
int i,flag,k;

if(root==NULL){
    return;
}
if(root->left==NULL&&root->right==NULL){
    vet[level]=root;//***********put last one here cause it should be count into the increasing order sequence
    for(i=flag=0;i<level&&flag==0;i++){
        if(vet[i]->key>=vet[i+1]->key){//WRONG if(vet[i+1]!=NULL&&vet[i]>=vet[i+1]){
            flag=1;
            printf("\nNO\n");
        }
    }
    if(flag==0&&level>(*maxlength)){//update the best solution
        *maxlength=level;
        for(i=k=0;i<=level;i++){ //copy the solution //WRONG for(i=k=0;vet[i]!=NULL;i++){
            best[k]=vet[i];
            k++;
        }
    }
    return;//终端结束 你连return 都不写？？？？？？！！！！
    }
    vet[level]=root;
    pathwrite(root->left,h,level+1,maxlength,vet,best);
    pathwrite(root->right,h,level+1,maxlength,vet,best);
    vet[level]=NULL;
    return;
}

node_t * newNode(int key){
	node_t *n = (node_t*) malloc (sizeof(node_t));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}

int main()  {

	/*
	         6
		7	      7
	10           8    9
	  3                 10
	                  22        */

   	node_t *root;
	root = newNode(6);
	root->left = newNode(7);
	root->left->left = newNode(10);
	root->left->left->right = newNode(3);
	root->right = newNode(7);
	root->right->left = newNode(8);
	root->right->right = newNode(9);
    root->right->right->right = newNode(10);
    root->right->right->right->left = newNode(22);

   longestpath(root);
   return 0;
}

