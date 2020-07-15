#include <stdio.h>
//#include <iostream>
//#include <ctype.h>
#include <limits.h>
//using namespace std;
//找到数组里的每一个数的次数 没有负数
//题目 打印出数组里的出现最多次数的元素
#define N 10
#define MAX 7                   /*b 数组 的index 是 A数组里的数的值 那b数组便可以存每个A元素的出现次数 在其对应的index上
                           /*so we set a array B to count the number of the apperance of every number in array  A */

int main( ) {
     int a[N]={1,2,2,4,3,4,6,7,4,5};
     int *b,i,value_with_maxapp,max,maxapp;
                                           /* B[j] 先全部初始化都弄成0 然后B[A[i]]就是A[i]出现的次数
                                           那对应的这个 A[i] 就是要输出的那个出现次数最多的那个数值 */
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
