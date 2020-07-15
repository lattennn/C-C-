#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<ctype.h>
#define R 3
#define C 4

int main(){
    int i,j,k,z,peak,flag;
    int m[R][C]={{5,2,3,1},
                 {3,1,6,4},
                 {3,0,5,2}};

    peak = INT_MIN;//
    //peak =-1;
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            flag=1;
            for(k=-1;k<=1;k++){
                for(z=-1;z<=1;z++){
                   if((i+k)>=0&&(i+k)<R&&(j+z)>=0&&(j+z)<C&&!(k==0&&z==0)){
                      if(m[i][j]<=m[i+k][j+z]){//if there is just one adjacent point that is large than (i,j), flag=0, (i,j)it's not a peak
                        flag=0;
                      }
                   }
                }
            }
            if(flag==1){
                printf("\nThe element at point(%d,%d),value %d\n",i,j,m[i][j]);
            }
        }
    }
    return 0;
}
