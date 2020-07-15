#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE  10

typedef struct e {
  int val;
  struct e *next;
}node_t;

void split (node_t **, int, node_t **, node_t **);
void listPrint (node_t *);
node_t *enqueue (node_t *, node_t *);//function to change the linear list into circular list

int main (
  int argc,
  char *argv[]
  )
{
  node_t e1, e2, e3, e4, e5, e6, e7, e8;
  node_t *head, *head1, *head2;
  int threshold;

  //threshold = atoi (argv[2]);//change the second input argument from string to integer
  threshold = 18;

  e1.val=  7; e1.next = &e2;//call the fields of a single structure using '.' instead of '->'(pointer)
  e2.val=  8; e2.next = &e3;
  e3.val= 25; e3.next = &e4;
  e4.val=  2; e4.next = &e5;
  e5.val=  9; e5.next = &e6;
  e6.val= -5; e6.next = &e7;
  e7.val= 10; e7.next = &e8;
  e8.val= 37; e8.next = NULL;
  head = &e1;//Because the pointer of a list is pointing to the first structure of the list, so head=the address of the first structure
  head1 = NULL;//empty list
  head2 = NULL;//empty list

  fprintf (stdout, "--- Ex 02\n");
  fprintf (stdout, "Lists before splitting\n");
  fprintf (stdout, "Printing p : ");
  listPrint (head);
  fprintf (stdout, "Printing p1: ");
  listPrint (head1);
  fprintf (stdout, "Printing p2: ");
  listPrint (head2);
  split (&head, threshold, &head1, &head2);
  fprintf (stdout, "Lists after splitting\n");
  fprintf (stdout, "Printing p : ");
  listPrint (head);
  fprintf (stdout, "Printing p1: ");
  listPrint (head1);
  fprintf (stdout, "Printing p2: ");
  listPrint (head2);

  return (1);
}

void split (
  node_t **p,
  int threshold,
  node_t **p1,
  node_t **p2)
{
  node_t *phead, *tmp, *pTail1, *pTail2;

  pTail1 = NULL;
  pTail2 = NULL;
  phead = *p;

  while (phead!=NULL) { //after phead walks to the last one, phead=NULL and all structures are in the correct position of the new lists
    // Pop                                                //the *p=head=phead = NULL
    tmp = phead;//prev
    phead = phead->next;//in case to lose everything following
    // Enqueue
    if (tmp->val > threshold) {
      pTail1 = enqueue (pTail1, tmp);
    } else {
      pTail2 = enqueue (pTail2, tmp);
    }

  }

  *p = NULL;

  // From circular to linear lists
  if (pTail1!=NULL && pTail1->next!=NULL) { //pTail1 points to the last structure and pTail->next actually points to the first one of the list
    *p1 = pTail1->next; //let the first one become the head of the new list1
    pTail1->next = NULL;//let the last structure point to NULL
  }
  if (pTail2!=NULL && pTail2->next!=NULL) {
    *p2 = pTail2->next;
    pTail2->next = NULL;
  }

  return;
}


// Circular List Implementation
node_t *
enqueue (
  node_t *pTail, //list1
  node_t *p //tmp=7
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
  node_t *head
  )
{
  node_t *p;

  p = head;
  while (p!=NULL) {
    fprintf (stdout, "%d ", p->val);
    p = p->next;
  }
  fprintf (stdout, "\n");

  return;
}

