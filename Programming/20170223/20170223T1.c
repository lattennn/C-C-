#include <stdio.h>
#include <stdlib.h>

void copySubMat(int m1[][8],int r1,int c1,int m2[][6],int r2,int c2,int x,int y){
    int i,j;
    printf("point (%d,%d) \n",x,y);
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){

            if((i+x)>=0&&(i+x)<r1&&(j+y)>=0&&(j+y)<c1){
                    printf("now changing the row %d and col %d of matrix1\n",i+x,j+y);
                    printf("%d->",m1[i+x][j+y]);
                    m1[i+x][j+y]=m2[i][j];
                    printf("%d\n",m2[i][j]);
            }
        }
    }
    return;
}

int main(){
    int i,j,m1[8][8],m2[6][6];
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            m1[i][j]=j;
        }
    }
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            m2[i][j]=j;
        }
    }


    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d ",m1[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            printf("%d ",m2[i][j]);
        }
        printf("\n");
    }



/*    printf("THE FIRST MATRIX:\n");
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d ",m1[i][j]);
        }
        printf("\n");
    }
    printf("THE SECOND MATRIX:\n\n");
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            printf("%d ",m2[i][j]);
        }
        printf("\n");
    }
*/
    copySubMat(m1,8,8,m2,6,6,5,2);

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d ",m1[i][j]);
        }
        printf("\n");
    }


}
