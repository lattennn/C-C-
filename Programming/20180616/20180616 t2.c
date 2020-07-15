#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int key;
    struct node* left;
    struct node* right;
} node_t;

node_t* newNode(int k){
    node_t* n=(node_t*)malloc(1*sizeof(node_t));
    if(n==NULL)
        exit(-1);
    n->key=k;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int count_diameter(node_t *r,int count){ //find the height basic function
    int lm,rm;
    if(r==NULL)
        return 0;
    if(r->left==NULL&&r->right==NULL)
        return count;
    lm=count_diameter(r->left,count+1);
    rm=count_diameter(r->right,count+1);

    if(lm>rm)
        return lm;
    return rm;
}
void rec(node_t* root,int *max){
    int my_len;

    if(root==NULL) return;

    rec(root->left,max);
    rec(root->right,max);
    my_len = count_diameter(root->left,0)+count_diameter(root->right,0)+2;

    if(my_len>=(*max)){
        *max = my_len;
    }
    return;
}
int tree_diameter(node_t* r){
    int max=0;
    rec(r,&max);
    return max;
}
//不可以 int*max,rec(r,max),return (*max);因为一般int* 就是要分配空间给它 它是个int数组了

int main(){
    node_t *root;

    root=newNode(30);
    root->left=newNode(19);
    root->right=newNode(45);


    root->left->right=newNode(21);


    root->right->left=newNode(38);
    root->right->right=newNode(67);


    root->right->left->left=newNode(36);
    root->right->left->left->left=newNode(31);

    root->right->right->left=newNode(63);
    root->right->right->left=newNode(89);

    printf("\n\nThe diameter of this tree is %d!\n\n",tree_diameter(root));
    return 0;
}
