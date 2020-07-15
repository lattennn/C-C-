#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define NA 4
#define NB 6
#define NC 2

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void random_sorted_vect(int *v, int len) {
  srand (time(NULL));
  int i;
  for(i=0;i<len;i++) v[i] = rand() % 100;
  qsort (v, len, sizeof(int), compare);
}

int *merge3 (int *a, int *b, int *c, int na, int nb, int nc) {
  int tot = na+nb+nc;
  int *d = calloc(tot, sizeof(int));
  int i, ia =0, ib=0, ic=0;
  for(i=0;i<tot;i++) {
    if (ia <na && ib < nb && ic < nc) {
      if (a[ia] < b[ib])
        d[i] = a[ia] < c[ic] ? a[ia++] : c[ic++];
      else {
        d[i] = b[ib] < c[ic] ? b[ib++] : c[ic++];
      }
    } else if(ia < na && ib < nb){
      d[i] = a[ia] < b[ib] ? a[ia++] : b[ib++];
    } else if(ia < na && ic < nc){
      d[i] = a[ia] < c[ic] ? a[ia++] : c[ic++];
    } else if(ib < nb && ic < nc){
      d[i] = b[ib] < c[ic] ? b[ib++] : c[ic++];
    } else if(ia < na ){
      d[i] =  a[ia++];
    } else if(ib < nb ){
      d[i] =  b[ib++];
    } else if(ic < nc ){
      d[i] =  c[ic++];
    }
  }
  return d;
}

print_v(int*v, int len) {
  int i;
  for(i=0;i<len;i++) printf("%d ", v[i]);
  printf("\n");
}

int main(int argc, char **argv) {
  int na = NA, nb = NB, nc = NC;
  int a[NA], b[NB], c[NC], *d;
  random_sorted_vect(a, na);
  random_sorted_vect(b, nb);
  random_sorted_vect(c, nc);
  d = merge3(a,b,c,na,nb,nc);
  print_v(a,na);
  print_v(b,nb);
  print_v(c,nc);
  print_v(d,na+nb+nc);
  return 0;
}
