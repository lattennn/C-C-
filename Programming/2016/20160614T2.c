#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
//NOT OKAY
/*
int splitPhrase(char v[],char ***m){
    int i,j,k,count=0,len,**mat;

    for(i=0;v[i]!='\0';i++){
        if(v[i]==' '){
            count++;
        }
    }

    mat=(int**)malloc(count*sizeof(int*));
    if(mat==NULL) {
        printf("Error Allocation!\n");
        exit(-1);
    }

    len = strlen(v);

    for(i=0;i<count;i++){
        mat[i]=(int*)malloc(len*sizeof(int));
        if(mat[i]==NULL){
            printf("Error Allocation!\n");
            exit(-1);
        }
    }

    k=0;
    for(i=0;i<count;i++){
        for(j=0;;j++){
            if(v[k]==' '){
                k++;
                break;
            }
            else
                m[i][j]=v[k++];// !!!
        }
    }
    *m = mat;
    return count;
}
*/

int splitPhrase(char v[],char ***m){
    int i,j,k,count=1,len;
    char **mat;

    for(i=0;v[i]!='\0';i++){//first count how many substrings by the ' '
        if(v[i]==' '){
            count++;
        }
    }
    mat=(char**)malloc((count+1)*sizeof(char*)); //allocate an array with <count> size to save string pointers char*
    if(mat==NULL) {                          //so the type of mat is char**
        printf("Error Allocation!\n");
        exit(-1);
    }
    len = strlen(v);
    for(i=0;i<count;i++){
        mat[i]=(char*)malloc(len*sizeof(char));//just give each char* (in the mat)a maximum length, if there is just one sub-string, the lengthh is strlen(str)
        if(mat[i]==NULL){
            printf("Error Allocation!\n");
            exit(-1);
        }
        for(j=0;j<len;j++)
            mat[i][j]='\0';//initialization necessary! Because we are goint to copy the character one by one so we set all elements \0 first
    }
    i=0;
    j=0;
    k=0;
    while(i<count){ //i count for the total number of substrings
        j=0;//j count for each sub string in each row of mat
        while((v[k]!=' ')&&k<len){// k goes through each element in the origin array V
            //printf("%c",v[k]);
            mat[i][j++]=v[k++];//copy characters one by one, after copying, j++,k++
        }
        printf("\n\n");
        k++;
        i++;
    }
    *m = mat; // we update the pointer m as a report to main function
    return count;
}

int main(){
    int n,i,j;
    char **m;
    char v[1000]="This is a phrase to split into sub-strings";

    n= splitPhrase(v,&m);

    printf("First way to print:\n");
    for(i=0;i<n;i++){
        printf("The %d string = ",i+1);
        puts(m[i]);
    }
    printf("\n\nSecond way to print:\n");
    for(i=0;i<n;i++){
        printf("The %d string = ",i+1);
        for(j=0;m[i][j]!='\0';j++){
            printf("%c",m[i][j]);
        }
        printf("\n");
    }
    return n;
}
