#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define M 5

typedef struct c
{
    int price;
    char brand[N];
    int grade;
}Car;

void assign(Car *t,Car *q)
{
    strcpy(t->brand,q->brand);
    t->price=q->price;
    t->grade=q->grade;
    return;
}
//上下两种都是对的 当t q是指针时候 不可以  t.brand,q.brand  可以 (*t).brand 当结构体类型不是指针 也不可以用->
/*
void assign(Car *t,Car *q)
{
    strcpy((*t).brand,(*q).brand);
    (*t).price=(*q).price;
    (*t).grade=(*q).grade;
    return;
}*/

void swap(Car *a,Car *b)
{
    Car temp;
    //Car *tem;

    //tem=a; 只交换指针是错误的 因为无法用别的方程这样改变指针 原来的方程里无法得到 除非传入指针的指针 才能改变指针
    //a=b;
    //b=tem;

    temp=*b;
    *b=*a;
    *a=temp;
    return;
}

int main()
{
    int i,j;
    Car car[M],min;
    for(i=0;i<M;i++){
        printf("Enter the information(price,brand,grade :'0' old car,'1' new car) of the car NO.%d:",i);
        scanf("%d%s%d",&car[i].price,car[i].brand,&car[i].grade);
    }

    for(i=1;i<M;i++){   //order them with the ascending price
        assign(&min,&car[i]);     /*Car temp
                                    temp = cars[i]; This way is right */
        j=i-1;
        while(j>=0&&min.price<car[j].price){
            swap(&car[j+1],&car[j]);//should be assign
            j--;
        }
        swap(&car[j+1],&min);//should be assign
    }

    for(i=0;i<M;i++){
        printf("%d %s %d \n",car[i].price,car[i].brand,car[i].grade);
    }

    for(i=0;i<M;i++){
        if(car[i].grade==1){
            printf("The cheapest new car is the brand: '%s' with price %d\n",car[i].brand,car[i].price);
            break;
        }
    }

    return 0;
}
