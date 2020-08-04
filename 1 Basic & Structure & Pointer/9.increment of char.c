#include<stdio.h>
#include<stdlib.h>

int main(){
    char b[]="hello\0";
    char *a = "hello";
    // NO WRONG !!!!!!! char *a="hello";
    char c='0';

    c=c+1;
    printf("\n\nTHIS WHAT THE FUCK %c\n\n",c);

    printf("This is b %c \n",*b);

    printf("\n%c",*a);
    printf("\n%s",a);
    printf("\n%c",a[1]);

    b[1]=b[1]+1;
    //*(a+1)=(*(a+1))+1;

    printf("\n%s",b);

    return 0;
}

