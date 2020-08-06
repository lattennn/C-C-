#include <stdio.h>
#include <stdlib.h>

void PrintStars(int n)
{
    int i;
    if(n==0){
      return;
    }
    PrintStars(n-1);
    for(i=0;i<n;i++){
        printf("* ");
    }
    printf("\n");
    return;
}
int main()
{
    PrintStars(5);
    return 0;
}
