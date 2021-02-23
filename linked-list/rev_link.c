#include<stdlib.h>
#include<stdio.h>

void disp();
void rev();

typedef struct node{
    int data;
    struct node *next;
}node;

struct node*nw;
struct node*head;
struct node*temp;
struct node*nex;
struct node*prev;

int main(){
    int value,op=0;
    do{
        printf("\nEnter the value of the node: ");
        scanf("%d",&value);
        nw= malloc(sizeof(node));
        nw->data= value;
        nw->next=NULL;

        if(head==NULL){
            head=nw;
        }
        else{
            nw->next=head;
            head=nw;
        }
        printf("\nPress 0 to continue: ");
        scanf("%d",&op);
    }while(op==0);
    printf("\n");
    disp();
    rev();
    disp();

    free(nw);
    return 0;
}

void disp(){
    temp=head;
    while(temp->next!= NULL){
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("%d", temp->data);   
    printf("\n");   
}

void rev(){
    temp=head;
    nex= head;
    prev=NULL;
    while(nex!=NULL){
        nex=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nex;
    }
    head=prev;
    // printf("\nHead: %d\n",head->data);
}