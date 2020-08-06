#include <stdio.h>
#include <stdlib.h>
int Factorial(int n)
{
    if(n==1){
        return 1;
    }
    Factorial(n-1);
    return n*Factorial(n-1);
}

int main()
{
    int x;
    scanf("%d",&x);
    printf("%d",Factorial(x));
    return 0;
}
