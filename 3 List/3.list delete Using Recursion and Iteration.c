#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

//增 删 查 改 里的 删

/*输入的字符串里 超过5的长度的字符串就不再输入进list*/
/*从list里删掉一个字符串*/

typedef struct List
{
    char value[N];
    struct List *next;
}list;

//两种方法
//第一种就是课上讲的 先照道要删掉的位置 如果位置找不到 代表string不存在 位置找到了 那就删除
//第二种方法包括了迭代iteration和递归recursion 需要传入flag的指针 让main函数知道有没有存在这个string

//when return type is void->return;
//when return type is structure pointer->return NULL;
list* FindPos(list *h,char *p) //or char p[]
{
    list *m;
    if(h==NULL)
        return NULL;
    m=FindPos(h->next,p);
    if(strcmp(h->value,p)==0){
        return h;
    }
    return m;
}

//方法一的子函数
list* rdelist(list*h,list *pos)
{
    list *c;
    if(h==NULL)
        return NULL;

    h->next = rdelist(h->next,pos);

    if(h==pos){
        c=h->next;
        free(h);
        return c;
    }
    return h;
}
//方法二的子函数1 用递归
list* recurdelete(list* h,char *p,int *flag){
    list* temp;
    if(h==NULL)
        return NULL;
    h->next = recurdelete(h->next,p,flag);
    if(strcmp(h->value,p)==0){
        *flag=1;
        temp = h->next;
        free(h);
        return temp;
    }
    return h;
}
//方法二的子函数2 用迭代
list* iterativedelete(list*h,char *p,int *flag){
    list* current,*prev;

    if(h==NULL)
        return NULL;
    if(strcmp(h->value,p)==0){
        *flag = 1;
        current=h;
        h = h->next;
        free(current);
        return h;
    }

    prev=h;
    current=h->next;
    while(current!=NULL){
        if(strcmp(current->value,p)==0){
            *flag = 1;
            printf("\nhere\n");
            prev->next=current->next;
            free(current);
            current=prev->next;
        }
        else{
            prev=current;
            current=current->next;
        }
    }
    return h;
}

void printlist(list *h)
{
    if(h==NULL){
        return;
    }
    printf("->%s",h->value);
    printlist(h->next);
}

int main()
{
    int l,flag;
    list *current,*head;
    char del1[N],del2[N],del3[N];  /*del[N]=‘hello’ is wrong*/
    char n[N];

    head=NULL;//initialization
    printf("insert some words with length 5 and end up with a word with the length that's different from 5!\n\n");
    gets(n);
    l=strlen(n);
    while(l==5){
        current=(list*)malloc(sizeof(list));
        if(current!=NULL){
        strcpy(current->value,n);
        current->next=head;
        head=current;
        }
        scanf("%s",n);
        l=strlen(n);
    }

    printf("\ninsert the first string you want to delete: ");
    scanf("%s",del1);

//首先看list有没有建立起来
   if(head!=NULL){

//方法一 先找到位置 再删除
    printf("\nThe first method:\n");
    current=FindPos(head,del1);
    if(current!=NULL){
        printf("succeeded to find the position\n");

        head = rdelist(head,current);
        printf("succeeded to delete %s in the %d position",del1,current);
        printf("\n");
        if(head!=NULL)
            printlist(head);
        else
            printf("Empty list after deleted\n");
    }

    else
        printf("Not exist such string\n");

//方法二 直接传入string 但是也得传入flag 得值string到底存在不存在

    printf("\n\nThe second method:\n");
    printf("insert the second string you want to delete: ");
    scanf("%s",del2);

    flag = 0;
    head = recurdelete(head,del2,&flag);

    if(flag!=0)
        printf("Succeeded to recursively delete %s in the list\n",del2);
    if(flag==0&&head!=NULL)
        printf("Not exist the string %s(in Recursion)\n",del2);

    if(head!=NULL)
        printlist(head);
    else
        printf("Empty list\n");
    printf("\n\n");


    printf("insert the third string you want to delete: ");
    scanf("%s",del3);
    flag=0;
    head = iterativedelete(head,del3,&flag);
    if(flag!=0)
        printf("Succeeded to iteratively delete %s in the list\n",del3);
    if(flag==0&&head!=NULL)
        printf("Not exist the string %s(in Iteration)\n",del3);

    if(head!=NULL)
        printlist(head);
    else
        printf("Empty list\n");
    printf("\n\n");
   }

   else
    printf("\nEmpty list(Originally)\n");

    return 0;
}
