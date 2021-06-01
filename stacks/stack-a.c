#include<stdio.h>
#include<stdlib.h>

// Stack implementation using linked lists

void ins();
void del();
void disp();

typedef struct node{
    int data;
    struct node *next;
}node;

node*top=NULL;
node*bottom=NULL;
node *nw;

int main(){
    
    // 1. Insertion from top only
    // 2. Deletion from top only
    // 3. Display of the Stack
    int choice;
    char ch;

    printf("\nThis is Stack implementation in C using Linked List\n");
    while(1){
        printf("\nChoose from the following option: \n1. Push into the stack \n2. Pop from the stack \n3. Display the stack \n4. Exit the program \n\nChoice: ");

        scanf("%d",&choice);

        switch(choice){
            case 1:
                ins();
                break;
            case 2:
                del();
                break;
            case 3:
                disp(bottom);
                break;
            case 4:
                printf("\nExiting the program\n");
                exit(0);
                break;
            default:
                printf("\nInvalid input\n");
                break;
        }
    }

    free(nw);
    return 0;
}

void ins(){
    int op;
    do{
        int value;

        nw= malloc(sizeof(int));
        printf("Enter the value you want to push: ");
        scanf("%d",&value);

        nw->data= value;
        nw->next= NULL;

        if (bottom==NULL && top==NULL){
            top=nw;
            bottom=nw;
        }
        else if(top != NULL){
            top->next= nw;
            top=nw;
        }

        printf("Press 0 to continue: ");
        scanf("%d",&op);

    }while(op==0);

    printf("\nTop of the stack is: %d\n",top->data);
}

void del(){
    struct node* temp;

    if(top==NULL && bottom==NULL){
        printf("\nStack is empty\n");
    }
    else{
        temp=bottom;

        if(temp==top){
           printf("\nThe value removed (POP) from the stack is %d\n",temp->data);
           free(temp);
           printf("\nStack is empty now\n");
           top=NULL;
           bottom=NULL; 
        }
        else{
            while(temp->next!=top){
                temp=temp->next;
            }
            top=temp;
            temp=top->next;
            printf("\nThe value removed (POP) from the stack is %d\n",temp->data);
            top->next=NULL;
            free(temp);
            printf("\nTop of the stack is: %d\n",top->data);
        } 
    }
}

void disp(){
    struct node*temp;
    temp=bottom;
    int count=0;
    if(temp==NULL){
        printf("\nStack is empty\n");
    }
    else{
        while(temp->next!=NULL){
            printf("%d-->",temp->data);
            temp=temp->next;
            count+=1;
        }
        printf("%d",temp->data);
        count=count+1;
        printf("\nThe number of elements in the stack are: %d\n", count);
    }
    
}