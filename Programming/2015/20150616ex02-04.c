#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30+1

typedef struct node {
  int key;
  struct node *right;
  struct node *left;
} node_t;

typedef struct product{
  char name[MAX];
  int price;
  struct product *next;
} product_t;

typedef struct producer{
  char name[MAX];
  product_t *products;
  struct producer *next;
} producer_t;

void mul (int *, int *, int, int **);
void doubleTree (struct node *);
void printTree(struct node *);
void seekV (producer_t *, char *, char *);
void seekO (product_t *, char *, char *);

int main (
   )
{
  // Ex 02
  {
  int i, n = 3;
  int v1[3] = { 2, 3, 9 };//932
  int v2[3] = { 9, 4, 2 };//249
  int* p = NULL;
  mul (v1, v2, n, &p);//&p=pv

  printf ("Mul: ");
  for (i=(n-1); i>=0; i--){
    printf("%d", v1[i]);
  }
  printf(" * ");
  for (i=(n-1); i>=0; i--){
    printf("%d", v2[i]);
  }
  printf(" = ");
  for (i=(2*n-1); i>=0; i--){
    printf ("%d", pv[i]);
  }
  printf ("\n\n");
  }

  // Ex 03
  {
  node_t *root;
  root = (node_t *)malloc(sizeof(node_t));
  root->key = 2;
  root->left = (node_t *)malloc(sizeof(node_t));
  root->right = (node_t *)malloc(sizeof(node_t));
  root->left->key = 1;
  root->left->left = root->left->right = NULL;
  root->right->key = 3;
  root->right->left = root->right->right = NULL;
  printf ("Tree before double tree: ");
  printTree(root);
  doubleTree(root);
  printf ("\n");
  printf ("Tree after  double tree: ");
  printTree(root);
  printf ("\n\n");
  }

  // Ex 04
  {
  char *producers[3] = { "fiat", "bmw", "audi" };
  char *fiat_products[2] = { "ff2", "ff1" };//*fiat_products[2] 代表这fiat是个char*指针 并且有两行
  char *audi_products[2] = { "aa2", "aa1" };
  char *bmw_products[2] = { "bb2", "bb1" };
  char **all_products[3] = { audi_products, bmw_products, fiat_products };
  int i, j, count;

  producer_t *head = NULL;

  count = 0;
  for (i=0; i<3; i++) {
    producer_t *tmp = (producer_t *) malloc (1 * sizeof (producer_t));
    strcpy (tmp->name, producers[i]);

    tmp->next = head;
    tmp->products = NULL;
    head = tmp;
    for (j=0; j<2; j++) {
      product_t *tmp2 = (product_t *) malloc (1 * sizeof (product_t));
      strcpy (tmp2->name, all_products[i][j]);
      tmp2->price = count++;
      tmp2->next = tmp->products;
      tmp->products = tmp2;
    }
  }
  for (i=0; i<3; i++) {
    for (j=0; j<2; j++) {
      printf("Seeking Producer=%5s Product=%5s: ", producers[i], all_products[i][j]);
      seekV (head, producers[i], all_products[i][j]);
    }
  }
  printf ("\n");
  }

#if 0
  {
  int n;
  scanf ("%d", &n);
  }
#endif

  return 0;
}

void mul (
  int *v1,
  int *v2,
  int n,
  int **pv
  )
{
  int *tmp;
  int i, j;
  int current;
//*pv=(int*)malloc((2*n)*sizeof(int));
  tmp = (int *) malloc ((2 * n) * sizeof (int));
  if (tmp == NULL){
    fprintf(stderr, "error allocating");
    exit(-1);
  }
  for (i=0; i<(2*n); i++) {
    tmp[i] = 0;
  }
  for (i=0; i<n; i++){
    current = 0;
    for (j=0; j<n; j++){
      tmp[i + j] = tmp[i + j] + v1[i] * v2[j] + current;
      current = tmp[i + j] / 10;
      tmp[i + j] = tmp[i + j] % 10;
    }
    tmp[i + n] = tmp[i + n]+current;
    //tmp[i + n - 1] += current; Wrong
  }
//pv pointer of pointer
  *pv = tmp;

  return;
}

void doubleTree (
  struct node *root
  )
{
  node_t *tmp;

  if (root == NULL){
    return;
  }
  doubleTree (root->left);
  doubleTree (root->right);

  tmp = (node_t *) malloc (1 * sizeof (node_t));
  if (tmp == NULL) {
    fprintf (stderr, "Allocation error.\n");
    exit (-1);
  }
  tmp->key = root->key;
  tmp->left = root->left;
  tmp->right = NULL;
  root->left = tmp;
  return;
}

void printTree(
  struct node *root
  )
{
  if (root == NULL){
    return;
  }
  printf ("%d ", root->key);
  printTree(root->left);
  printTree(root->right);

  return;
}

void seekV(producer_t *pr, char *prn, char *ptn){
   if (pr == NULL) {
    return;
   }
   if (strcmp(pr->name, prn) > 0) {
    return;
   }
   if (strcmp(pr->name, prn) < 0) {
    seekV(pr->next, prn, ptn);
    return;
   }
   if (strcmp(pr->name, prn) == 0) {
    seekO(pr->products, prn, ptn);
    return;
   }
  printf("seekV error!\n");
  exit(1);
}

void seekO(product_t *pt, char *prn, char *ptn){
  if (pt == NULL) {
    return;
  }
  if (strcmp(pt->name, ptn) > 0) {
    return;
  }
  if (strcmp(pt->name, ptn) < 0) {
    seekO(pt->next, prn, ptn);
    return;
  }
  if (strcmp(pt->name, ptn) == 0) {
    printf("Producer=%5s Product=%5s Price=%d\n", prn, ptn, pt->price);
    return;
  }
  printf("seekO error.\n");
  return;
}

