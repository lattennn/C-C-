/*
 *  StQ 26.01.2016
 *  Exam of the 26.02.2016: Solution of the 12 point exercise
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// et/p=elementType/Pointer, rt/p=rowType/Pointer, mt/p=matrixType/Pointer
struct et {
  int c;
  float val;
  struct et *ep;
};

struct rt {
  int r;
  struct et *ep;
  struct rt *rp;
};

struct mt {
  int row;
  int column;
  struct rt *rp;
};

char *charEraseV1 (char *, int *);
char *charEraseV2 (char *, int *);

void stringSplit (char *, int, int *);
int stringSplitRec (char *, int, int *, char *, int, int);

void msPrint (struct mt);
void msWrite (struct mt *, float, int, int);
void visitRow (struct rt *, float, int);
struct rt *create (float, int, int, struct rt *);

int main (
  )
{
  /* Exercise 1 */
  {
  char str[] = "ThisIsAString";
  int pos[] = {7, 4, 2, 0, 11, -1};
  char *s1, *s2;

  printf ("\n### Ex 01:\n");
  s1 = charEraseV1 (str, pos);
  printf ("version 1: %s\n", s1);
  s2 = charEraseV2 (str, pos);
  printf ("version 2: %s\n", s2);
  free (s1);
  free (s2);
  }

  /* Exercise 2 */
  {
  struct et e1, e2, e3, e4;
  struct rt r1, r2, r3;
  struct mt m;

  // Create Dummy Structure
  e1.c=2; e1.val=12.75; e1.ep=NULL;
  e2.c=0; e2.val=-2.5; e2.ep=&e3;
  e3.c=1; e3.val=3.15; e3.ep=NULL;
  e4.c=4; e4.val=-2.75; e4.ep=NULL;
  r1.r=0; r1.rp=&r2; r1.ep=&e1;
  r2.r=2; r2.rp=&r3; r2.ep=&e2;
  r3.r=3; r3.rp=NULL; r3.ep=&e4;
  m.column=4; m.row=5; m.rp=&r1;

  printf ("\n### Ex 02:\n");
  printf ("Original Matrix:\n");
  msPrint (m);
  msWrite (&m, 33.3, 1, 2);
  msWrite (&m, 3.3, 1, 1);
  msWrite (&m, 333.3, 1, 3);
  msWrite (&m, -27.5, 3, 3);
  printf ("Matrix after Insertions:\n");
  msPrint (m);
  }

  /* Exercise 3 */
  {
  char str[] = "sampleTest";
  int n = 3;
  int length[] = {2, 3, 6};

  printf ("\n### Ex 03:\n");
  stringSplit (str, n, length);
  }

  return (1);
}

/*
 *  Short Code ; Quadratic Cost
 */
char *
charEraseV1 (
  char *str,
  int *pos
  )
{
  char *s;
  int i, j, k;

  s = (char *) malloc ((strlen (str) + 1) * sizeof (char));
  if (s==NULL) {
    fprintf (stderr, "Allocation Error.\n");
    exit (1);
  }
  for (i=k=0; i<strlen(str); i++) {
    for (j=0; pos[j]!=(-1) && pos[j]!=i; j++);//if find pos[j]==i, that one has to be deleted, not put into the new array s[]
    if (pos[j]==(-1)) { //after the whole loop for; the pos[j]==(-1) it means it reached to the end of the pos array but not because pos[j]==i
      s[k] = str[i];  //This str[i] has to be saved into the new array s[]
      k++;
    }
  }
  s[k] = '\0';

  return (s);
}

/*
 *  Long Code ; Linear Cost
 */
char *
charEraseV2 (
  char *str,
  int *pos
)
{
  char *s;
  int i, j;

  s = (char *) malloc ((strlen (str) + 1) * sizeof (char));
  if (s==NULL) {
    fprintf (stderr, "Allocation Error.\n");
    exit (1);
  }
  for (i=0; i<strlen(str)+1; i++)
    s[i] = '1';
  for (i=0; pos[i]!=(-1); i++) {
    s[pos[i]] = '0';
  }
  for (i=j=0; i<strlen(str)+1; i++) {
    if (s[i]=='1') {
      s[j] = str[i];
      j++;
    }
  }

  return (s);
}

void msPrint (
  struct mt m
  )
{
  struct rt *rpt;
  struct et *ept;

  fprintf (stdout, "Number of row: %d\n", m.row);
  fprintf (stdout, "Number of column: %d\n", m.column);
  for (rpt=m.rp; rpt!=NULL; rpt=rpt->rp) {
    fprintf (stdout, "Row: %d -->", rpt->r);
    for (ept=rpt->ep; ept!=NULL; ept=ept->ep) {
      fprintf (stdout, "(c=%d,val=%f)", ept->c, ept->val);
    }
    fprintf (stdout, "\n");
  }

  return;
}

