
//better

#include<stdio.h>
#include<stdlib.h>

int findit(int n, int L, int* c,int* length){
    int i,len=L;
    while(len<=100){
        //((2*n/L )- L+1) =  2 i
        // (((2*n/len )- len+1) & 1) == 0 NEED TO () BEFORE == because the precedence of operator '&' is lower than '==' 
        // (((2*n/len )- len+1) % 2 )== 0 EQUIVALENT TO THIS      
        if ( (((2*n/len )- len+1) & 1) == 0 && (2*n)%len ==0 ){
            *c = (((2*n/len )- len+1)/2);
            *length=len;
            return 0; //found
        }
        len++;
    }
    return 1;
}
int main(){
    int i,l=0,n,L,index=-1;
    scanf("%d %d",&n,&L);
    if(!(n<=10e9&&n>=1)||!(L>=2&&L<=100)){
        printf("Wrong parameters!\n");
        exit(-1);
    }
    if(findit(n,L,&index,&l)){
        printf("No");
    }
    else{
        for(i=0;i<l;i++){
            if(i==(l-1))
                printf("%d",(index+i));
            else
                printf("%d ",(index+i));
        }
    }
    return 0;
}





