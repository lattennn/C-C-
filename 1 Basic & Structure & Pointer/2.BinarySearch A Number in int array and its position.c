#include <stdio.h>
#include <stdlib.h>
#define N 10

 // �ж϶������ʱ ����������֮��Ĺ�ϵ һ�㶼�� && AND ͬʱ���� ||OR ����һ������

int main()
{
    int n,i,right,left,mid,flag;
    int a[N]={33,35,45,66,78,96,100,189,267,354};//sorted array

    printf("enter one number \n");
    scanf("%d",&n);

    flag=0;
    left=0;
    right=N-1;
    mid=(left+right)/2;
    while( left<right && mid>=0 && mid<=N-1 ){//mid go out as soon as left==right or left > right
        if(left==right-1){ //ֻҪleft��rightָ������ �����д�ⲿ mid��Զ�����left Ȼ�������ѭ�� �޷��˳�
            if(a[left]==n){
                mid=left;
                flag=1;
                break;
            }
            else if(a[right]==n){
                mid=right;
                flag=1;
                break;
            }
            else{
                break;
            }
        }
        else{
            mid=(left+right)/2;
        }

    ///////�����if ��else��һ���
    // �����if else if ��else ��һ���
        if(a[mid]<n){
            left=mid;
        }
        else if(a[mid]>n){
            right=mid;
        }
        else if(a[mid]==n){
            flag=1;
            break;
        }
        else{
            break;//Ϊ���Ͻ� д�� ��ʵһ��û��������
        }
    }

    if(a[mid]==n || flag==1){
        printf("found!in the position %d of the array \n",mid+1);
    }
    if(flag==0){
        printf("not found\n");
    }
    return 0;
}
