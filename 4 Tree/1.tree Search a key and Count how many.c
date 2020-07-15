#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;

}node_t;

//preorder
void findkey(node_t *root,int v,int *count);

int findkey2(node_t *root,int v);

void printree(node_t *root)
{
    if(root==NULL)
        return;
//pre-order in-order post-order

    printf("%d ",root->key);

    printree(root->left);
    printree(root->right);


    return;
}

//思路很简单 两种最好想的办法
//有返回类型int 那->我找所有的点 找到底是没找到反正就返回0 找到了 就得返回我左右儿子树里有多少个 再 +我自己 ---> +1
//没有返回类型int 那->就用一个*count 反正不是空的点那就（*count）++ 注意要打括号 空树count不加就直接return 完事
//当到了termination 要是函数返回类型是void 直接return;没有其他东西。但如果 函数返回类型为结构体指针 那就底得return NULL; 不能直接return;

int main()
{
    int k,flag,c;
    node_t *root,*temp;

    //0
    root=(node_t*)malloc(sizeof(node_t));
    root->key=2;     /*create the first node only one with the value 2*/
    root->left=NULL;
    root->right=NULL;

    //1
    temp=(node_t*)malloc(sizeof(node_t));
    temp->key=4;     /*create the second node with the value 4*/
    temp->left=NULL;
    temp->right=NULL;

    root->left=temp; /*Connect 2 and 4 . root一定要指向我们一开始的根 */

    //2
    temp=(node_t*)malloc(sizeof(node_t));
    temp->key=6;
    temp->left=NULL;
    temp->right=NULL;

    root->right=temp;

    //3
    temp=(node_t*)malloc(sizeof(node_t));
    temp->key=6;
    temp->left=NULL;
    temp->right=NULL;

    root->left->left=temp;

    //4
    temp=(node_t*)malloc(sizeof(node_t));
    temp->key=8;
    temp->left=NULL;
    temp->right=NULL;

    root->left->right=temp;

    //5
    temp=(node_t*)malloc(sizeof(node_t));
    temp->key=0;
    temp->left=NULL;
    temp->right=NULL;

    root->right->right=temp;

    printree(root);

    printf("\n\ninsert the number:");
    scanf("%d",&k);
    c=0;
    findkey(root,k,&c);
    printf("\n\nUsing the first function (with pointer *count)->exist,and it appears %d time(s)\n",c);

    flag=0;
    flag = findkey2(root,k);
    printf("\nUsing the second function,the key %d appears %d time(s)\n\n\n",k,flag);

    return 0;
}


void findkey(node_t *root,int v,int *count)
{
    //int m,n;
    if(root==NULL)
        return;
    if(root->key==v){
        (*count)++;
    }

    findkey(root->left,v,count);
    /*if(m==1)
        return 1;这里如果要找有多少个这个value 不能用这个办法 (返回类型是int) 因为这样中途找到一个就退出了 其实还有啊 如果只是找某个数 OK*/
    findkey(root->right,v,count);
}

int findkey2(node_t *root,int v){
    int l,r;

    if(root == NULL)
        return 0;

    l=findkey2(root->left,v);
    r=findkey2(root->right,v);

    if(root->key==v)
        return r+l+1;
    return r+l;//自己不是的话 只返回自己的左右子给自己的结果
}
