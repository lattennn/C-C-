#include <stdio.h>
#include <stdlib.h>

int Min(int a[],int l,int r)
{
    int u,v,q;
    if(r<=l){
        return a[l];        /*������ ����Ҫ�����Ǹ�����Ҫ�ҵ� ����߱߿�ʼ�ҵ��Ǹ���*/
    }
    q=(l+r)/2;
    u=Min(a,l,q);
    v=Min(a,q+1,r);
    if(u>v)
        return v;
    else
        return u;
}
int main()
{
    int b[10]={45,67,34,87,56,98,23,10,45,23};
    printf("%d ",Min(b,0,9));
    return 0;
}
