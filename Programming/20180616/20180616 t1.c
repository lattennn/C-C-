#include<stdio.h>
#include<string.h>
#include<stdlib.h>




int string_count(char *s,int n){
    int count=0,i=0,j=0,m=0;
    for(i=0;i<=(strlen(s)-n);i++){
        m=0;//count how many aioue for each n-size sub string
        for(j=0;j<n;j++){//each element inside the sub string
            //or atoi(s[i+j])>96 && <112 ....
            if(s[i+j]=='a'||s[i+j]=='i'||s[i+j]=='u'||s[i+j]=='e'||s[i+j]=='o'||
               s[i+j]=='A'||s[i+j]=='I'||s[i+j]=='U'||s[i+j]=='E'||s[i+j]=='O')
                m++;
        }
        if(m>=2){
            count++;
            for(j=0;j<n;j++){
                printf("%c",s[i+j]);
            }
            printf("\n");
        }
    }
    return count;
}


int main()
{
    char ss[10]="ForExample";
    printf("\n\n%d substrings.\n\n\n",string_count(ss,4));
    return 0;
}
