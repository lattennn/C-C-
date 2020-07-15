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

//˼·�ܼ� ���������İ취
//�з�������int ��->�������еĵ� �ҵ�����û�ҵ������ͷ���0 �ҵ��� �͵÷��������Ҷ��������ж��ٸ� �� +���Լ� ---> +1
//û�з�������int ��->����һ��*count �������ǿյĵ��Ǿͣ�*count��++ ע��Ҫ������ ����count���Ӿ�ֱ��return ����
//������termination Ҫ�Ǻ�������������void ֱ��return;û����������������� ������������Ϊ�ṹ��ָ�� �Ǿ͵׵�return NULL; ����ֱ��return;

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

    root->left=temp; /*Connect 2 and 4 . rootһ��Ҫָ������һ��ʼ�ĸ� */

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
        return 1;�������Ҫ���ж��ٸ����value ����������취 (����������int) ��Ϊ������;�ҵ�һ�����˳��� ��ʵ���а� ���ֻ����ĳ���� OK*/
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
    return r+l;//�Լ����ǵĻ� ֻ�����Լ��������Ӹ��Լ��Ľ��
}
