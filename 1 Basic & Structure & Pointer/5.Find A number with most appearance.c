#include <stdio.h>
//#include <iostream>
//#include <ctype.h>
#include <limits.h>
//using namespace std;
//�ҵ��������ÿһ�����Ĵ��� û�и���
//��Ŀ ��ӡ��������ĳ�����������Ԫ��
#define N 10
#define MAX 7                   /*b ���� ��index �� A�����������ֵ ��b�������Դ�ÿ��AԪ�صĳ��ִ��� �����Ӧ��index��
                           /*so we set a array B to count the number of the apperance of every number in array  A */

int main( ) {
     int a[N]={1,2,2,4,3,4,6,7,4,5};
     int *b,i,value_with_maxapp,max,maxapp;
                                           /* B[j] ��ȫ����ʼ����Ū��0 Ȼ��B[A[i]]����A[i]���ֵĴ���
                                           �Ƕ�Ӧ����� A[i] ����Ҫ������Ǹ����ִ��������Ǹ���ֵ */
     //max = -100000;
     max = INT_MIN;
 //    min = INT_MAX;   There is a question We just can only use this method in the case there are just positive number in array A
     for(i=0;i<N;i++){
        if(a[i]>max){
            max = a[i];
        }
     }

     b = (int*)malloc((max+1)*sizeof(int));// Dynamically memory allocation
     if(b==NULL) {
        printf("Allocation Error!\n");
        exit(-1);
     }

     for(i=0;i<=max;i++)
        b[i]=0;

     for(i=0;i<N;i++)
        b[a[i]]++;


     maxapp=-1;
     for(i=0;i<=max;i++){
        if(b[i]>maxapp){
            maxapp = b[i];
            value_with_maxapp = i;
        }
     }
     printf("The number with the most appearance is %d ",value_with_maxapp);
     return 0;
}
