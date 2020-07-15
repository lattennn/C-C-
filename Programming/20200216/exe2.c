#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} node_t;

int treesame(node_t *t1,node_t *t2);

int subtree(node_t* tree1,node_t* tree2){

    if(tree1==NULL||tree2==NULL)
        return 0;
    if(tree1->key == tree2->key){
        return treesame(tree1,tree2);
    }

    if(subtree(tree1->left,tree2))
       return 1;
    if(subtree(tree1->right,tree2))
       return 1;
    return 0;
}



int treesame(node_t *t1,node_t*t2)
{
    if(t1==NULL&&t2==NULL)
    {
        return 1;
    }
    if(t1==NULL&&t2!=NULL)
    {
        return 0;
    }
    if(t1!=NULL&&t2==NULL)
    {
        return 0;
    }
    if(t1->key!=t2->key)
    {
        return 0;
    }
    if(treesame(t1->left,t2->left)==0)
    {
        return 0;
    }
    if(treesame(t1->right,t2->right)==0)
    {
        return 0;
    }
    return 1;
}
void main()
{
    node_t* tree1 = (node_t*)malloc(sizeof(node_t));
    node_t* tree2 = (node_t*)malloc(sizeof(node_t));
    node_t* temp1 = tree1, *temp2 = tree2;
    temp1->key = 1;
    temp1->left= (node_t*)malloc(sizeof(node_t));
    temp1->right= (node_t*)malloc(sizeof(node_t));
    temp1 = temp1->left;
    temp1->key = 2;
    temp1->right = NULL;
    temp1->left = (node_t*)malloc(sizeof(node_t));
    temp1 = temp1->left;
    temp1->key = 3;
    temp1->right = NULL;
    temp1->left = NULL;
    temp1 = tree1;
    temp1 = tree1->right;
    temp1->key = 4;
    temp1->left = NULL;
    temp1->right = NULL;

    temp2->key = 2;
    temp2->right = NULL;
    temp2->left = (node_t*)malloc(sizeof(node_t));
    temp2 = temp2->left;
    temp2->key = 3;
    temp2->left = NULL;
    temp2->right = NULL;

    printf("tree is same or not:%d\n", subtree(tree1,tree2));
}
