#include <stdlib.h>
#include <stdio.h>

#define N 3

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
}node_t;

void findnode(node_t *root,int *count)
{
    if(root==NULL)
        return;

    if(root!=NULL)
        (*count)++;

    findnode(root->left,count);
    findnode(root->right,count);
}

//preorder
void printree(node_t *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->key);
    printree(root->left);
    printree(root->right);
    return;
}

void changekey(node_t root){
    root.key=11;
}

void changekey2(node_t* n){
    n->key=11;
}


node_t hey(int key){
    node_t anode;
    anode.key = key;
    anode.left=NULL;
    anode.right=NULL;
    return anode;
 /*
    anode.left =(node_t*)malloc(1*sizeof(node_t));
    anode.left->key=111;
    anode.left->left=NULL;
    anode.left->right = NULL;
    anode.right = (node_t*)malloc(1*sizeof(node_t));
    anode.right->key = 222;
    anode.right->left=NULL;
    anode.right->right = NULL;
    return anode;*/
}
int main ()
{
    FILE *fw;//prototype a pointer of a file
    int count=0;
    node_t what;//Single structure, not a structure pointer
    node_t *root,*temp; //不要忘记了 用个temp来新建 暂时存放点啊啊！
    fw=fopen("out.txt","w");//create and write in a file named 'out.txt'
    //1
    root=(node_t*)malloc(1*sizeof(node_t));
    root->key=1;
    root->left=NULL;
    root->right=NULL;
    //2
    temp=(node_t*)malloc(1*sizeof(node_t));
    temp->key=2;
    temp->left=NULL;
    temp->right=NULL;
    root->left=temp;
    //3
    temp=(node_t*)malloc(1*sizeof(node_t));
    temp->key=3;
    temp->left=NULL;
    temp->right=NULL;
    root->right=temp;
    //4
    temp=(node_t*)malloc(1*sizeof(node_t));
    temp->key=4;
    temp->left=NULL;
    temp->right=NULL;
    root->left->left=temp;
    //5
    temp=(node_t*)malloc(1*sizeof(node_t));
    temp->key=5;
    temp->left=NULL;
    temp->right=NULL;
    root->left->right=temp;
    //6
    temp=(node_t*)malloc(1*sizeof(node_t));
    temp->key=6;
    temp->left=NULL;
    temp->right=NULL;
    root->right->right=temp;

    findnode(root,&count);
    fprintf(fw,"It has %d nodes\n\n",count);
    fclose(fw);

    printree(root);
    what = hey(10);
    printf("\n\n\ncrazy value is %d\n",what.key);//field

    root->right->right->right = &what;
    printf("\nThe tree after insert the key 10\n");
    printree(root);

    changekey(what);
    printf("\ncrazy value after change1 is %d\n(No change actually)\n",what.key);

    changekey2(&what);
    printf("\ncrazy value after change2 is %d\n(changed if input the pointer)\n",what.key);

    return 0;
}

