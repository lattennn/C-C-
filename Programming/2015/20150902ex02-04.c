/*
 *  StQ 02.09.2015
 *  A&P Exam
 *  Solution of exercizes # 2, 3, 4
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

typedef struct node {
  int key;
  struct node *right;
  struct node *left;
} node_t;

void chess (int [4][4], int);
int treeIsomorph (struct node *, struct node *);
void treePrint (struct node *);
void path (int [3][3], int, int, int, int [3][3], int [3][3], int *, int, int *, int);
void matPrint (int [3][3], int);
void matCopy (int [3][3], int [3][3], int);

int main (
   )
{
  // Ex 02
  {
  int mat[4][4] =
    {{ 0, 3, 4, 0},
     { 1, 0, 6, 6},
     { 1, 3, 9, 0},
     { 0, 0, 3, 1}};

  chess (mat, 4);

  fprintf (stdout, "\n");
  }

  // Ex 03
  {
  int retVal;
  node_t *r1, *r2;

  r1 = (node_t *)malloc(sizeof(node_t));
  r1->key = 2;
  r1->left = (node_t *)malloc(sizeof(node_t));
  r1->right = (node_t *)malloc(sizeof(node_t));
  r1->left->key = 1;
  r1->left->left = r1->left->right = NULL;
  r1->right->key = 3;
  r1->right->left = r1->right->right = NULL;

  r2 = (node_t *)malloc(sizeof(node_t));
  r2->key = 2;
  r2->left = (node_t *)malloc(sizeof(node_t));
  r2->right = (node_t *)malloc(sizeof(node_t));
  r2->left->key = 1;
  r2->left->left = r2->left->right = NULL;
  r2->right->key = 4;
  r2->right->left = r2->right->right = NULL;

  fprintf (stdout, "Tree r1: ");
  treePrint (r1);
  fprintf (stdout, "\n");
  fprintf (stdout, "Tree r2: ");
  treePrint (r2);
  fprintf (stdout, "\n");

  retVal = treeIsomorph (r1, r1);
  if (retVal==1)
    fprintf (stdout, "Tree r1 and r1 ARE Isomorph!\n");
  else
    fprintf (stdout, "Tree r1 and r1 are NOT Isomorph!\n");

  retVal = treeIsomorph (r1, r2);
  if (retVal==1)
    fprintf (stdout, "Tree r1 and r2 ARE Isomorph!\n");
  else
    fprintf (stdout, "Tree r1 and r2 are NOT Isomorph!\n");

  fprintf (stdout, "\n");
  }

  // Ex 04
  {
  int mat[3][3] =
    {{ 1, 2, -3},
     { 9, -9, 7},
     { 0, 1, 4}};
  int visitedBest[3][3] =
    {{ 0, 0, 0},
     { 0, 0, 0},
     { 0, 0, 0}};
  int visited[3][3] =
    {{ 0, 0, 0},
     { 0, 0, 0},
     { 0, 0, 0}};
  int pathSumMax = 0,
      pathLenMax = 0;

  path (mat, 3, 0, 0, visitedBest, visited, &pathSumMax, 0, &pathLenMax, 0);
  fprintf (stdout, "Path:\n");
  matPrint (visitedBest, 3);
  fprintf (stdout, " sum max = %d\n length max = %d\n",
    pathSumMax, pathLenMax);

  fprintf (stdout, "\n");
  }

  return 0;
}

void chess (
  int mat[4][4],
  int n
  )
{
  int r, c, rr, cc;
  int sum, max, rBest, cBest;

  max = rBest = cBest = (-1);
  for (r=0; r<n; r++) {
    for (c=0; c<n; c++) {
      if (mat[r][c]==0) {
        sum = 0;
        for (rr=r, cc=c; rr>=0 && cc>=0; rr--, cc--) {//left up
          sum += mat[rr][cc];
        }
        for (rr=r, cc=c; rr>=0 && cc<n; rr--, cc++) {//right up
          sum += mat[rr][cc];
        }
        for (rr=r, cc=c; rr<n && cc>=0; rr++, cc--) {//left down
          sum += mat[rr][cc];
        }
        for (rr=r, cc=c; rr<n && cc<n; rr++, cc++) {//right down
          sum += mat[rr][cc];
        }

        if (sum>max) {
          max = sum;
          rBest = r;
          cBest = c;
        }
      }
    }
  }

  fprintf (stdout, "Bishop coordinates (%d, %d) sum (%d) \n", rBest, cBest, max);

  return;
}

int treeIsomorph (
  struct node *t1,
  struct node *t2
  )
{
  if (t1==NULL && t2==NULL){
    return (1);
  }
  if (t1==NULL && t2!=NULL){
    return (0);
  }
  if (t1!=NULL && t2==NULL){
    return (0);
  }

  if (t1->key!=t2->key){//strcmp(t1->string,t2->string)!=0
    return (0);
  }
  if (!treeIsomorph (t1->left, t2->left)) {
    return (0);
  }
  if (treeIsomorph (t1->right, t2->right) == 0) {
    return (0);
  }
  return (1);
}

void treePrint (
  struct node *root
  )
{
  if (root == NULL){
    return;
  }
  printf ("%d ", root->key);
  treePrint (root->left);
  treePrint (root->right);

  return;
}

void path (
  int mat[3][3],
  int matSize,
  int r,
  int c,//current ccordination
  int visitedBest[3][3],//best sol
  int visited[3][3],//current sol //mark
  int *pathSumMax,//updated in termination
  int pathSumCurrent,//updated during recursions
  int *pathLenMax,//updated in termination
  int pathLenCurrent//updated during recursions
  )
{
  int dx[8] = {-1, -1, -1, 0, 0, +1, +1, +1};
  int dy[8] = {-1, 0, +1, -1, +1, -1, 0, +1};

  int i, v1, v2;

//Three terminations

//out of the dimension
//already been here once
//reach to the destination of the question

  if (r<0 || r>=matSize || c<0 || c>=matSize) { //0 matSize-1
    return;
  }

  if (visited[r][c]>0) { //already been here once
    return;
  }

  if (r==(matSize-1) && c==(matSize-1)) {

#if DEBUG
    matPrint (visited, matSize);
    fprintf (stdout, " --> %d %d\n", v1, v2);
#endif

      v1 = pathSumCurrent + mat[r][c];
      v2 = pathLenCurrent + 1;
      //here we reach the destination
      //if the path sum is max OR the path sum is the same but path length is smaller ! UPDATE the best solution
    if ( (v1> *pathSumMax) || (  (v1==*pathSumMax) && (v2<*pathLenMax)  ) ) {
#if DEBUG
      fprintf (stdout, "  --> NEW BEST\n");
#endif

      *pathSumMax = v1;//we need to use the pointer to remember the number because MAIN function wants to know
      *pathLenMax = v2;
      matCopy (visitedBest, visited, matSize);//copy the current solution into the best solution, copy the matrix
      visitedBest[r][c] = *pathLenMax;//The last cell, last step one hasn't put the value into the path-mark-matrix
    }

    return;
  }

  //Every intermediate step should do this, update the current solution with the current-sum, current path length
  v1 = pathSumCurrent + mat[r][c]; //v1 current sum
  v2 = pathLenCurrent + 1;         //v2 current path-length

  visited[r][c] = v2;//stamp every step number i.e'path length' in the matrix at the point index

  for (i=0; i<8; i++) {                             //下一个递归的sumcurrent=v1=pathSumCurrent + mat[r][c]; 下个current path length=v2=pathLenCurrent + 1
      path (mat, matSize, r+dx[i], c+dy[i], visitedBest, visited, pathSumMax, v1, pathLenMax, v2);
  }

  visited[r][c] = 0;////out of the for loop cause for every point r,c it moves 8 directions and when all directions recur finish ,track back and this r,c empty!

  return;
}

void matPrint (
  int mat[3][3],
  int n
  )
{
  int r, c;

  for (r=0; r<n; r++) {
    for (c=0; c<n; c++) {
      fprintf (stdout, "%d ", mat[r][c]);
    }
    fprintf (stdout, "\n");
  }

  return;
}

void matCopy (
  int m1[3][3],
  int m2[3][3],
  int n
  )
{
  int r, c;

  for (r=0; r<n; r++) {
    for (c=0; c<n; c++) {
      m1[r][c] = m2[r][c];
    }
  }

  return;
}

