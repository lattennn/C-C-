/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
void Revers(char *a)
{
    if(*a=='\0')
        return;
    Revers(a+1);
    printf("%c",*a);
}
int main()
{
    char s[N];
    printf("Enter the string\n");
    gets(s);
    Revers(s);
    return 0;
}
*/

#include <stdio.h>

void rprints(char *s){
    if(*s == '\0')
        return;
    rprints(s+1);
    printf("%c", *s);
    return;
}

int main()
{
    char *s;
    int n=5;
    s=(char*)malloc(n*sizeof(char));
    if(s==NULL){
        printf("ERROR");
        exit(-1);
    }
    printf("Enter a string:\n");
    scanf("%s", s);
    rprints(s);
    printf("\n");
    return 0;
}

