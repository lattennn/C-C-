#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

void FindString(char s[],char c,int* count);
int main()
{
    char a[N],b;
    //char *c;
    int count=0;
    printf("Enter one string and the character b:\n");
    scanf("%s %c",a,&b);//这里如果%s%c是无法读取成功的
    printf("%s %c \n",a,b);

    FindString(a,b,&count);
    printf("There are %d this characters in this string\n",count);
    return 0;
}

void FindString(char *s,char c,int* count){

    printf("%c HAHA ",c);
    int i=0;//,count=0;
    while(s[i]!='\0'){
       //printf("%c,",s[i]);
       if(s[i]==c){
        (*count)++;// CANNOT write *count++ CANNOT *(count++)
       }
    i++;
    }
}
