#include<stdlib.h>
#include<stdio.h>

#define N 10

void rot(int *vet, int n, int d){

    int D = (d > 0) ? d : -1*d;//D absolute value of d
    D = D > n ? D%n : D;

    int *aux = calloc(D, sizeof(int)), i, j;//auxiliary array
    if (aux == NULL) exit(-1);

    if (d > 0){
        // ROT_dx right
        for(i=n-D, j=0;i<n;i++) {
            aux[j++] = vet[i];
        }
        for(i=n-1;i>=D;i--) vet[i] = vet[i-D];
        for(i=0;i<D;i++) vet[i] = aux[i];

    } else {
        // ROT_sx left
        for(i=0;i<D;i++) {
            aux[i] = vet[i];
        }
        for(i=0;i<n-D;i++) vet[i] = vet[i+D];
        for(i=n-D, j=0;i<n;i++) vet[i] = aux[j++];
    }

    free(aux);
}

int main(int argc, char **argv) {

    int vet[N] = {0,1,2,3,4,5,6,7,8,9};
    rot(vet, N, -2);
    rot(vet, N, 4);
    rot(vet, N, 46);
    return 0;
}
