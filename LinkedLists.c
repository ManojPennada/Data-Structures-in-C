//INSERT AT BEGINING------------------------------------


#include <stdio.h>   
#include <stdlib.h>
typedef struct node{    int data;    struct node *next;}Node;
Node* insertAtBeg(Node *head, int val)
{
    Node *nn = (Node*)malloc(sizeof(Node));
    nn -> data = val;    
    nn -> next=head;
    return nn;
}
void display(Node *head)
{
    if(head){ display(head->next);  printf("%d\t",head->data); }
}
int main()
{
    int temp;
    Node *head = NULL;
    int i; 
    for(i=1;i<=5;i++)   //change i if you want to
    {
        printf("\nEnter : ");
        scanf("%d",&temp);
        head = insertAtBeg(head,temp); 
    }
    printf("\n");
    display(head);    
    return 0;
}

//INSERT AT LAST-----------------------------------------

#include <stdio.h>   
#include <stdlib.h>
typedef struct node{    int data;    struct node *next;}Node;

Node* insertAtEnd(Node *head, int val){
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = val;    nn->next=NULL;
    if(!head) return nn;
    Node *p = head;
    while(p->next) p = p->next;
    p->next = nn;
    return head;
}
void display(Node *head){
    if(head){  printf("%d ",head->data); display(head->next); }
}

int main(){
    Node *head=NULL;
    int i;
    for(i=1;i<=5;i++){ head = insertAtEnd(head,i); }
    display(head);    
    return 0;
}

//DELETE FROM BEGINING------------------------------------

#include <stdio.h>   
#include <stdlib.h>
typedef struct node{    int data;    struct node *next;}Node;

Node* insertAtEnd(Node *head, int val){
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = val;    nn->next=NULL;
    if(!head) return nn;
    Node *p = head;
    while(p->next) p = p->next;
    p->next = nn;
    return head;
}
void display(Node *head){
    if(head){  printf("%d ",head->data); display(head->next); }
}
Node* deleteFromBeg(Node *head){
    if(head){   Node *t = head; head = head->next; free(t);   }
    return head;
}
int main(){
    Node *head=NULL;
    int i;
    for(i=1;i<=5;i++){ head = insertAtEnd(head,i); }
    display(head);    
    head = deleteFromBeg(head);  printf("\n");
    display(head);
    return 0;
}

//DELETE FROM END------------------------------------------------

#include <stdio.h>   
#include <stdlib.h>
typedef struct node{    int data;    struct node *next;}Node;

Node* insertAtEnd(Node *head, int val){
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = val;    nn->next=NULL;
    if(!head) return nn;
    Node *p = head;
    while(p->next) p = p->next;
    p->next = nn;
    return head;
}
Node* deleteFromBeg(Node *head){
    if(head){   Node *t = head; head = head->next; free(t);   }
    return head;
}
void display(Node *head){
    if(head){  printf("%d ",head->data); display(head->next); }
}
Node* deleteFromEnd(Node* head){
    if(!head || !(head->next))return NULL; //better release memory in case of single node
    Node *t = head;
    while(t->next->next){ t = t->next; }
    Node *p = t->next; t->next = NULL; free(p);
    return head;
}
int main(){
    Node *head=NULL;
    int i;
    for(i=1;i<=5;i++){ head = insertAtEnd(head,i); }
    display(head);    
    head = deleteFromBeg(head);  printf("\n");
    display(head);
    head = deleteFromEnd(head);  printf("\n");
    display(head);
    
    return 0;

}

//REVERSE THE LIST-----------------------------------------------------

#include <stdio.h>   
#include <stdlib.h>
typedef struct node{    int data;    struct node *next;}Node;

Node* insertAtEnd(Node *head, int val){
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = val;    nn->next=NULL;
    if(!head) return nn;
    Node *p = head;
    while(p->next) p = p->next;
    p->next = nn;
    return head;
}
void display(Node *head){
    if(head){  printf("%d ",head->data); display(head->next); }
}
Node* Reverse(Node *head){
Node *prv,*cur,*fwd;
cur=head; prv=NULL;
while(cur!=NULL){	fwd=cur->next;	cur->next=prv;	prv=cur;	cur=fwd; }
head=prv;
return head;
}

int main(){
    Node *head=NULL;    int i;
    for(i=1;i<=5;i++){ head = insertAtEnd(head,i); }
    display(head);    
    head=Reverse(head); printf("\n");
    display(head);
    return 0;
}