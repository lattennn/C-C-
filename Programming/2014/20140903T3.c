#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
//Okay

typedef struct node{
    char sur[N];
    char name[N];
    int mark;
    struct node *left;//children
    struct node *right;//siblings
}node_t;

node_t* newNode(char*,char*,int);
void print(node_t* root);

int main()
{
    node_t *root;

    root = newNode("a","a",23);
    root->left= newNode("b","b",22);
    root->left->right= newNode("c","c",22);
    root->left->right->right= newNode("d","d",22);

    root->left->left = newNode("e","e",24);
    root->left->left->left = newNode("h","h",18);
    root->left->left->left->right = newNode("i","i",10);
    root->left->left->left->right->right = newNode("j","j",19);


    root->left->right->right->left = newNode("f","f",29);
    root->left->right->right->left->right = newNode("g","g",27);

    print(root);

    return 0;
}

node_t* newNode(char* surn,char* namee,int m){
    node_t *n;

    n=(node_t*)malloc(sizeof(node_t));
    if(n==NULL){
        printf("Error Allocation!\n");
        exit(-1);
    }
    n->mark = m;
    strcpy(n->name,namee);
    strcpy(n->sur,surn);
    n->left = NULL;
    n->right =NULL;
    return n;
}


void print(node_t* root){
    if(root==NULL)
        return;
    print(root->left);
    printf("\n\nStudent '%s %s' has mark:%d",root->sur,root->name,root->mark);
    print(root->right);
}

