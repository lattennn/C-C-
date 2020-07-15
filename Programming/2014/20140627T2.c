#include <stdio.h>
#include <stdlib.h>

//OKAY

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}node_t;

void listInsert (node_t **left, node_t **right, int key, int leftRight);
void listDisplay (node_t *left, node_t *right, int leftRight);
node_t *newNode(int v);

int main()
{
    node_t *current,*head;
    int i;
    head=NULL;
    for(i=0;i<10;i++){

        current = newNode(i+1);
        current->right = head;
        if(head!=NULL)
            head->left=current;
        head = current;
    }
    for(current=head;current->right!=NULL;current=current->right);

    printf("The oringinal numerical series is 1 2 3 4 5 6 7 8 9 10\n");

    printf("\n\nPrint it from right:\n");
    listDisplay(head,current,0);//from left 10 9 8 7 6 5 4 3 2 1

    printf("\n\nPrint it from left:\n");
    listDisplay(head,current,1);//from right 1 2 3 4 5 6 7 8 9 10

    printf("\n\nWhen inserting a wrong parameter for 'leftWright':\n");
    listDisplay(head,current,2);//error

    printf("\n\nInsert 0 from left then");
    listInsert(&head,&current,0,0);//from left insert
  //  listDisplay(head->left,current->right,0);//0 10 9 8 7 ...
    printf("print it from right:\n");
    listDisplay(head,current,0);//0 10 9 8 7 6 5 4 3 2 1..

    printf("\n\nInsert 0 from right then");
    listInsert(&head,&current,0,1);//from right insert
   // listDisplay(head->left,current->right,1);//0 1 2 3 4 ...
    printf(" print it from right:\n");
    listDisplay(head,current,1);//0 1 2 3 4 ...9 10 0

    printf("\n\n");
    return 0;
}

void listInsert (node_t **left, node_t **right, int key, int leftRight){
    node_t *l,*r,*current;

    l=*left;
    r=*right;
    current = newNode(key);

    switch(leftRight){
    case 0:
        current->left = NULL;//l->left;//(*left)->left
        current->right = l;//(*left);
        l->left = current;
        (*left)=current;//necessary
        break;
    case 1:
        current->right = NULL;//r->right;
        current->left = r;
        r->right = current;
        (*right)=current;
        break;
    default:
        printf("\nError argument!Please insert another new parameter for 'leftRight' \n\n");
        break;
    }
}


void listDisplay (node_t *left, node_t *right, int leftRight){
    node_t *current;
    printf("\n");

    switch(leftRight){
    case 0:
        for(current=left;current!=NULL;current=current->right){
            printf(" %d ",current->val);
        }
        break;
    case 1:
        for(current=right;current!=NULL;current=current->left){
            printf(" %d ",current->val);
        }
        break;
    default:
        printf("Error Parameter!Please input another 'leftRight'\n\n");
        break;
    }

}

node_t *newNode(int v){//allocation function
    node_t *newone;
    newone = (node_t*)malloc(sizeof(node_t));
    if(newone==NULL){
        printf("Error Allocation!\n");
        exit(-1);
    }
    newone->val = v;
    newone->right = NULL;
    newone->left = NULL;

    return newone;
}
