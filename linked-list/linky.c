#include<stdlib.h>
#include<stdio.h>

void ins_beg();
void ins_end();
void ins_aw();
void del_beg();
void del_end();
void del_aw();
void disp();
void total_nodes();

typedef struct node{
    int data;
    struct node *next;
} node;

node *head =NULL;
node *tail=NULL;
node *nw;

int main(){
    
    int choice;
    char ch;

    printf("\nThis is a Linked List basic operation program\n");
    while(1){
        printf("\nChoose from the following option: \n1. Insertion from the beginning of the linked list \n2. Insertion from the end of the linked list \n3. Insertion at specific position in linked list  \n4. Deletion from the beginning of the linked list \n5. Deletion from the end of the linked list \n6. Deletion at specific position in linked list \n7. Total no. of nodes in the linked list \n8. Display the linked list \n9. Exit the program \n\nChoice: ");

        scanf("%d",&choice);

        switch(choice){
            case 1:
                ins_beg();
                break;
            case 2:
                ins_end();
                break;
            case 3:
                ins_aw();
                break;
            case 4:
                del_beg();
                break;
            case 5:
                del_end();
                break;
            case 6:
                del_aw();
                break;
            case 7:
                total_nodes(head);
                break;
            case 8:
                disp(head);
                break;
            case 9:
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
    

// Insertion from beginning of the linked list
void ins_beg(){
    int op;
    do{
        int value;

        nw= (struct node *)malloc(sizeof(node));
        printf("Enter the value: ");
        scanf("%d",&value);

        nw->data=value;
        nw->next=NULL;

        if(head == NULL && tail == NULL){
            head=nw;
            tail=nw;
        }
        else{
            nw->next=head;
            head=nw;      
        }

        tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
    
        printf("Press 0 to continue:");
        scanf("%d",&op);
    
    }while (op==0);
    
    printf("Tail: %d\n",tail->data);
    printf("Head: %d\n",head->data);
}

// Insertion from end of the linked list
void ins_end(){
    int op;
    do{
        int value;

        nw= malloc(sizeof(node));
        printf("Enter the value: ");
        scanf("%d",&value);
        nw->data=value;
        nw->next=NULL;

        if(head ==NULL && tail ==NULL){
            head=nw;
            tail=nw;
        }
        else if(tail!=NULL){
            tail->next=nw;
            tail=nw;
        }
        
        printf("Press 0 to continue:");
        scanf("%d",&op);

    }while(op==0);  

    printf("Tail: %d\n",tail->data);
    printf("Head: %d\n",head->data);

}

// Insertion at a specific position in the linked list
void ins_aw(){
    
    if(head==NULL && tail==NULL){
        printf("No element in the linked list");
    }
    
    else{
        node *temp;
        node *len;
        int length=0;
        temp = head;
        len = head;

        int value,pos=0;
        nw = malloc(sizeof(node));

        printf("Enter the value: ");
        scanf("%d",&value);
        nw->data=value;
        nw->next=NULL;
        
        while(len->next != NULL){
            length = length+1;
            len=len->next;
        }
        length=length+1;
        // printf("Length is: %d",length);
        
        do{
            printf("Please input position within values 1 to %d: ",length+1);
            scanf("%d",&pos);
            pos=pos-1;
        }while(pos>length);

        if(pos==0){
            nw->next=temp;
            head=nw;
        }
        else if(pos==length){
            for(int i=1; i<pos; i++){
                temp=temp->next;
            }
            // printf("Temp data: %d",temp->data);
            nw->next = temp->next;
            temp->next=nw;
            tail=nw;
        }
        else{
            for(int i=1; i<pos; i++){
                temp=temp->next;
            }
            nw->next = temp->next;
            temp->next=nw;
        }
    
    }
    
    printf("Tail: %d\n",tail->data);
    printf("Head: %d\n",head->data);
}

// Deletion from beginning of the linked list
void del_beg(){
    struct node*temp,*len;
    int length;
    if(head==NULL && tail ==NULL){
        printf("\nLinked list is empty\n");
    }
    else{
        len=head;
        while(len->next != NULL){
            length = length+1;
            len=len->next;
        }
        length=length+1;
        
        if(length==1){
            temp=head;
            printf("\nNode deleted is: %d ", temp->data);
            printf("\n");
            free(temp);
            printf("\nLinked list is empty now\n");
            head=NULL;
            tail=NULL;
        }
        else{
            temp=head;
            head=temp->next;
            temp->next=NULL;
            printf("\nNode deleted is: %d",temp->data);
            printf("\n");
            free(temp);
            printf("Tail: %d\n",tail->data);
            printf("Head: %d\n",head->data);
        }
    }
    
}

// Deletion from end of the linked list
void del_end(){
    int length;
    struct node*temp, *len;
    if (head==NULL && tail==NULL){
        printf("\nLinked List is empty\n");
    }
    else{
        len=head;
        while(len->next != NULL){
            length = length+1;
            len=len->next;
        }
        length=length+1;
        
        if(length==1){
            temp=head;
            printf("\nNode deleted is: %d ", temp->data);
            printf("\n");
            free(temp);
            printf("\nLinked list is empty now\n");
            head=NULL;
            tail=NULL;
        }
        else{
            temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            tail=temp;
            temp=tail->next;
            printf("\nNode deleted is: %d ", temp->data);
            printf("\n");
            tail->next=NULL;
            free(temp);
            printf("Tail: %d\n",tail->data);
            printf("Head: %d\n",head->data);
        }
    }
    
}

// Deletion at a specific position in the linked list
void del_aw(){
    struct node*temp, *len, *tempy;
    int pos, length=0;

    if(head==NULL && tail ==NULL){
        printf("\nLinked list is empty\n");
    }
    else{
        len=head;
        
        while(len->next != NULL){
            length = length+1;
            len=len->next;
        }
        length=length+1;

        if(length==1){
            printf("Only 1 element to delete in the linked list");
            temp=head;
            printf("\nNode deleted is: %d ", temp->data);
            printf("\n");
            free(temp);
            printf("\nLinked list is empty now\n");
            head=NULL;
            tail=NULL;
        }
        else{
            printf("Please input position within values 1 to %d: ",length);
            scanf("%d",&pos);
            if(pos==1){
                temp=head;
                head=temp->next;
                printf("\nNode deleted is: %d ", temp->data);
                printf("\n");
                temp->next=NULL;
                free(temp);
            }
            else if(pos==length){
                temp=head;
                while(temp->next!=tail){
                    temp=temp->next;
                }
                tail=temp;
                temp=tail->next;
                printf("\nNode deleted is: %d ", temp->data);
                printf("\n");
                tail->next=NULL;
                free(temp);
            }
            else{
                temp=head;
                for(int i=1;i<pos-1;i++){
                    temp=temp->next;
                }
                printf("%d\n",temp->data);
                tempy=temp->next;
                printf("\nNode deleted is: %d ", tempy->data);
                printf("\n");
                temp->next=temp->next->next;
                free(tempy);
            }
            printf("Tail: %d\n",tail->data);
            printf("Head: %d\n",head->data);
        }

    }

}

// Display the linked list
void disp(struct node *temp){
    if(temp==NULL){
        printf("\nLinked list is empty\n");
    }
    else{
        printf("\nThe Linked list is: \n");
        while(temp->next != NULL){
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
    
}

// Total no. of nodes in the linked list
void total_nodes(struct node*temp){
    int count=0;
    if(temp==NULL){
        printf("\nThe linked list is empty");
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
            count = count +1;
        }
        count=count+1;
        printf("\nThe number of nodes in the linked list are: %d", count);
    }
}