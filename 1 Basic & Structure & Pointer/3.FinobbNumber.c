#include <stdio.h>
#include <stdlib.h>
//1 2 3 5 8....
int main()
{
    int a[20];//memory allocation is already done,dimension is equal to 20
    int i;

    a[0]=1;
    a[1]=2;
    printf("1 2 ");
    for(i=2;i<20;i++){ //iteration
        a[i]=a[i-1]+a[i-2];
        printf(" %d",a[i]);
    }
    return 0;
}
