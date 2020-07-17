
//题目描述
//给出一个正整数N和长度L，找出一段长度大于等于L的连续非负整数，他们的和恰好为N。答案可能有多个，我我们需要找出长度最小的那个。
//例如 N = 18 L = 2：
//5 + 6 + 7 = 18
//3 + 4 + 5 + 6 = 18
//都是满足要求的，但是我们输出更短的 5 6 7
//输入描述:
//输入数据包括一行： 两个正整数N(1 ≤ N ≤ 1000000000),L(2 ≤ L ≤ 100)
//输出描述:
//从小到大输出这段连续非负整数，以空格分隔，行末无空格。如果没有这样的序列或者找出的序列长度大于100，则输出No
//示例1
//输入

//18 2
//输出

//5 6 7

//Stupid Way

#include<stdio.h>
#include<stdlib.h>

int findit(int n, int L, int* c,int* length){
    int i,len=L;
    while(len<=100){
        i=0;
        while(i<=n/2){
            if ( ((i+(i+len-1))*len)/2 == n){
                *c=i;
                *length=len;
                return 0; //found
            }
            i++;
        }
        len++;
    }
    return 1;
}
int main(){
    int i,l=0,n,L,index=-1;
    scanf("%d %d",&n,&L);
    if(!(n<=10e9&&n>=1)||!(L>=2&&L<=100)){
        printf("Wrong parameters!\n");
        exit(-1);
    }
    if(findit(n,L,&index,&l)){
        printf("NO");
    }
    else{
        for(i=0;i<l;i++){
            if(i==l-1)
                printf("%d",(index+i));
            else
                printf("%d ",index+i);
        }
    }
    return 0;
}





