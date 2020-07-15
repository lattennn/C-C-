#include <stdio.h>
#include <stdlib.h>

//增 删 查 改 里的 建立+查+改

typedef struct list
{
    int key;
    struct list *next;
}List;

void Findm(List *headd,int *max,int *min)
{
    List *c;
    //*max=headd->key;//main函数已经给它初始值了 不用再重复写一遍
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
//    FindM(headd->next,&max,&min);  /*注意啊！大错特错啊！这里的max和min已经address 了 已经是个指针 不要&*/
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

    head=NULL;//Initialization 初始化！重要重要！！！
    printf("input!\n");
    scanf("%d",&n);
    //input numbers and insert new structure into the list in LIFO way and when you input a negative number, it stops.
    while(n>0){
        current=(List*)malloc(1*sizeof(List));
        current->key=n;
        current->next=head;//LIFO
        head=current;/*head本来是空的 但是 空 已经被next记住了 这时 current给了head 就代表head从后面移到前面 也就是等于这个currentlist就被head记住了现在*/
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
