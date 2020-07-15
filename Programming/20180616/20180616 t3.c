#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void rec(char *s,int k,int *sol,int pos,int start);

//allocation function!
int subsequence(char *s,int k){
    char *sol=malloc(k*sizeof(char));

 //   if(sol==NULL) exit(-1);

    if(sol==NULL) {
        printf("error allocation!\n");
        exit(-1);
    }
    int i=0,pos=0,start=0;
    for(i=0;i<k;i++)//optional
        sol[i]='0';//optional
    rec(s,k,sol,pos,start);
    return 1;
}

void rec(char*s,int k,int *sol,int pos,int start){
    int i,j;
    if(k==pos){
       for(i=0;i<k-1;i++){
            if(sol[i]>sol[i+1]){//strictly alphabetically ordered
                return;
            }
       }
       for(i=0;i<k;i++){
           printf("%c ",sol[i]);
       }
       return;
    }
    for(i=start;i<strlen(s);i++){ //strlen(s) = n
        sol[pos]=s[i];
        rec(s,k,sol,pos+1,i+1);
    }
}
int main(){
    char string[4]="AZCD";
    if(subsequence(string,3))
        printf("\n\nSuccesful!\n\n\n");

    return 0;
}
