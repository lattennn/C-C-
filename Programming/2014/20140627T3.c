#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3
#define dish_name_lenth 10
//okay

int buildrecur(char ***dat,char **sol,int n,int pos,int count);//prototype

//allocation function
void buildMenu (char **data[], int n){
    int i,number;
    char **sol;

    sol=(char**)malloc(n*sizeof(char*));//
    if(sol==NULL){
        printf("Error Allocation!\n");
        exit(-1);
    }
 // sol[0]= "duck\0\0\0\0\0\0"
 //sol[0][0]='d';
 //sol[0][1]='u';
 //sol[0][2]='c';
 //sol[0][3]='k';
 //sol[0][4]='\0' sol[0][5]='\0' sol[0][6]='\0' sol[0][7]='\0' sol[0][8]='\0' sol[0][9]='\0' sol[0][10]='\0'
 //because we define dish name length is 10
//but we only use sol[0] sol[1] sol[2] because we need the "dish name",they are strings!
    for(i=0;i<n;i++){
        sol[i]=(char*)malloc(dish_name_lenth*sizeof(char));//£¡£¡£¡
        if(sol[i]==NULL){
            printf("Error Allocation!\n");
            exit(-1);
        }
    }

    number = buildrecur(data,sol,3,0,0);//
    printf("\n\nThere are totally %d menus.\n\n\n",number);
    return;
}
                            //sol saves n strings //pos = n //only multiplication not combination no START
int buildrecur(char ***dat,char **sol,int n,int pos,int count){//function head needs to indicate every parameters and their type!!!!!
    int i;
    if(pos==n){
        count++;
        printf("\nMenu_%d:",count);
        for(i=0;i<n;i++){
            printf("%s ",sol[i]);
        }
        return count;
    }

    for(i=0;dat[pos][i]!=NULL;i++){
        strcpy(sol[pos],dat[pos][i]);//both are string pointer -> char*
        count=buildrecur(dat,sol,n,pos+1,count);
    }
    return count;
}

int main()
{
    char ***d;
    int i;
    d=(char***)malloc(N*sizeof(char**));//N course oer menu
    if(d==NULL){
        printf("Error Allocation\n\n");
        exit(-1);
    }

    for(i=0;i<N;i++){
        d[i]=(char**)malloc(5*sizeof(char*));
        if(d[i]==NULL){
          printf("Error Allocation\n\n");
          exit(-1);
        }
    }

   // len=strlen("duck_salad");
   // d[0][0]=(char*)malloc(len*sizeof(char));
    //strcpy(d[0][0],"duck_salad");
    d[0][0]=strdup("duck_salad");
    d[0][1]=strdup("scotch_egg");
    d[0][2]=strdup("soupeandbread");
    d[0][3]=strdup("baby_squid");
    d[0][4]=NULL;


    d[1][0]=strdup("rabit");
    d[1][1]=strdup("fish_and_chips");
    d[1][2]=strdup("roast");
    d[1][3]=NULL;
    d[1][4]=NULL;

    d[2][0]=strdup("gateaux_opera");
    d[2][1]=strdup("ice_cream");
    d[2][2]=strdup("cheese cake");
    d[2][3]=NULL;
    d[2][4]=NULL;


/*
    strcpy(d[0][0],"duck_salad");
    strcpy(d[0][1],"scotch_egg");
    strcpy(d[0][2],"soupeandbread");
    strcpy(d[0][3],"baby_squid");
    d[0][4]=NULL;


    strcpy(d[1][0],"baby_squid");
    strcpy(d[1][1],"fish_and_chips");
    strcpy(d[1][2],"fish_and_chips");
    d[1][3]=NULL;
    d[1][4]=NULL;

    strcpy(d[2][0],"gateaux_opera");
    strcpy(d[2][1],"ice_cream");
    strcpy(d[2][2],"cheese cake");
    d[2][3]=NULL;
    d[2][4]=NULL;
*/
    printf("\nHello world!\n\n");
    printf("The menus are:\n\n");


    buildMenu(d,N);

    return 0;
}
