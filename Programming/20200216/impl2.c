#include<stdio.h>
#include<stdlib.h>

typedef struct node{
 int key;
 struct node*left;
 struct node*right;

}node_t;

int check_tree(node_t* root1,node_t* root2);
int subtree(node_t* tree1,node_t* tree2);
node_t * newNode(int key);

void visit(node_t * root);

int main(){
    node_t *root,*temp,*root2;
    int flag=0;

	/*
	         6
		4	      8
	2           7    9
	  3                 1
	                  22        */
	root = newNode(6);
	root->left = newNode(4);
	root->left->left = newNode(2);
	root->left->left->right = newNode(3);
	root->right = newNode(8);
	root->right->left = newNode(7);
	root->right->right = newNode(9);
    root->right->right->right = newNode(1);
    root->right->right->right->left = newNode(22);

    printf("\nTree1:");
    visit(root);


	root2 = newNode(9);
    root2->right = newNode(1);
    root2->right->left = newNode(22);

    printf("\nTree2:");
    visit(root2);

    flag=subtree(root,root2);

    if(flag){
        printf("\nYES!\n");
    }
    else{
        printf("\nNO!\n");
    }

}

int check_tree(node_t* root1, node_t* root2){

    if( (root1==NULL && root2!=NULL ) || ( root1!=NULL && root2==NULL) )
        return 0;

    if(root1==NULL && root2==NULL)
        return 1;

    if(root1->key!=root2->key)
        return 0;
    if(check_tree(root1->left,root2->left)==0)
        return 0;
    if(check_tree(root1->right,root2->right)==0)
        return 0;

    return 1;
}

int subtree(node_t* tree1,node_t* tree2){

    if(tree1==NULL||tree2==NULL)
        return 0;
    if(tree1->key == tree2->key){
        return check_tree(tree1,tree2);
    }

    if(subtree(tree1->left,tree2))
       return 1;
    if(subtree(tree1->right,tree2))
       return 1;
    return 0;
}


node_t * newNode(int key){
	node_t *n = (node_t*) malloc (sizeof(node_t));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void visit(node_t * root)
{
	if(root == NULL)
		return;
	visit(root->left);
	visit(root->right);
	printf("%d ", root->key);
}
