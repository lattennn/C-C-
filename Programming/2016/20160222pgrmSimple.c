/*
 *  StQ 22.02.2016
 *  Algorithms and Programming
 *  Exam of the 22.02.2016
 *  Solutions for the 12 point exercises
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE  10
#define EMPTY  0
#define FULL   1

#define NS  4
#define NB  5

struct e {
  int val;
  struct e *next;
};

int area (FILE *);

void split (struct e **, int, struct e **, struct e **);
void listPrint (struct e *);
struct e *enqueue (struct e *, struct e *);

void switchAndBulb (int [][NB], int, int, int *, int *, int *, int);

int main (
  int argc,
  char *argv[]
  )
{
  /* Exercise 1 */
  {
  FILE *fp;

  fp = fopen (argv[1], "r");
  if (fp==NULL) {
    fprintf (stderr, "Opening File Error.\n");
    exit (1);
  }

  fprintf (stdout, "--- Ex 01\n");
  fprintf (stdout, "area: %d\n", area (fp));

  fclose (fp);
  }

  /* Exercise 2 */
  {
  struct e e1, e2, e3, e4, e5, e6, e7, e8;
  struct e *p, *p1, *p2;
  int threshold;

  threshold = atoi (argv[2]);

  e1.val=  7; e1.next = &e2;
  e2.val=  8; e2.next = &e3;
  e3.val= 25; e3.next = &e4;
  e4.val=  2; e4.next = &e5;
  e5.val=  9; e5.next = &e6;
  e6.val= -5; e6.next = &e7;
  e7.val= 10; e7.next = &e8;
  e8.val= 37; e8.next = NULL;
  p = &e1;
  p1 = NULL;
  p2 = NULL;

  fprintf (stdout, "--- Ex 02\n");
  fprintf (stdout, "Lists before splitting\n");
  fprintf (stdout, "Printing p : ");
  listPrint (p);
  fprintf (stdout, "Printing p1: ");
  listPrint (p1);
  fprintf (stdout, "Printing p2: ");
  listPrint (p2);
  split (&p, threshold, &p1, &p2);
  fprintf (stdout, "Lists after splitting\n");
  fprintf (stdout, "Printing p : ");
  listPrint (p);
  fprintf (stdout, "Printing p1: ");
  listPrint (p1);
  fprintf (stdout, "Printing p2: ");
  listPrint (p2);
  }

  /* Exercise 3 */
  {
  int nBest = NS+1;//or you can define a very big number for that it should be exchange(changed) value
  int mat[NS][NB] = {{1, 1, 1, 0, 1},
                     {1, 0, 1, 0, 0},
                     {0, 1, 1, 1, 0},
                     {0, 0, 0, 1, 0},
                    };
  int switchBest[NS] = {0, 0, 0, 0};
  int switchCurrent[NS] = {0, 0, 0, 0};
  int i;

  switchAndBulb (mat, NS, NB, &nBest, switchBest, switchCurrent, 0);

  fprintf (stdout, "--- Ex 03\n");
  if (nBest>NS) {
    fprintf (stdout, "No solution found.\n");
  } else {
    fprintf (stdout, "Solution found.\n");
    fprintf (stdout, "%d Switches on -> ", nBest);
    for (i=0; i<NS; i++) {
      if (switchBest[i]==1)
        fprintf (stdout, "%d ", i);
    }
    fprintf (stdout, "\n");
    }
  }

  return (1);
}

