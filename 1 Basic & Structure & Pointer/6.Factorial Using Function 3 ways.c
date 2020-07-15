#include <stdio.h>
#include <stdlib.h>

//prototype
int Factorial1(int n);//Using iteration
int Factorial2(int n);//Using recursion
void Factorial3(int,int*);//Using iteration and pointer   fac = &f

int main()
{
    int m,f=-1,result;
    printf("insert an integer\n");
    scanf("%d",&m);
    if(m!=0){
        //First Method
        result = Factorial1(m);
        printf("Iteration->The factorial is %d\n",result);

        //Second Method
        printf("Recursion->The factorial is %d\n",Factorial2(m));

        //Third Method
        Factorial3(m,&f);//no return type, not return anything
        printf("Using pointer->The factorial is %d\n",f);
    }
    else{
        printf("The factorial of the integer 0 is 1");
    }
    return 0;
}



int Factorial1(int n)//input parameter type
{
    int i,s=1;//varibles
    for(i=1;i<=n;i++)       /*����n=n*i ��Ϊ n������� ��i<n �Ͳ�����*/
        s=s*i;
    return s;               /*/ע�������Ҫreturn s ��*/
}

int Factorial2(int n){
    int sol;
    if(n==1||n==0)
        return 1;

    return n*Factorial2(n-1);
}


void Factorial3(int n,int* fac)
{
    int i,s=1;
    for(i=1;i<=n;i++)
        s=s*i;
    *fac = s;//fac = &f
    /*/ע�����ﲻ��return������ ��β����дҲ���Բ�дreturn;*/
}
