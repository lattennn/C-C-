#include <stdio.h>
#include <stdlib.h>

void PrintStars(n)
{
    int i;
    for(i=0;i<n;i++){
    printf("* ");
    }
    printf("\n");
    if(n==1){
        return;
    }//���߿��԰� n==0 ������ д���ʼ ����һ�����Ǵ���֮��ͻ�n=0 Ȼ���return
    PrintStars(n-1);

}

int main()
{
    PrintStars(5);
    return 0;
}