int
area (
  FILE *fp
)
{
  int mat[SIZE][SIZE], count;
  int x1, x2, y1, y2, r, c;

  for (r=0; r<SIZE; r++) {
    for (c=0; c<SIZE; c++) {
      mat[r][c] = EMPTY;
    }
  }

  while (fscanf (fp, "%d%d%d%d", &x1, &y1, &x2, &y2) != EOF) {
    if (x1<0 || x1>SIZE || y1<0 || y1>SIZE ||
        x2<0 || x2>SIZE || y2<0 || y2>SIZE) {
      fprintf (stderr,
        "Skipping rectangle out of bound (%d,%d,%d,%d).\n",
        x1, y1, x2, y2);
      continue;
    }
    for (r=x1; r<x2; r++) {
      for (c=y1; c<y2; c++) {
        mat[r][c] = FULL;
      }
    }
  }

  count = 0;
  for (r=0; r<SIZE; r++) {
    for (c=0; c<SIZE; c++) {
      if (mat[r][c] == FULL) {
        count++;
      }
    }
  }

  return (count);
}

void split (
  struct e **head,
  int threshold,
  struct e **head1,
  struct e **head2)
{
  struct e *p, *tmp, *pTail1, *pTail2;
  pTail1 = NULL;
  pTail2 = NULL;
  p = *head;
  while (p!=NULL) {
    // Pop
    tmp = p;
    p = p->next;
    // Enqueue
    if (tmp->val > threshold) {
      pTail1 = enqueue (pTail1, tmp);
    } else {
      pTail2 = enqueue (pTail2, tmp);
    }
  }

  *head = NULL;

  // From circular to linear lists
  if (pTail1->next!=NULL) {
    *head1 = pTail1->next;
    pTail1->next = NULL;
  }
  if (pTail2->next!=NULL) {
    *head2 = pTail2->next;
    pTail2->next = NULL;
  }

  return;
}


// Circular List Implementation
struct e *
enqueue (
  struct e *pTail,
  struct e *p
  )
{
  if (pTail==NULL) {
    pTail = p;
    pTail->next = p;
 } else {
    p->next = pTail->next;
    pTail->next = p;
    pTail = p;
  }

  return (pTail);
}



void
listPrint (
  struct e *head
  )
{
  struct e *p;

  p = head;
  while (p!=NULL) {
    fprintf (stdout, "%d ", p->val);
    p = p->next;
  }
  fprintf (stdout, "\n");

  return;
}


void switchAndBulb (
  int mat[NS][NB],
  int ns,//Number of Switches
  int nb,//Number of Bulbs
  int* nBest,//pointer of integer
  int switchBest[NS],//bestsol
  int switchCurrent[NS],//sol
  int level//pos = 0
  )
{
  int i, j, c, n, flag;

  // Termination
  if (level==ns) {//for every switch, we have decided to take it or not--> 1/0
    flag = 1;
    for (i=0; i<nb && flag==1; i++) {//loop for bulbs, if flag==0, there is one bulb that cannot be lighted.
      c = 0;//sum should be an odd number for each i, so c=0 for each i before the j loop(for switches in the current solution)
      for (j=0; j<ns; j++) {//loop for switches
        if (switchCurrent[j]==1) {//sol
          c = c + mat[j][i];
        }
      }              //after the loop for all switches we pick (in the solution),for this 'i' bulb, estimate that c is odd
      if ((c%2)==0) {//if there is just one bulbs is off
        flag = 0;//flag = 0 it will get out of this loop and return to last recursion function
      }
    }
    if (flag==1) {//when all bulbs are on together
      n = 0;
      for (j=0; j<ns; j++)  //for loop,j is inside dimension of switches
        n = n + switchCurrent[j]; //we put 1 into the solution to mark the switch is taken or not, so sum them up, it's the number of the switches we picked
      //n=3
      if (n < *nBest) {
        *nBest = n;
        for (i=0; i<ns; i++) {
          switchBest[i] = switchCurrent[i];
        }
      }
    }
    return;
}

  // Set All Switches
  switchCurrent[level] = 0;
  switchAndBulb (mat, ns, nb, nBest, switchBest, switchCurrent, level+1);
  switchCurrent[level] = 1;
  switchAndBulb (mat, ns, nb, nBest, switchBest, switchCurrent, level+1);

  return;
}