void msWrite (
  struct mt *m,
  float value,
  int row,
  int column
  )
{
  struct rt *rp1;


  //ONLY in the overwrite case,'find that row' we go to the Visitrow function
  rp1 = m->rp;
  if (rp1==NULL || row<rp1->r) { //empty list or we should insert before the first row index-> head
    m->rp = create (value, row, column, rp1);

    return;
  }

  if (rp1->r == row) {           // if the first row is the row we want, direction insert into the column
    visitRow (rp1, value, column);//equal to the case overwrite
  }

  while (rp1->rp!=NULL && rp1->rp->r < row) { //if neither the above two cases, to find the correct row position and to know it's head, middle, or tail
    rp1 = rp1->rp;
  }                       //rp1 go down

  if (rp1->rp == NULL) { //tail
    rp1->rp = create (value, row, column, rp1->rp);
    return;
  }
  if (rp1->rp->r == row) { //overwrite
    visitRow (rp1->rp, value, column);
  } else {
    rp1->rp = create (value, row, column, rp1->rp);  //middle
  }
  return;
}
//The function to create a new row and col index
struct rt *create (
  float value,
  int row,
  int column,
  struct rt *p
  )
{
  struct rt *rp;
  struct et *ep;

  rp = (struct rt *) malloc (sizeof (struct rt));
  ep = (struct et *) malloc (sizeof (struct et));
  if (rp==NULL || ep==NULL) {
    fprintf (stderr, "AllocatioN Erro.\n");
    exit (1);
  }
  rp->r = row;
  rp->rp = p;
  rp->ep = ep;
  ep->c = column;
  ep->val = value;
  ep->ep = NULL;

  return (rp);
}

void
visitRow (
  struct rt *rp, //this input parameter is the first column list-element
  float value,
  int column
  )
{
  struct et *ep1, *ep2;

  ep1 = rp->ep;
  if (ep1==NULL || column<ep1->c) {  //EMPTY or HEAD cases create a new column node
    ep2 = (struct et *) malloc (sizeof (struct et));
    ep2->c = column;
    ep2->val = value;
    ep2->ep = rp->ep;
    rp->ep = ep2;

    return;
  }

  if (ep1->c == column) {  //overwrite
    ep1->val = value;
  }

  while (ep1->ep!=NULL && ep1->ep->c<column) { //find the correct position of ep1->ep, ep1=prev, ep=current OR current->next
    ep1 = ep1->ep;                             //we have to insert into the position between ep1->here->ep
  }

  if (ep1->ep == NULL) {   //estimate the position ep1->ep is the tail
    ep2 = (struct et *) malloc (sizeof (struct et));
    ep2->c = column;
    ep2->val = value;
    ep2->ep = NULL;

    ep1->ep = ep2;
  }
  if (ep1->ep->c == column) { //ep1->ep exist and it's that column, overwrite
    ep1->val = value;
  } else {                    //ep1->ep is in the middle, so ep1->ep2->ep
    // Insert New Element
    ep2 = (struct et *) malloc (sizeof (struct et));
    ep2->c = column;
    ep2->val = value;
    ep2->ep = ep1->ep;

    ep1->ep = ep2;
  }

  return;
}

//allocation function
void stringSplit (
  char *str,
  int n,
  int *length
  )
{
  char *s;
  int i;

  s = (char *) malloc ((strlen (str) + 1) * sizeof (char));
  if (s==NULL) {
    fprintf (stderr, "Allocation Error.\n");
    exit (1);
  }
  for (i=0; i<strlen(str); i++) { //max length of the solution should be strlen(str) because the split length can be 1 1 1 1 1
    s[i] = 0;
  }
  stringSplitRec (str, n, length, s, 0, 0);

  return;
}
//recursion function
int stringSplitRec (
  char *str,
  int n,
  int *length,
  char *res,//save the picked length from the length array
  int ind,//like pos or level parameter
  int len
  //int *f // main -> &flag
  )
{
  int i, j, k;

  // Termination with no solution
  if (len>strlen (str)) {
    return (0);
  }

  // Termination with a solution
  if (len==strlen (str)) { // NOT k or n here
    for (i=k=0; i<ind; i++) { //ind saves-> how many lengths did we pick, so we can get our solution by res[i] -->pos in the recursion
      for (j=0; j<res[i]; j++) { //j counts for one res[i], if res[i]=2 it means we have a splited substring with length 2, j will be counted 0,1 ->2 times
        fprintf (stdout, "%c", str[k])//should is the one goes through every element, when we need to split and copy each character
        k++;                          //so after copy it, k++
      }
      fprintf (stdout, " ");   //before the big for i++, we have to print ' ', because j goes for one split, and i++, it will go to another split
    }
    //*f = 1;//flag=1;
    fprintf (stdout, "\n");
    return (1);
  }

  // Try to use all lengths, so the range of i is 0 to n-1, n is given by the question as the total number of the length-choices
  for (i=0; i<n; i++) {
    res[ind] = length[i];
#if 1
/*
     *  Enable the following 2 lines
     *  to have only ONE solution
     */
    if (stringSplitRec (str, n, length, res, ind+1, len+length[i]))
      return (1);//SINGLE solution
#else

    /*
     *  Enable the following 2 lines
     *  to have ALL solutions
     */
    stringSplitRec (str, n, length, res, ind+1, len+length[i]);
#endif

   }
  return (0);
}
