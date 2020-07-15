#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define NEW 1
#define USED 2
//�� ɾ �� �� ��� ��(����)

/*�Ҽ����Ҵ�����˵��³�ǰ�� ��һ�������˵��³�*/

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
    minc = rFindC(head->next);/*��Ҫע�⣡������&&��Ӧ��Ҫ�Ӹ�����*/
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

void printlist(list *h) //���������� ȥ��listβ�� ΪNULL�ٷ��ؿ�ʼ��ӡ �� FIFO ��Ϊ������ʱ�� һ���������ʱ �������������listβ��
{                    //�����Ϳ��԰������������˳���ӡ���� ����insert��list�Ǹ�pos�ĺ��� �Ǵ�ӡ��������posǰ��
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

    /*����Ҫ��current=(list*)malloc(sizeof(List));
    //��ֻ��һ��ָ�� ����Ҫ��� ֻ�Ǽ�ס����˵��³���λ��
    //��������λ�õ�ָ�붼Ҫ����ռ��*/

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

    //���ﲻҪ���ǼӸ�malloc ��ΪҪ�洢�µ�car��ȥlist
    insertin=(list*)malloc(sizeof(list));
    if(insertin==NULL){
        printf("Error Allocation!\n");
        exit(-1);
    }
    scanf("%d%d%s",&insertin->price,&insertin->grade,insertin->brand);

    insert(head,current,insertin); //������˵��³�ǰ�����
    printf("After inserting the newest car before the cheapest car by iteration,the list becomes:\n");
    printlist(head);
    return 0;
}

/*OKAY*/
