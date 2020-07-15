#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int SubMatMax(int m[][4],int r,int c,int n){
    int i,j,k,z,max=INT_MIN,sum;
    int markr=-1,markc=-1;

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if((i+n)<=r&&(j+n)<=c){// estimate the dimension here so decrease the complexity
            sum = 0;
            for(k=i;k<i+n;k++){
                for(z=j;z<j+n;z++){
                    //if(k>=0&&k<r&&z>=0&&z<c){ not good here, high complexity
                       sum+=m[k][z];
                   //}
                }
            }
            if(sum>max){
                markr=i;
                markc=j;
                max = sum;
              }
            }
        }
    }
    printf("The square with dimension %d start from position (%d,%d) has the max sum",n,markr,markc);
    return max;
}

int main()
{
    int i,j,m[3][4]={5,2,3,1,3,1,6,4,3,0,5,2};
    printf("Insert\n");

    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
           printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf(" %d\n\n\n",SubMatMax(m,3,4,2));
    printf("Hello world!\n");
    return 0;
}
