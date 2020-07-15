#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define N 20

typedef struct node_ {
  char *name;
  char *surname;
  struct node_ *next;
  struct node_ *prev;
}node;

typedef struct lista_ {
  int numEl;
  node *head;
  node *tail;
} lista;

//find \(-name h* -or -name *i \) -exec mv {} comeon \;


lista *listaINIT() {//initialization
  lista *l;
  l = (lista *)malloc(1 * sizeof(lista));
  if (l == NULL)
    exit(-1);

  l->numEl = 0;//number of structures in the list
  l->head = NULL;
  l->tail = NULL;

  return l;

}

node *nodeINIT(char *nm, char *cg) {//node initialization
  node *n;
  n=(node*)malloc(1 * sizeof(node));
  if (n == NULL)
    exit(-1);
  //n->name = strdup(nm);
//n->name char*
  n->name = (char*)malloc((strlen(nm)+1)*sizeof(char));
  strcpy(n->name,nm);

  n->surname = strdup(cg); //string duplicate //dynamically allocated and copy

  n->next = NULL;
  n->prev = NULL;
  return n;
}

void seeList(lista *L) {
  node *tmp = L->head;
  while(tmp != NULL) {
    printf("%s %s\n", tmp->surname, tmp->name);
    tmp = tmp->next;
  }
  printf("-----------------\n");
}

int orderInsert(lista *L, char *nm, char *cg) {
  node *n = nodeINIT(nm, cg);//initialization
  node *l,*r;//temp

  if (L->head == NULL) { // equivalente L->numEl == 0 empty list
    L->head = L->tail = n;
    L->numEl++;
  } else {// not empty case ->insert head, middle,tail,overwrite

    node *tmp = L->head;

    while(tmp != NULL && strcmp(cg, tmp->surname) > 0) {// if cg < = tmp->surname EXIT
      tmp = tmp->next;
    }
    while(tmp != NULL && !strcmp(cg, tmp->surname) && strcmp(nm, tmp->name) > 0) {
      tmp = tmp->next;
    }
//find the correct tmp, to tell the pos of tmp

    if (tmp != NULL && !strcmp(tmp->name, nm) && !strcmp(tmp->surname, cg)) {//overwrite
      printf("ALERT ! Replica > %s %s\n", cg, nm);
      return 0;
    }


    //Finished finding the right position 'tmp' before to insert here, newnode->next=tmp

    if (tmp == L->head) {//head
      n->next = tmp;
      tmp->prev = n;
      L->head = n;
    }

    else if (tmp == NULL) {//tail
      n->prev = L->tail;
      L->tail->next = n;
      L->tail = n;
    }

    else {     //orderInsert        //middle
      n->next = tmp;
      n->prev = tmp->prev;//先把新的点先接入到list里，再去改变原来list的点的指针
      n->prev->next = n;
      tmp->prev = n;
    }
    L->numEl++;
  }

  seeList(L);
  return 1;
}



int main(int argc, char **argv) {

  lista *L;
  int flag;
  L = listaINIT();//init = initial
  if(orderInsert(L, "mario", "rossi")){//return 1 ->true
    printf("successful inserted!");//..................
  }

  flag=orderInsert(L, "mario", "bianchi");
  if(flag==1) printf("Success!\n");
  flag=orderInsert(L, "wario", "bianchi");
  if(flag==1) printf("Success!\n");
  flag=orderInsert(L, "wario", "rossi");
  if(flag==1) printf("Success!\n");
  flag=orderInsert(L, "wario", "rossi");
  if(flag==1) printf("Success!\n");
  flag=orderInsert(L, "wario", "grossi");
  if(flag==1) printf("Success!\n");
  flag=orderInsert(L, "lario", "grossi");
  if(flag==1) printf("Success!\n");
  flag=orderInsert(L, "ario", "rossi");
  if(flag==1) printf("Success!\n");
  flag=orderInsert(L, "dario", "fossi");
  if(flag==1) printf("Success!\n");
  flag=orderInsert(L, "dario", "tossi");
  if(flag==1) printf("Success!\n");

  return 0;
}
