#include<stdio.h>
#include<stdlib.h>

#define N 9
// OKAY

//Simple Combination
//function prototype
                   //m[][9]
void cover(int **m,int n,int k);//allocation function
int recur(int **m,int n,int k,int *sol,int pos,int start);//recursion function


int main(){
    //int m[5][8]={{1,2,3},{2,3,7},{7,8},{3,4},{4,5,6}};
    int n=5,k=3,i,j;
   // cover(int m[][],int n,int k);
    int **m;
    m=(int**)malloc(n*sizeof(int*));
    if(m==NULL){
        printf("Allocation error!\n");
        exit(-1);
    }
    for(i=0;i<n;i++){
        m[i]=(int*)malloc(9*sizeof(int));
        if(m[i]==NULL){
           printf("Allocation error!\n");
           exit(-1);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<9;j++){
            m[i][j]=0;
        }
    }

    m[0][0]=1;
    m[0][1]=2;
    m[0][2]=3;
    m[1][0]=2;
    m[1][1]=3;
    m[1][2]=7;
    m[2][0]=7;
    m[2][1]=8;
    m[3][0]=3;
    m[3][1]=4;
    m[4][0]=4;
    m[4][1]=5;
    m[4][2]=6;

    cover(m,n,k);
    return 0;
}


//allocation function
void cover(int **m,int n,int k){
    int i,*sol,j;

    sol=(int*)malloc(k*sizeof(int));
    if(sol==NULL) exit(-1);

    for(i=0;i<k;i++){
        sol[i]=-1;
    }

    if(recur(m,n,k,sol,0,0)==1){
        printf("\n\nThe sub-sets covering all elements in the Set are:\n\n");
        for(i=0;i<k;i++){//sol[i] row index
            printf("S(%d) ",sol[i]);//final sol array :sol[0]=0,sol[1]=2,sol[2]=4
        }//print out S(0) S(2) S(4) these three subsets
        printf("\n\n");
    }
    else{
        printf("Does not exit\n\n");
    }
    free(sol);
}


int recur(int **m,int n,int k,int *sol,int pos,int start){
    int i,j,z,flag,count[9]={0};

    if(pos>=k){
        //printf("Here\n");
        //count=(int*)malloc(N*sizeof(int));
        //if(count==NULL) exit(-1);

//        for(i=0;i<N;i++) 没必要 上面一行就可以了 count[9]={0};
//            count[i]=0;

        for(i=0;i<k;i++){//i for the solution
            for(j=0;m[sol[i]][j]!=0;j++){ //j for each element in each sub-set,each row we picked in the solution
                                         // so m[sol[i]][j] is each element we pick, next, we need to make sure we pick all from 1 to 9
               count[m[sol[i]][j]]=1;//or count++ indicates that this NUMBER appear one time in the subsets that we picked in our solution
            } //[0 1 1 1 1 1 1 1 1]
        }

        for(i=1;i<=8;i++){
           if(count[i]==0){// if we have any value count[i]=0, we miss the value i, this solution is not ok, return 0
                return 0;
           }
        }
        return 1;
    }

    for(i=start;i<n;i++){
        sol[pos]=i;
        if(recur(m,n,k,sol,pos+1,i+1)==1){ //if it returns zero, we will not return 1 and we will go on the for loop to pick another combination
            return 1;
        }
    }
    return 0;
}



//int recur(int m[][9],int n,int k,int *sol,int pos,int start,int val[N]);
/*    if(pos>=k){
        printf("HERE");

        for(i=0;i<k;i++){//n rows
            for(j=0;m[i][j]!=0;j++){//cols
                flag=0;
                for(z=0;z<N;k++){
                    if(m[sol[i]][j]==val[z]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                  return 0;
               }
            }
        }
        return 1;
    }
*/
