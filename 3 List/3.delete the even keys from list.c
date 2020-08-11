#include <stdio.h>
#include <stdlib.h>

//search,change,insert,delete->delete
//增 删 查 改 里的 删

typedef struct node
{
    int key;
    struct node *next;
} node_t;


void printList(node_t *head)
{
    if(head==NULL)
        return;

    printf("%d ", head->key);//顺着打印出来
    printList(head->next);
}

//Generally we use this method, recursively
node_t* deleter1(node_t *head)
{
    node_t *temp;
    if(head == NULL)
        return NULL;//return;-->void
// temp->9->7->5->3->1->NULL
    head->next = deleter1(head->next);

    if((head->key)%2==0){
        temp = head->next; //temp->9->7->5->3->1->NULL
        free(head);
        return temp;
    }
    return head;
}

//stupid, iteratively (just ok for this case 10 9 8 7 6 5 4 3 2 1)
node_t* deleter2(node_t* head)
{
    node_t *c,*current,*prev=NULL;
    if(head==NULL)
        return NULL;

    if((head->key)%2==0){
        current=head;
        head=head->next;
        free(current);
    }

    c=head;
    while(c!=NULL){
     if((c->key)%2==0){
        current=c;
        prev->next=c->next;//为了让他们连接在以上，上课的时候漏写了这行。
        c=c->next;
        free(current);
      }
      else{ //一定要写else 这里
         prev = c;
         c = c->next;
      }
    }
    return head;
}

// Delete the node whose key is equal to n(even)
/*node_t* deleter(node_t *head, int n)
{
    node_t *temp;
    if(head == NULL)
        return NULL;//return ;-->void

    head->next = deleter(head->next, n);
    if(head->key == n){
        temp = head->next;
        free(head);
        return temp;
    }
    return head;
}*/

//head->5->3->1->NULL delete the nodes with value>5
void deleter3(node_t** h){ // h=&head
    node_t *head,*prev,*current;

    prev=NULL;
    head=(*h);
    current=head;

    while(current!=NULL){
        if(current->key > 5){
            if(prev==NULL){//delete the head node
                head=current->next;
                free(current);
                current=head;
            }
            else{    //delete the middle nodes
                prev->next=current->next;
                free(current);
                current=prev->next;
            }
            continue;
        }

        prev=current;
        current=current->next;
    }

    *h=head;

}
/*
    while(head!=NULL){
        if(head->key > 5){
            if(prev==NULL){//delete the head node
                (*h)=head->next;
                free(head);
                head=(*h);
            }
            else{    //delete the middle nodes
                prev->next=head->next;
                free(head);
                head=prev->next;
            }
            continue;
        }
        prev=head;
        head=head->next;
    }*/

int main()
{
    int n;
    node_t *head, *current,*temp;
    head = NULL;
    n = 1;

    for(n=0; n<=10; n++)
    {
        current = (node_t*) malloc(sizeof(node_t));
        current->key = n;
        current->next = head;
        head = current;
    } // head->10->9->8->7->....->1->0

    printf("Original list:\n");
    printList(head);
    printf("\nDeleting...\n");

    head=deleter1(head); //head->9->7->5->3->1->NULL
    printList(head);
    printf("\nDeleting the numbers with value > 5");
    deleter3(&head);//void deleter3(node_t** h);delete numbers with value > 5
 /*   for(n=0; n<=10; n+=2){
        head = deleter(head, n);
    }
*/
    printf("\nFinal result by Recursion:\n");
    printList(head);

//Free the whole list memory
    while(head!=NULL){
        current=head;
        head=head->next;
        free(current);
    }

//Build the list again
    for(n=0; n<=10; n++)
    {
        current = (node_t*) malloc(sizeof(node_t));
        current->key = n;
        current->next = head;
        head = current;
    }

    head=deleter2(head);
    printf("\nFinal result by Iteration:\n");
    printList(head);
    printf("\nBye\n");
    return 0;
}
