#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4
//COMPLETELY OKAY
void recur(int *val,int *mark,int n,int *sol,int *bestsol,int pos,int *maxc,int *minc,int *mindiff){
    int i,j,sum,diff=0,max,min;
    if(pos==n){
        sum=0;
        max=INT_MIN;
        min=INT_MAX;
        for(j=0;j<n;j++){
            sum+=sol[j];//current
            if(sum>max)
                max=sum;
            if(sum<min)
                min=sum;
        }

        diff=max-min;
        if(diff<(*mindiff)){
            *maxc=max;
            *minc=min;
            *mindiff=diff;
            for(j=0;j<n;j++)
                bestsol[j]=sol[j];
        }
        return;
    }

    for(i=0;i<n;i++){
        if(mark[i]==0){
            mark[i]=1;
            sol[pos]=val[i];
            recur(val,mark,n,sol,bestsol,pos+1,maxc,minc,mindiff);
            mark[i]=0;
        }
    }

}

int main()
{
    int i;
    int val[N]={10,-5,7,-8};
    int sol[N]={0};
    int bestsol[N]={0};
    int mark[N]={0};
    int mx,mi,mdiff;

    mx=INT_MIN;
    mi=INT_MAX;
    mdiff=INT_MAX;

    recur(val,mark,N,sol,bestsol,0,&mx,&mi,&mdiff);

    printf("The best flow with the max current <%d> and the mini current <%d> and mini diff <%d> is : ",mx,mi,mdiff);
    for(i=0;i<N;i++){
        printf("%d ",bestsol[i]);
    }
    printf("\n\nHello world!\n");
    return 0;
}
