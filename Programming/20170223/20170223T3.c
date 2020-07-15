#include <stdio.h>
#include <stdlib.h>

//I created a m[5][5]-->shows that:
//0 2 should be connected
//0 4 should be connected
//and k = 4 the set should be into 2 partition with at least one of them with size 4
//So only 2 possible outcomes: set {0,1,2,4}&{3} or {0,2,3,4}&{1};
//if I change k = 3 totally 3 possible outcomes:set {0,2,4}&{1,3} or 2 answers above

#define BLOCK 2
int partition (int n,int k,int m[5][5]);
void rec(int m[5][5],int n,int k,int *sol,int pos,int block);

int main(){
    int m[5][5]={{1,0,1,0,1},
                 {0,1,0,0,0},
                 {1,0,1,0,0},
                 {0,0,0,1,0},
                 {1,0,0,0,1}
                 };
    int i,j,n=5,k=3;
    for(i=0;i<n;i++){
        printf("%d connects:",i);
        for(j=0;j<n;j++){
            if(m[i][j]==1){
                printf("%d ",j);
            }
        }
        printf("\n");
    }
    if(partition(n,k,m))
    printf("Hello world!\n\n");
    return 0;
}
int partition (int n,int k,int m[5][5]){
    int *sol,i;
    sol=(int*)malloc(n*sizeof(int));
    if(sol==NULL){
        printf("Error Allocation!\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
        sol[i]=-1;

    rec(m,n,k,sol,0,0);
 /*   if(rec(m,n,k,sol,0)){
        printf("Found such a set partition!\n");
        return 1;
        }
    else{
        printf("Not found such a set partition!\n");
        return 0;
        }*/
    return 0;
}


void rec(int m[5][5],int n,int k,int *sol,int pos,int block){
    int i,j,count[2]={0};//2 partition sets in these case OTHER WISE count[k]={0}

    if(pos==n){//termination that we have found the solution, the dimension reaches to the required size
        if(BLOCK==block){//FROM 0 TO 2
        for(i=0;i<n;i++)//sum up how many elements are there for every (each) partition-set
            count[sol[i]]++;
        if(  (count[0]>=k||count[1]>=k) && count[0]!=0 && count[1]!=0){//for sure no empty set and at least one set has dimension >=k
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(m[i][j]==1&&sol[i]!=sol[j])//m[i][j]==1 means i and j have to stay together in the same block, so sol[i]should==sol[j]
                        return;
                }
            }

            /*for(i=0;i<2;i++){     //i=0;i<k;i++ when
                printf("Belonging to the set NO.%d :",i+1);
                for(j=0;j<n;j++){   //solution dimension
                if(sol[j]==i)
                    printf("%d ",j);
                }
            }*/
            printf("\n{");
            for(i=0;i<n;i++)
                if(sol[i]==0) printf(" %d ",i);
            printf("},{");
            for(i=0;i<n;i++)
                if(sol[i]==1) printf(" %d ",i);
            printf("}");
            return;
          }
        }
        return;
    }

    for(i=0;i<block;i++){
        sol[pos]=i;
        rec(m,n,k,sol,pos+1,block);
    }
    sol[pos]=block;
    rec(m,n,k,sol,pos+1,block+1);
    return;
}


/*
int rec(int m[5][5],int n,int k,int *sol,int pos){
    int i,j,count[2]={0};//2 partition sets in these case OTHER WISE count[k]={0}
    if(pos==n){
        for(i=0;i<n;i++)//sum up how many elements are there for every (each) partition-set
            count[sol[i]]++;
        if((count[0]>=k||count[1]>=k)&&count[0]!=0&&count[1]!=0){//for sure no empty set and at least one set has dimension >=k
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(m[i][j]==1&&sol[i]!=sol[j])
                        return 0;
                }
            }
            for(i=0;i<2;i++){
                printf("Belonging to the set NO.%d :",i+1);
                for(j=0;j<n;j++){
                if(sol[j]==i)
                    printf("%d ",j);
                }
            }
            return 1;
        }
        return 0;
    }

    for(i=0;i<2;i++){
        sol[pos]=i;
        if(rec(m,n,k,sol,pos+1))
            return 1;
    }
    return 0;
}
*/
