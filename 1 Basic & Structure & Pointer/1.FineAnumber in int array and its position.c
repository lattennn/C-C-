#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int n,i,flag,p,count=0;

    int a[N]={23,34,5,5,23,89,88,93,90,10};

    printf("insert!\n");//%d integer %c character %s string:An array with some characters with termination \0
    //�ַ�������ַ���������
    //�ַ����� ����ֻ��һ������ ����ÿ��Ԫ�� ����һ���ַ�
    //�ַ��� ��һ������ ����ÿһ��Ԫ�ض���һ���ַ� �������һ������\0��Ϊ��β

    scanf("%d",&n);//ȡn�ĵ�ַ Ȼ��ֵ

    flag=0;//��ֵ single equal
    for(i=0;i<10;i++){
        if(a[i]==n){//�ж� double equal
            p=i;
            flag=1;
            break;//�˳���ǰѭ��
        }
    }

    if(flag==1){
        printf("the integer %d exists,in the position %d \n",n,p+1);

    }
    else{
        printf("%d does not exist! \n",n);
    }

    for(i=0;i<10;i++){
        if(a[i]==n){
            count++;//count=count+1
        }
    }
    printf("the value %d appears %d times\n\n",n,count);

    return 0;
}
