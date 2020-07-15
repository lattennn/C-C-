#include <stdio.h>
#include <stdlib.h>
void Print(int n)
{
    if(n==0)
        return;
    printf("%d\n",n);
    Print(n-1);
}
int main()
{
    int x;
    printf("enter one integer\n");
    scanf("%d",&x);
    Print(x);
    return 0;
}
