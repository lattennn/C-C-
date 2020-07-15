#include <stdio.h>
#include <stdlib.h>


typedef struct n{
    int val;
    struct n *right;
    struct n *left;
}node_t;

int distance(node_t *root,int key1,int key2){

    if(root==NULL)
        return 0;

    if((root->val < key1 && root->val > key2) || (root->val > key1 && root->val < key2) ){
        if(path(root,key1,0)&&path(root,key2,0)){
            return path(root,key1,0)+path(root,key2,0);
        }
        else
            return 0;
    }
    else if(root->val < key1 && root->val < key2){//key1 and key2 both are in the right subtree
        return distance(root->right,key1,key2);
    }
    else if(root->val > key1 && root->val > key2){//key1 and key2 both are in the left subtree
        return distance(root->left,key1,key2);
    }

    else if(key1 == root->val)                   //key1 is the root of key2
        return path(root,key2,0);
    else                                        //key2 is the root of key1
        return path(root,key1,0);
}
/*wrong example
int path(node_t *root,int key){
    int nr,nl;
    if(root==NULL)
        return 0;
    if(key==root->left->val||key==root->right->val)
        return 1;

    else if(key<root->val){
        return path(root->left,key);
    }
    else
        nr = path(root->right,key);

    if((nr==0&&nl>0)||(nr>0&&nl==0))
        return nr+nl+1;
    else
        return nr+nl;
}*/

int path(node_t *root,int key,int count){

    if(root==NULL)
        return 0;

    if(root->val==key)
        return count;

    count++;
    if(root->val>key)// key is in the left subtree
        return path(root->left,key,count);
    else
        return path(root->right,key,count);
}

node_t * newNode(int key){
	node_t *n = (node_t*) malloc (sizeof(node_t));
	n->val = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}

int main()
{
	/*
	         6
		4	      8
	2           7    9
	  3                 22
                     10       */

	node_t *root;
	int dist;

	root = newNode(6);
	root->left = newNode(4);
	root->left->left = newNode(2);
	root->left->left->right = newNode(3);
	root->right = newNode(8);
	root->right->left = newNode(7);
	root->right->right = newNode(9);
    root->right->right->right = newNode(22);
    root->right->right->right->left = newNode(10);

    dist = distance(root,8,10);
    printf("\nThe distance is %d\n",dist);
	return 0;
}
