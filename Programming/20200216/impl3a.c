#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void arr(int pos,char* str,char* sol,int n,int m,int* mark);
void generate(char*str,int n,int m);

int main(){
    char *str="1234567890";
    int n=2,m=9;
    generate(str,n,m);
    return 0;
}

void generate(char* str,int n,int m){
    char *sol;
    int *mark;
    int length=strlen(str);
    int i;

    mark=(int*)calloc(length,sizeof(int));// malloc + initialization to 0

    sol=(char*)malloc(n*sizeof(char));
    if(sol==NULL) printf("Allocation Error!\n");
    for(i=0;i<length;i++)
        sol[i]="\n";

    for(i=1;i<=n;i++)
        arr(0,str,sol,i,m,mark);
    free(sol);
}

void arr(int pos,char* str,char* sol,int n,int m,int *mark){
   int i,count,sum;

   if(pos>=n){
    sum=0;
    for(i=0;i<n;i++){
            //sum+=(int)str[i];
            sum+=sol[i]-'0';
    }
    if(sum==m){
        printf("{");
        for(i=0;i<n;i++){
            printf(" %c ",sol[i]);
        }
        printf("} ");
    }
    return;
   }
   for(i=0;i<strlen(str);i++){
     if(mark[i]==0){
        mark[i]=1;
        sol[pos]=str[i];
        arr(pos+1,str,sol,n,m,mark);
        mark[i]=0;
     }
   }
   return ;

}
