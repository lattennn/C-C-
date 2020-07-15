#include <stdio.h>
#include <stdlib.h>
void put(int*,int,int,int);//NO NEED TO PASS K

void nonIncreasing(int n){
    int*sol,j;

    sol=(int*)malloc(n*sizeof(int));//max length is n, just need 1 time allocation
    if(sol==NULL){
        fprintf(stderr,"Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    for(j=n;j>1;j--){//j cannot equal to 1, because it requires sum, at least 2 numbers
       put(sol,0,j,n);//max n numbers sum up n*1 = n
    }
    free(sol);
    return;
}

void put(int*sol,int pos,int j,int n){   //,int k){
    int sum,i,flag,k;
    if(pos==j){
       sum=0;//remember to initialization before you use it
       for(i=0;i<pos;i++){
          sum+=sol[i];
       }
       flag=1;//initialization here not in the beginning
       for(i=0;i<pos-1;i++){
            if(sol[i]<sol[i+1]||sum!=n){
                flag=0;//sol has to be non-increasing, so if we find i+1 bigger than i, NOT OK
            }
        }
        if(flag==1){
            for(i=0;i<pos;i++){
                fprintf(stdout,"%d",sol[i]);
            }
            fprintf(stdout,"\n");
        }
        return;//remember to return in when termination finishes
    }
    for(k=1;k<=n;k++){
        sol[pos]=k;
        put(sol,pos+1,j,n);
    }
    return;
}
int main()
{
    int n=5;
    nonIncreasing(n);

    return 0;
}
