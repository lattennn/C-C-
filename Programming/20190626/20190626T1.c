#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void longestsubstring (char* in,char** out){
    int i=0,best,max=0,l,count=0,j,k;
    char* M;
    l=strlen(in);
    while(i<=l){
        if(in[i]>='A'&&in[i]<='Z'){
          count++;
        }
        else{
            if(count>max){
              printf("%d\n",count);
              max=count;
              best = i-max;//best = i WRONG!
            }
            count=0;
        }
        i++;
    }
    M=(char*)malloc(max*sizeof(char));//M=(char*)malloc(max*sizeof(int));WRONG!!!
    //*out=(char*)malloc((max+1)*sizeof(char));
    for(k=0,j=best;j<=best+max;j++,k++){
       M[k]=in[j];//(*out)[k]=in[j];// Can use out directly actually
    }
    //*out[k]='\0';
    *out=M;
    return;
}

int main()
{
    char in[]={"PSEUDOseudohypoparaTHYROIDISM"};//char*in[]={"PSEUDOseudohypoparaTHYROIDISM"};
    char*out;
    longestsubstring (in,&out);
    printf("%s\n",out);
    return 0;
}
