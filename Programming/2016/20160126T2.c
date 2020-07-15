//20160126 T2


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// et/p=elementType/Pointer
// rt/p=rowType/Pointer
// mt/p=matrixType/Pointer

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



void msPrint (struct mt);
void msWrite (struct mt *, float, int, int);
void visitRow (struct rt *, float, int);
struct rt *create (float, int, int, struct rt *);



int main ( )
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



void msPrint (struct mt m)
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

void msWrite (struct mt *m, float value, int row, int column )
{
  struct rt *rp1;

  rp1 = m->rp;
  if (rp1==NULL || row<rp1->r) {//empty list && head
    m->rp = create (value, row, column, rp1); //headrp=m->rp
    return;                                   //  |
  }                                           // rp1

  if (rp1->r == row) {//insert rp1=m->rp
    visitRow (rp1, value, column);
  }

  while (rp1->rp!=NULL && rp1->rp->r <row) {//If you don't want to use the prev pointer, you can do in this way
    rp1 = rp1->rp;//next vertically
  }

  if (rp1->rp == NULL) {//tail
    rp1->rp = create (value, row, column, rp1->rp);
    return;
  }
  if (rp1->rp->r == row) {//overwrite
    visitRow (rp1->rp, value, column);
  } else {   //middle
    rp1->rp = create (value, row, column, rp1->rp);
  }  //rp1 -> newnode -> (rp1->rp)
  return;
}

struct rt *create ( //new row + new col
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
  struct rt *rp,
  float value,
  int column
  )
{                                     //
  struct et *ep1, *ep2;//ep1用来标记位置 找位置 ep2用来产生新的点

  ep1 = rp->ep;//传进来的rp 是row index那个结构体 它要rp->ep 才是那一行list的head
  if (ep1==NULL || column<ep1->c) { //empty row or insert before the first column
    ep2 = (struct et *) malloc (sizeof (struct et));
    ep2->c = column;
    ep2->val = value;
    ep2->ep = rp->ep;//这个rp->ep就是rp->listhead//rp->listhead->listnode(2)->listnode(3)
    rp->ep = ep2;//新的rp->listhead是这个新生的ep2

    return;
  }

  if (ep1->c == column) {
    ep1->val = value;  //first one overwrite
  }//ep1 is listhead 是rp->ep

  while (ep1->ep!=NULL && ep1->ep->c<column) {//column < = ep1->ep->c
    ep1 = ep1->ep;  //find the position ep1-> 插入 ->(ep1->ep)
  }

  if (ep1->ep == NULL) {  //tail ep1-> 后插入为空
    ep2 = (struct et *) malloc (sizeof (struct et));
    ep2->c = column;
    ep2->val = value;
    ep2->ep = NULL;

    ep1->ep = ep2;
  }

  if (ep1->ep->c == column) {    // middle overwrite ep1-> 后一列就是这一列 插入
    ep1->ep->val = value;
  } else {
    // Insert New Element        //in the middle & head of ep1->ep 也就是ep1->new->(ep1->ep)
    ep2 = (struct et *) malloc (sizeof (struct et));
    ep2->c = column;
    ep2->val = value;
    ep2->ep = ep1->ep;
                           //ep1->ep2-> (ep1->ep)
    ep1->ep = ep2;
  }

  return;
}



