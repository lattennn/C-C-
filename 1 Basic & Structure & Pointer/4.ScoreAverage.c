#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 10
int main()
{
    int a[N];
    int i,max,p,s;
    float avr;
    printf("enter 10 integers:");
    max=-10000;
    //max=INT_MIN;//include limits head file
    s=0;
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
        s+=a[i];//s=s+a[i];
        if(max<a[i]){
            max=a[i];
            p=i;
        }
    }
    //avr= s/N;//both s and avr should be float
    avr = (float)s / N;//强转型把s从int转成float
    printf("average = %.2f The maximum number is %d and its position is NO.%d\n\n\n",avr,max,p+1);
                    //%.2f 打印float数 只保留小数点后两位小数
    return 0;
}
