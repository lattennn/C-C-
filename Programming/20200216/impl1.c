#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void histogram(char*str){
     int count[26]={0};    /*the array named count to count the times which
                            the letters appears in the given string*/
     int i,temp;
     //char *letter;

     int n=strlen(str);

  //  for(i=0;i<26;i++)
  //     printf("%d %d ",i,count[i]);

     for(i=0;i<n;i++){
       // printf("Here %c ",str[i]);
        temp=((int)str[i])-97;
        //temp=str[i]-'a';
        printf("%d\n",temp);
        count[temp]++;//NEED initialization to 0
     }

//     for(i=0;i<26;i++)
//       printf("%d\n",count[i]);

     for(i=0;i<26;i++){
      if(count[i]!=0){
       //itoa(i+97,letter,10);

       printf("\"%c\":%d ",(char)(i+97),count[i]);
      }
     }
return;
}

int main(){

    char *s="azaaabbnnccacczn";
    histogram(s);
    return 0;
}
