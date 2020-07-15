#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 15

//The numeric substring should be transfer from char* to int*

typedef struct node{
    char *sub;//char sub[N]
    struct node *next;
}node_t;

node_t *splitStr(char *str){
    int len,count=0,i,j,k;
    char *temp;
    node_t *head,*current;
    head = NULL;
    len = strlen(str);
    i=0;
    while(str[i]!='\0'){
        count = 0;
        while(i<len){
          if(str[i]=='.'){
             break;
          }
          count++;
          i++;
        }
      // printf("%d\n",count); //1 2 3 4 5 5 ok 这些只是当我在debug的时候打印的东西去check对不对 看哪里出问题了

       current = (node_t*)malloc(sizeof(node_t));
       if(current==NULL){
          printf("Error Allocation\n");
          exit(-1);
       }
       current->sub = (char*)malloc((count+1)*sizeof(char));
       if(current->sub==NULL){
          printf("Error Allocation!\n");
          exit(-1);
       }
       for(j=0;j<=count+1;j++){
            current->sub[j]='\0';
       }//记得初始化 因为要一个一个字符去copy

       for(j=0,k=i-count; j<=count&&k<i;j++,k++){
             printf("%c ",str[k]);
             current->sub[j]=str[k];
        }//copy char by char

       current->next=head;
       head=current;
       i++;
        //printf("i : %d\n",i);//2 5 9 14 20 26 ok
    }
    return head;

}



int main()
{
    node_t *head,*current;
    //char str[N]={'a','b','b','c','c','c','d','d','d','d','e','e','e','e','e'};
    //这就是我之前的错误。。。。。我搞了半天 原来是建立的string 忘记打"." !!!!!!! 哈哈哈哈 蠢哭 所以很多时候就是低级错误跑不出来 考试没问题的
    char str[]="a.bb.ccc.dddd.eeeee.fffff";
    head = NULL;
    head = splitStr(str);

    printf("\n\nresult:\n\n");
    for(current=head;current!=NULL;current=current->next){
        printf("\n%s\n",current->sub);
    }

    printf("\n\n\nHello world!\n");
    return 0;
}
