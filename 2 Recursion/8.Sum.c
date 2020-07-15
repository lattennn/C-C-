


/*递归的关键点：在哪调用返回到哪*/

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



