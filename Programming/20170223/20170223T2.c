#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int key;
  int num;
  struct node *parent;
  struct node *child;
  struct node *right;
}node_t;

void proceTree(node_t*);
void rec(node_t*,node_t*);
node_t *newNode(int);
void printree(node_t *root);
void printree1(node_t*root);
int main()
{

    node_t *root;
    int c=0;

    root=newNode(1);
    root->child=newNode(2);
    root->child->right=newNode(3);
    root->child->right->right=newNode(4);
    root->child->right->right->right=newNode(6);
    //root->child->right->right->child->right=newNode(7);´í
    root->child->right->right->child=newNode(7);
    root->child->right->right->child->right=newNode(77);
    /*   1
        2->3->4->6
      5      7->77
    8->9->10
*/
    root->child->child=newNode(5);

    root->child->child->child=newNode(8);
    root->child->child->child->right=newNode(9);
    root->child->child->child->right->right=newNode(10);

    proceTree(root);
 //   printf("%d\n",root->num);
 //   printf("%d",root->child->num);

   // printree(root);

    printree(root);
    printree1(root);
    printf("\n\n\n\nEvery thing is ok\n\n\n\n");
    return 0;
}



void printree1(node_t *root){
    if(root==NULL)
        return;
    printf("%d->",root->key);
    printree1(root->right);
    printf("\n");
    printree1(root->child);
}

void printree(node_t *root){
    if(root==NULL)
        return;

    printf("key :%d,",root->key);
    if(root->num==0)
        printf("No child!");
    else
        printf("has %d children,",root->num);

    if(root->parent!=NULL)
        printf("It's parent is key %d.",root->parent->key);
    else
        printf("No parent!");
    printf("\n");
    printree(root->right);
    printf("\n");
    printree(root->child);
    return;
}

void proceTree(node_t* root){

   if(root==NULL) return;

   root->parent=NULL;
   rec(root,root->child);
}

void rec(node_t *p,node_t *c){

    if(p==NULL) return;
    if(c==NULL){
       p->num=0;
       return;
     }
 //printf("%d,%d\n",p->key,c->key);
    node_t *tep=c;
    int count=0;
    while(tep!=NULL){
       count++;
      //printf("count:%d\n",count);
       tep->parent=p;
       rec(tep,tep->child);
       tep=tep->right;
    }
    p->num=count;
    return;
}

node_t* newNode(int key1){
    node_t *n;
    n=(node_t*)malloc(1*sizeof(node_t));
    if(n==NULL){
        fprintf(stderr,"Allocation Error!\n");
        exit(-1);
    }

    n->key=key1;
    n->num=0;
    n->child=NULL;
    n->right=NULL;
    n->parent=NULL;
    return n;
}


