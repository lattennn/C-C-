#include <stdio.h>
#include <stdlib.h>
//OKAY
int search (int *vet1, int *vet2, int d1, int d2){
    int i,j,k;

    for(i=0;i<d1;i++){
        if(vet1[i]==vet2[0]){

            for(j=0,k=i;j<d2&&k<d1;j++,k++){
                if(vet1[k]!=vet2[j])
                    break;
            }
            if(j==d2){
                return i;
            }
        }
    }
    return -1;
}


int main()
{
    int vet1[9]={1,2,3,4,5,4,5,6,9};
    int vet2[3]={4,5,6};

    printf("\n%d\n\n",search(vet1,vet2,9,3)+1);
    printf("Hello world!\n");
    return 0;
}
