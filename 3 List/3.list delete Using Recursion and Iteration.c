#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

//�� ɾ �� �� ��� ɾ

/*������ַ����� ����5�ĳ��ȵ��ַ����Ͳ��������list*/
/*��list��ɾ��һ���ַ���*/

typedef struct List
{
    char value[N];
    struct List *next;
}list;

//���ַ���
//��һ�־��ǿ��Ͻ��� ���յ�Ҫɾ����λ�� ���λ���Ҳ��� ����string������ λ���ҵ��� �Ǿ�ɾ��
//�ڶ��ַ��������˵���iteration�͵ݹ�recursion ��Ҫ����flag��ָ�� ��main����֪����û�д������string

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

//����һ���Ӻ���
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
//���������Ӻ���1 �õݹ�
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
//���������Ӻ���2 �õ���
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
    char del1[N],del2[N],del3[N];  /*del[N]=��hello�� is wrong*/
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

//���ȿ�list��û�н�������
   if(head!=NULL){

//����һ ���ҵ�λ�� ��ɾ��
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

//������ ֱ�Ӵ���string ����Ҳ�ô���flag ��ֵstring���״��ڲ�����

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
