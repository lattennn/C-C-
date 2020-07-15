#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define OK    0
#define KO    1
#define N     3

struct node {
  int key;
  struct node *child[N];
  //struct node **child;
};

void eraseDuplicate (char *);

void visitLevelByLevel (struct node *, int, int);
void visit (struct node *, int, int);

void readFile (FILE *, char ***, int *);
void play (FILE *, char **, int, char *, int);

int
main (
  int argc,
  char *argv[]
)

{
  // EX 2
  {
    char str[MAX];
    //char *str
    int a;

    fprintf (stdout, "Input string: ");
    scanf ("%s", str);
    scanf("%d",&a);
    eraseDuplicate (str);
    fprintf (stdout, "Output string: %s\n", str);

  }

  // EX 3
  {
    // Create Fake Tree
    struct node *root;

    root = (struct node *) malloc (1 * sizeof (struct node));
    root->key = 0;
    root->child[0] = (struct node *) malloc (1 * sizeof (struct node));
    root->child[1] = (struct node *) malloc (1 * sizeof (struct node));
    root->child[2] = (struct node *) malloc (1 * sizeof (struct node));
    root->child[0]->key = 10;
    root->child[1]->key = 12;
    root->child[2]->key = 14;
    root->child[0]->child[0] = NULL;
    root->child[0]->child[1] = NULL;
    root->child[0]->child[2] = NULL;
    root->child[1]->child[0] = NULL;
    root->child[1]->child[1] = NULL;
    root->child[2]->child[2] = NULL;
    root->child[2]->child[0] = NULL;
    root->child[2]->child[1] = NULL;
    root->child[2]->child[2] = (struct node *) malloc (1 * sizeof (struct node));
    root->child[2]->child[2]->key = 16;
    root->child[2]->child[2]->child[0] = NULL;
    root->child[2]->child[2]->child[1] = NULL;
    root->child[2]->child[2]->child[2] = NULL;

    visitLevelByLevel (root, 2, 3);
  }


  // EX 4
  {
    FILE *fpR, *fpW;
    int n;
    char name1[MAX], name2[MAX], **mat, *vet;

    fprintf (stdout, "NameI NameO: ");
    scanf ("%s %s", name1, name2);
    fpR = fopen (name1, "r");
    fpW = fopen (name2, "w");
    if (fpR==NULL || fpW==NULL) {
      fprintf (stderr, "Error opening file.\n");
      exit (KO);
    }

    readFile (fpR, &mat, &n);

    vet = (char *) malloc (n * sizeof (char));
    if (vet == NULL) {
      fprintf (stderr, "Allocation error.\n");
      return (KO);
    }
    play (fpW, mat, n, vet, 0);

    fclose (fpR);
    fclose (fpW);
  }

  return (OK);
}

void
eraseDuplicate (
  char *str;
  )
{
  int i, j, k;

  for (i=0; str[i]!='\0'; i++) {
    for (j=i+1; str[j]!='\0'; j++) {
      if (str[i]==str[j]) {
        for (k=j; str[k]!='\0'; k++) {
          str[k] = str[k+1];
        }//a;;;bbbb\0
        j--;
      }
    }
  }
}

void readFile (
  FILE *fp,
  char ***mat,
  int *n
)
{
  int i, j;
  char **tmp, s[MAX];

  if (fscanf (fp, "%d", n) == EOF) {//没有&因为n就是指针
    fprintf (stderr, "File error.\n");
    return;
  }

  tmp = (char **) malloc (*n * sizeof (char *));
  if (tmp == NULL) {
    fprintf (stderr, "Allocation error.\n");
    return;
  }

  i = 0;
  while (fscanf (fp, "%s", s) != EOF && i<(*n)) {// i read rows, j reads columns
    tmp[i] = (char *) malloc ((strlen(s)+2) * sizeof (char *));
    if (tmp[i] == NULL) {
      fprintf (stderr, "Allocation error.\n");
      return;
    }
    tmp[i][0] = strlen (s);
    for (j=0; j<strlen (s); j++) {
      tmp[i][j+1] = s[j];
    }
    i++;
  }

  *mat = tmp;

  return;
}

void
play (
  FILE *fp,
  char **mat,
  int n,
  char *vet,
  int level
  )
{
  int i;

  if (level == n) {
    for (i=0; i<n; i++) {
      fprintf (fp, "%c", vet[i]);
    }
    fprintf (fp, "\n");
    return;
  }

  for (i=1; i<=((int) mat[level][0]); i++) {
    vet[level] = mat[level][i];
    play (fp, mat, n, vet, level+1);//level++ wrong
  }

  return;
}

void
visitLevelByLevel (
  struct node *root,
  int l1,
  int l2
)
{
  int i;

  for (i=l1; i<=l2; i++) {
    fprintf (stdout, "Level %d: ", i);
    visit (root, i, 1);
    fprintf (stdout, "\n");
  }

  return;
}

void
visit (
  struct node *root,
  int level,//要求打印数的层
  int l   //在树里递归的层数
  )
{
  int i;

  if (root==NULL)
    return;

  if (l == level) {
    fprintf (stdout, "%d ", root->key);
    return;
  }

  for (i=0; i<N; i++) {
    visit (root->child[i], level, l+1);
  }
  //visit(root->child[0],level,l+1);
  //visit(root->child[1],level,l+1);
  //visit(root->child[2],level,l+1);


  //assume there are just two children
  //visit(root->left,level,l+1); visit(root->child[0],level,l+1);
  //visit(root->right,level,l+1); visit(root->child[1],level,l+1);
  return;
}
