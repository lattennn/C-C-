#include<stdlib.h>
#include<stdio.h>

typedef struct node_t_ {
    float f;
    int col;
    struct node_t_ *next;
} node_t;

typedef struct list_t_ {
    int nEl;
  //  int rn;*********************
    node_t *next;
} list_t;

typedef struct matr_t_ {
    int NR, NC;
    list_t *rows;
} matr_t;

void MATRwrite(matr_t *M, int r, int c, float val);
matr_t *MATRinit(int r, int c);
void PRINTmatr(matr_t *M, int r, int c);


node_t * NEWfloatNode(float val, int col, node_t *next) {
    node_t *n = malloc(sizeof(node_t));
    if (n == NULL) exit(-1);
    n->col = col;
    n->f = val;
    n->next = next;

    return n;
}


int main(int argc, char **argv) {
    matr_t *M = MATRinit(10,10);
    MATRwrite(M, 2, 3, 3.5);
    MATRwrite(M, 2, 7, 32.5);
    MATRwrite(M, 3, 1, 1.5);
    MATRwrite(M, 2, 2, 0.5);
    MATRwrite(M, 2, 2, 23.5);
    MATRwrite(M, 10, 12, 23.5);
    MATRwrite(M, 4, 5, -3);
    MATRwrite(M, 4, 4, -2);
    MATRwrite(M, 4, 3, -1);
    MATRwrite(M, 4, 6, 0);
    MATRwrite(M, 9, 9, 100.0);


    PRINTmatr(M,M->NR, M->NC);
    return 0;
}

void PRINTmatr(matr_t *M, int r, int c) {
    int i;
    for(i=0;i<M->NR;M->rowsi++) {
        if (M->rows[i].nEl == 0)
            printf("<Empty Row>\n");
        else {
            node_t *n = M->rows[i].next;
            while(n != NULL) {
                printf("%f (%d) ", n->f, n->col);
                n = n->next;
            }
            printf("\n");
        }
    }
}

void MATRwrite(matr_t *M, int r, int c, float val) {

    if (r >= M->NR || c >= M->NC)
        return;

    int overwrite = 0;//flag

    if (M->rows[r].nEl == 0) {//M->rows[i].next == NULL
        // First element ever, empty list
        M->rows[r].next = NEWfloatNode(val, c, NULL);
    } else {
        // Sorted insert
        node_t *n = M->rows[r].next, *prev = NULL;
        while(n != NULL && n->col < c) {
            prev = n;
            n = n->next;
        }

        if (n != NULL) {
            // Not in the end(bottom) of the list...
            if (n->col == c) {
                // Overwrite (there already exists one value in that position)
                n->f = val;
                overwrite = 1;
            } else {
                // New node in the middle of the not-empty list...
                if (prev != NULL)
                    prev->next = NEWfloatNode(val, c, n);
                else { //New node in the head of the not-empty list..
                    M->rows[r].next = NEWfloatNode(val, c, n);
                }
            }
        } else {//n==NULL
            // Bottom of the not-empty list
            prev->next = NEWfloatNode(val, c, NULL);
        }

    }
    if (!overwrite) M->rows[r].nEl++;//if overwrite == 0,there is no overwrite happened, one more node was created, so element number increased 1

}

matr_t *MATRinit(int r, int c) {
    int i;
    matr_t * M = malloc(1*sizeof(matr_t));
    if (M == NULL) exit(-1);
    M->NR = r;
    M->NC = c;
    //M->rows
    M->rows = (list_t*)malloc(r *sizeof(list_t));
    if (M->rows == NULL) exit(-1);
    for(i=0;i<r;i++){
        M->rows[i].nEl = 0;
        M->rows[i].next = NULL;
    }

    return M;
}

