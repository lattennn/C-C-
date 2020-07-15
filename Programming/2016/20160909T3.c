#include <stdio.h>
#include <stdlib.h>
//birthday return type why should be int ,I think it could be void
int birthday(int *vet,int n,int m,int k);
int recur(int *vet,int *sol,int n,int m,int k,int pos,int start,int count);

int birthday(int *vet,int n,int m,int k){//k is a variable ====== the length of the array sol is not fixed
    int *s,count;

    s=(int*)malloc(k*sizeof(int));
    if(s==NULL){
        printf("Allocation Error!\n");
        exit(-1);
    }
    printf("All possible selections are the following: ");
    count=recur(vet,s,n,m,k,0,0,0);// call the first recursive function --> give all the parameters the initial values

    return count;
}

int recur(int *vet,int *sol,int n,int m,
          int k,int pos,int start,int count){
    int i,j,flag;
    if(pos==k){
        flag=1;
        for(i=0;i<(k-1)&&flag==1;i++){
            for(j=i+1;j<k;j++){
               if(vet[sol[i]]==vet[sol[j]]){
                    flag=0;
                    break;
               }
            }
        }
        if(flag==1){
            printf("\n(");
            for(i=0;i<k;i++){
                printf(" %d ",sol[i]);
            }
            printf(")");
            count++;
            return count;
        }
        return count;
    }

    for(i=start;i<n;i++){
        sol[pos]=i;
        count=recur(vet,sol,n,m,k,pos+1,i+1,count);
    }
    return count;
}

int main()
{
    int vet[6]={1,2,3,1,2,3};
    int n=6,k=2,m=3,number;

    number = birthday(vet,n,m,k);
    printf("\nThere are %d choice\n",number);
    printf("Hello world!\n");
    return 0;
}
