#include <stdio.h>
#include <stdlib.h>
//���Ӷȵ�ʽ��Ϊ��� �����n֮��ĸ��Ӷ�Ϊ����
// T(n)=3*T(n/2)+n

int RecFunc(int n)
{
    int m;
    if(n==1){
        return 1;
    }
    m=3*RecFunc(n/2)+n;
    return m;
}
int main()
{
    printf("%d",RecFunc(10));
    return 0;
}
