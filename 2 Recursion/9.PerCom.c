#include <stdio.h>
#include <stdlib.h>

//compute m!/n!
int PerCom(int m,int n)
{
    if(m==n+1){
        return n+1;
    }
    return m*PerCom(m-1,n);
}
int main()
{
    int x,y;
    printf("input m = ");
    scanf("%d",&x);
    printf("input n = ");
    scanf("%d",&y);
    if(x>y){
       printf("m!/n!=%d",PerCom(x,y));
    }
    else
        printf("input error\n");
    return 0;
}
