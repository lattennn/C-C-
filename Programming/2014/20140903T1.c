#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 15
//okay
void searchStr (char *str, int* start, int *length){
    int i,j,count;

    for(i=0;i<strlen(str);i=j){//i+=count){ both are right
        count=0;
        for(j=i;j<strlen(str);j++){
            if(str[i]!=str[j])
                break;
            count++;
        }
        if(count>(*length)){
            (*length)=count;
            (*start)=i;
        }
    }
}

int main()
{
    char str[N]={'a','b','b','c','c','c','d','d','d','d','e','e','e','e','e'};
    int index=0,len=0,i;

    puts(str);
    for(i=0;i<N;i++){
        printf(" %c ",str[i]);
    }
    searchStr(str,&index,&len);

    printf("\n\nstart = %d ,length = %d \n\n",index,len);

    for(i=index;i<index+len;i++){
        printf("%c",str[i]);
    }
    printf("\n\n\n\n");

    return 0;
}
