#include<stdlib.h>
#include<stdio.h>

#define N_L 5

char *sol;
char alfa[N_L] = {'A','E','I','O','U'};
int taken[N_L] = {0};

void aeiou(int position, int N, int reps_allowed) {

    int i;
    if (position == N) {
        for(i=0;i<N;i++) printf("%c", sol[i]);
        printf("\n");
        return;
    }

    for(i=0;i<N_L;i++) {//a i e u o
        if (!taken[i]) {//if(taken[i]==0)
            taken[i] = 1;
            sol[position] = alfa[i];
            aeiou(position+1, N, reps_allowed);
            taken[i] = 0;

        } else if (taken[i] && reps_allowed > 0) {
            sol[position] = alfa[i];
            aeiou(position+1, N, reps_allowed-1);
        }
    }
}

int main(int argc, char **argv) {

    if (argc < 2)
        exit(-1);
    int N = atoi(argv[1]);//
    if (N < N_L)
        exit(-1);

    sol = calloc(N, sizeof(char));
    aeiou(0, N, N-N_L);
    return 0;
}
