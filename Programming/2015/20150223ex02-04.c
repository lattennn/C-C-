#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define L1  10
#define L2   5

struct node {
  int key;
  struct node *left;
  struct node *right;
};

void invertSequence (int *, int, int*);

void printPath (struct node *, int, int, struct node **);

void password (char *, int, int *, int *, int);

int
main (
  int argc,
  char *argv[]
  )
{
  // EX 2
  {
    int v1[L1] = {1, 2, 3, 4, 5, 0, 12, 13, 14, 2};
    //int v1[L1] = {1, 2, 3, 4, 5, 0, 12, 13, 14, 15};
    int i, v2[L1];

    invertSequence (v1, L1, v2);
    fprintf (stdout, "v1: ");
    for (i=0; i<L1; i++) {
      fprintf (stdout, "%d ", v1[i]);
    }
    fprintf (stdout, "\n");
    fprintf (stdout, "v2: ");
    for (i=0; i<L1; i++) {
      fprintf (stdout, "%d ", v2[i]);
    }
    fprintf (stdout, "\n");
  }

  // EX 3
  {
    /*
     * Create Fake Tree
     *        0
     *     /     \
     *   10      20
     *    \      /
     *    30    40
     */

    struct node *root, **vet;
    int i;

    root = (struct node *) malloc (1 * sizeof (struct node));
    root->key = 0;
    root->left = (struct node *) malloc (1 * sizeof (struct node));
    root->right = (struct node *) malloc (1 * sizeof (struct node));

    root->left->key = 10;
    root->left->left = NULL;
    root->left->right = (struct node *) malloc (1 * sizeof (struct node));
    root->right->key = 20;
    root->right->left = (struct node *) malloc (1 * sizeof (struct node));
    root->right->right = NULL;

    root->left->right->key = 30;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right->left->key = 40;
    root->right->left->left = NULL;
    root->right->left->right = NULL;

    // Array of pointers to nodes along the path
    vet = (struct node **) malloc (3 * sizeof (struct node *));
    for (i=0; i<=2; i++) {
      vet[i] = NULL;
    }
    printPath (root, 3, 0, vet);
  }

  // EX 4
  {
    int i, n, level, letter[26], digit[10];
    char pass[5];

    for (i=0; i<26; i++) letter[i]=0;
    for (i=0; i<10; i++) digit[i]=0;
    // Max number of Letter/Digit
    n = 1;
    level = 0;

    password (pass, level, letter, digit, n);
  }

  return (1);
}

void
invertSequence (
  int *v1,
  int n,
  int *v2
  )
{
  int i, f, j;

  for (i=0, f=1; f<L1; f++) {
    if (v1[f] <= v1[f-1]) {
      for (j=0; j<(f-i); j++) {
        v2[i+j] = v1[f-j-1];
      }
      i = f;
    }
  }
  // Deal with last sub-sequence
  for (j=0; j<(f-i); j++) {
    v2[i+j] = v1[f-j-1];
  }

  return;
}

void
printPath (
  struct node *root,
  int height,
  int level,
  struct node **vet
  )
{
  int i;

  if (root==NULL) {
     return;
  }

  vet[level] = root;
  printPath (root->left, height, level+1, vet);
  printPath (root->right, height, level+1, vet);

  if (root->left==NULL && root->right==NULL) {
    // This is a leaf
    //OR print from 0 to level (i=0; i<=level; i++)
    fprintf (stdout, "Path: ");
    for (i=0; i<height; i++) {
      if (vet[i]!=NULL) {
        fprintf (stdout, "%d ", vet[i]->key);
      }
    }
    fprintf (stdout, "\n");
    return;
  }

  vet[level] = NULL;

  return;
}

void
password (
  char *pass,//sol
  int level,//pos 0->recursive pos+1
  int *letter,//mark for A-Z --> how many time you already picked
  int *digit,//mark for 0-9
  int n //max repeat times
  )
{
  static int stop = 0, STOP = 1000; // Stop after STOP password
  int i;

  if (level == 5) {
    for (i=0; i<L2; i++) {//L2=5
      fprintf (stdout, "%c", pass[i]);
    }
    fprintf (stdout, "\n");

    stop++;
    if (stop==STOP) exit (1);

    return;
  }

  if (level<3) {
    // Select a letter
    for (i=0; i<26; i++) {
      if (letter[i]<n) {
        letter[i]++;
        pass[level] = (char) (((int) 'a') + i);//A-Z
        password (pass, level+1, letter, digit, n);
        letter[i]--;
      }
    }
  } else {
    // Select a digit
    for (i=0; i<10; i++) {
      if (digit[i]<n) {
        digit[i]++;
        pass[level] = (char) (((int) '0') + i);
        password (pass, level+1, letter, digit, n);
        digit[i]--;
      }
    }
  }


  return;
}

