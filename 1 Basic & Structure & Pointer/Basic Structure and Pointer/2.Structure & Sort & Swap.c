#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct{
    int age;
    char name[N];
    int height;

}Person;

void swap(Person *a,Person *b)
{
    Person c;
    c=*a;
    *a=*b;
    *b=c;
    return;
}

int main()
{
    int i,j,flag;
    Person classs[5];  /*an array with 5 structures of this type*/
    printf("enter the information of 5 people(age,name,height)\n");
    for(i=0;i<5;i++)
      scanf("%d%s%d",&classs[i].age,classs[i].name,&classs[i].height);
/*注意要& 因为这个class是一个 结构体数组 这是数组里的一个元素*/
    /*WRONG
        for(i=0;i<5;i++)
           printf("%d %s %d \n",class[i].age,class[i].name,class[i].height);*/

    printf("\n");

    flag=1;
    for(i=0;i<4&&flag==1;i++){
            flag=0;
       for(j=0;j<4-i;j++){
         if(classs[j].age>classs[j+1].age){
            swap(&classs[j],&classs[j+1]);//等同于
            //Person temp
            //temp = class[j]
            //class[j]=class[j+1]
            //class[j+1]=temp;
            flag=1;
          }
       }
    }
    for(i=0;i<5;i++)
        printf("%d %s %d\n",classs[i].age,classs[i].name,classs[i].height);
    return 0;
}
