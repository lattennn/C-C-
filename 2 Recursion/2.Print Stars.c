#include <stdio.h>
#include <stdlib.h>

void PrintStars(int n)
{
    int i;
    for(i=0;i<n;i++){
    printf("* ");
    }
    printf("\n");
    if(n==1){
        return;
    }//或者可以把 n==0 的条件 写在最开始 这样一颗星星打完之后就会n=0 然后就return
    PrintStars(n-1);

}

int main()
{
    PrintStars(5);
    return 0;
}
