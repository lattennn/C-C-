#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 26

void histogram (char *str)
{
    int i,j,l,v[M];
    l = strlen(str);

    for(i=0; i<M; i++)
    {
        v[i]=0;
    }

    for(j=0; j<l; j++)
    {
        v[((int)str[j])-97]++;
    }

    for(i=0; i<M; i++)
    {
        if(v[i]!=0)
        {
            printf("\"%c\":%d",(char)((int)'a'+i),v[i]);
        }
    }
    return;
}

int main(){
char *str="azaaabbnnccacczn";
histogram(str);
return 0;
}
