#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define NEW 1
#define USED 2
//增 删 查 改 里的 增(插入)

/*我假设我从最便宜的新车前面 加一个更便宜的新车*/

//->car1->car2->car3->car4->car5
//for example if the car3 is the cheapeast new car ,we have to insert the newcar here
//->car1->car2->car3->newcar->car4->car5

typedef struct cars
{
    int price;
    int grade;
    char brand[N];//char *brand;
    struct cars *next;
}list;

//iteratively find the position
list* FindC(list *h)
{
    list *current;
    list *c;

    c=NULL;//c remember the cheapest car pointer
    for( current=h ; current!=NULL; current=current->next){
        if(current->grade==NEW &&(c==NULL ||current->price < c->price )){
            c = current;
        }
    }
    return c;
}
//recursively find the position
list* rFindC(list* head){
    list *minc;
    if(head==NULL){
        return NULL;
    }
    minc = rFindC(head->next);/*你要注意！！这里&&后应该要加个（）*/
    if(head->grade ==NEW &&(minc==NULL || minc->price>head->price)){
        minc = head;
    }
    return minc;
}

void insert(list *h,list *pos,list *in)//iteration
{
    list *temp;
    if(h==NULL)
        return;
    for(temp=h;temp!=NULL;temp=temp->next){
        if(temp==pos){
            in->next=temp->next;
            temp->next=in;
            return;
        }
    }
    return;
}

void insertR(list *h,list *pos,list *in){
    list* current;

    if(h==NULL){
        return;
    }
    if(h==pos){
        in->next=h->next;
        h->next=in;
        return;
    }
    insertR(h->next,pos,in);
    return;
}

void printlist(list *h) //这里这样子 去到list尾端 为NULL再返回开始打印 是 FIFO 因为进来的时候 一个个输进来时 是最先输入的在list尾端
{                    //这样就可以按照我们输入的顺序打印出来 并且insert在list那个pos的后面 那打印出来就在pos前面
    if(h==NULL){
        return;
    }
    printlist(h->next);
    printf("%d %d %s\n",h->price,h->grade,h->brand);
}

int main()
{
    int p,g,i;
    char b[N];
    list *current,*head,*insertin;
    head=NULL;
    printf("input the information of some cars with the price ,grade(2 used or 1 new) and the brand\n");

    i=0;

    while(i<3){

        scanf("%d%d%s",&p,&g,b);
        current=(list*)malloc(sizeof(list));
        //if(current!=NULL).....
        current->price=p;
        current->grade=g;
        strcpy(current->brand,b);

        current->next=head;
        head=current;
        i++;
    }

    /*不需要把current=(list*)malloc(sizeof(List));
    //它只是一个指针 不需要存放 只是记住最便宜的新车的位置
    //不是所有位置的指针都要分配空间的*/

    current=FindC(head);//Find the position
    if(current!=NULL)
        printf("\nThe cheapest new car found by iteration is %s with the price %d\n",current->brand,current->price);
    else
        printf("No new car!\n");

    current=rFindC(head);
    if(current!=NULL)
        printf("The cheapest new car found by recursion is %s with the price %d \n",current->brand,current->price);
    else
        printf("No new car!\n");

    printf("Insert the new car information:\n");

    //这里不要忘记加个malloc 因为要存储新的car进去list
    insertin=(list*)malloc(sizeof(list));
    if(insertin==NULL){
        printf("Error Allocation!\n");
        exit(-1);
    }
    scanf("%d%d%s",&insertin->price,&insertin->grade,insertin->brand);

    insert(head,current,insertin); //在最便宜的新车前面插入
    printf("After inserting the newest car before the cheapest car by iteration,the list becomes:\n");
    printlist(head);
    return 0;
}

/*OKAY*/
