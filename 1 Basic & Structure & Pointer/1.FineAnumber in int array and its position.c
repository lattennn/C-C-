#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int n,i,flag,p,count=0;

    int a[N]={23,34,5,5,23,89,88,93,90,10};

    printf("insert!\n");//%d integer %c character %s string:An array with some characters with termination \0
    //字符数组和字符串的区别
    //字符数组 可以只是一个数组 里面每个元素 都是一个字符
    //字符串 是一个数组 里面每一个元素都是一个字符 但是最后一定是用\0作为结尾

    scanf("%d",&n);//取n的地址 然后赋值

    flag=0;//赋值 single equal
    for(i=0;i<10;i++){
        if(a[i]==n){//判断 double equal
            p=i;
            flag=1;
            break;//退出当前循环
        }
    }

    if(flag==1){
        printf("the integer %d exists,in the position %d \n",n,p+1);

    }
    else{
        printf("%d does not exist! \n",n);
    }

    for(i=0;i<10;i++){
        if(a[i]==n){
            count++;//count=count+1
        }
    }
    printf("the value %d appears %d times\n\n",n,count);

    return 0;
}
