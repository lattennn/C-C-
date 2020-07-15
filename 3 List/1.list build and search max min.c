#include <stdio.h>
#include <stdlib.h>

//�� ɾ �� �� ��� ����+��+��

typedef struct list
{
    int key;
    struct list *next;
}List;

void Findm(List *headd,int *max,int *min)
{
    List *c;
    //*max=headd->key;//main�����Ѿ�������ʼֵ�� �������ظ�дһ��
    //*min=headd->key;
    for(c=headd;c!=NULL;c=c->next){
        if( *max < c->key)
            *max = c->key;//c.key
        if(*min > c->key)
          *min = c->key;
    }
    return;
}
/*recursively*/
void FindM(List *headd,int* max,int* min)
{
    if(headd==NULL)
        return;
    //FindM(headd->next,max,min);
//    FindM(headd->next,&max,&min);  /*ע�Ⱑ������ش��������max��min�Ѿ�address �� �Ѿ��Ǹ�ָ�� ��Ҫ&*/
    if(headd->key > *max)
        *max=headd->key;
    if(headd->key<*min)
        *min=headd->key;
    FindM(headd->next,max,min);
    return;
}
int main()
{
    int maxx,minn,n;
    List *current;
    List *head;

    head=NULL;//Initialization ��ʼ������Ҫ��Ҫ������
    printf("input!\n");
    scanf("%d",&n);
    //input numbers and insert new structure into the list in LIFO way and when you input a negative number, it stops.
    while(n>0){
        current=(List*)malloc(1*sizeof(List));
        current->key=n;
        current->next=head;//LIFO
        head=current;/*head�����ǿյ� ���� �� �Ѿ���next��ס�� ��ʱ current����head �ʹ���head�Ӻ����Ƶ�ǰ�� Ҳ���ǵ������currentlist�ͱ�head��ס������*/
        scanf("%d",&n);
    }
    printf("\n");


    for(current = head;current!=NULL;current=current->next){
        printf("%d ",current->key);
    }

    if(head!=NULL){
    maxx=head->key;
    minn=head->key;
    FindM(head,&maxx,&minn);

    printf("\n\nThe max is %d and the min is %d / searched by the recursion way",maxx,minn);
    Findm(head,&maxx,&minn);
    printf("\n\nThe max is %d and the min is %d / searched by the iteration way\n\n",maxx,minn);
    }
    return 0;
}
