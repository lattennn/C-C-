


/*�ݹ�Ĺؼ��㣺���ĵ��÷��ص���*/

#include<stdio.h>
#include<stdlib.h>

/*Iteration
int Sum(int n)
{
    int i,s=0;
    for(i=1;i<=n;i++){
        s+=i;
    }
    return s;
}*/

//Recursion
int Sum(int n)
{
    if(n==1)
        return 1;
    return n+Sum(n-1);
}

void main( )
{
    int x;
    printf("enter one integer\n");
    scanf("%d",&x);
    Sum(x);
}



