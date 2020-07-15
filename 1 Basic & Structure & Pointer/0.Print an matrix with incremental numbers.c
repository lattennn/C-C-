#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,a[3][4],row_index,column_index;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            a[i][j]=4*i+j+1; //因为有四列 所以在换行处就会是增加 4*i这么多个数 遇到别的题就卜是写4 列数为多少写多少
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("The coordinates of each element are :\n");
    for(i=1;i<=(3*4);i++){
        printf("%d's coordinate is:",i);
        row_index=(i-1)/4;      //知道了哪个数 直接可以算出这个数所在的坐标
        column_index=(i-1)%4;
        printf("(%d,%d)\n",row_index,column_index);
    }

    printf("\n\n");
    return 0;
}


