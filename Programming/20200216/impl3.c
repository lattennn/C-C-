#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void powerset(int pos,char* str,int* sol,int n,int m,int len);
void generate(char*str,int n,int m);


int main(){
    char *str="1234567890";
    int n=2,m=9;
    generate(str,n,m);
    return 0;
}

void generate(char* str,int n,int m){
    int *sol;
    int length=strlen(str);
    int i;

    sol=(int*)malloc(length*sizeof(int));// malloc + initialization to 0
    if(sol==NULL) printf("Allocation Error!\n");
    for(i=0;i<length;i++)
        sol[i]=0;
    powerset(0,str,sol,n,m,length);
    free(sol);
}

void powerset(int pos,char* str,int* sol,int n,int m,int len){
   int i,count,sum;
   if(pos>=len){
    count=0;
    sum=0;
    for(i=0;i<len;i++){
        count+=sol[i];
        if(sol[i]==1){
            //sum+=(int)str[i];
            sum+=str[i]-'0';
        }
    }
    //printf("\ncount is %d,sum is %d",count,sum);
    if(count<=n&&sum==m){
        printf("{");
        for(i=0;i<len;i++){
            if(sol[i]!=0){
                printf("%c,",str[i]);
            }
        }
        printf("}");
    }
    return;
   }
   sol[pos]=0;
   powerset(pos+1,str,sol,n,m,len);
   sol[pos]=1;
   powerset(pos+1,str,sol,n,m,len);
   return ;

}
