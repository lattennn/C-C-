#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,a[3][4],row_index,column_index;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            a[i][j]=4*i+j+1; //��Ϊ������ �����ڻ��д��ͻ������� 4*i��ô����� ���������Ͳ���д4 ����Ϊ����д����
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("The coordinates of each element are :\n");
    for(i=1;i<=(3*4);i++){
        printf("%d's coordinate is:",i);
        row_index=(i-1)/4;      //֪�����ĸ��� ֱ�ӿ��������������ڵ�����
        column_index=(i-1)%4;
        printf("(%d,%d)\n",row_index,column_index);
    }

    printf("\n\n");
    return 0;
}


