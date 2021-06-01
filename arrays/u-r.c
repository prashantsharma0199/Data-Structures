#include <stdio.h>

const int info = 2;

int main() {
    int user;
    printf("Enter the number of users for registration: ");
    scanf("%d",&user);

    long int a[user][info];

    for (int i = 0; i < user; ++i){
        printf("\nFor User number %d \n", i + 1);
        for (int j = 0; j < info; ++j){ 
            if(j+1==1){
                long int id;
                printf("\tEnter the user id: ");
                scanf("%ld",&id);
                a[i][j]=id;
            }
            else if(j+1==2){
                long int num;
                printf("\tEnter the phone number: ");
                scanf("%ld",&num);
                a[i][j]=num;
            }
            
        }
    }
    
    printf("\nDetails of registered users are:\n");
    for (int i = 0; i < user; ++i){
        printf("\nFor User number %d \n", i + 1);
        for (int j = 0; j < info; ++j){
            if(j+1==1){
                printf("\tUser ID: %ld\n",a[i][j]);
            }
            else if(j+1==2){
                printf("\tPhone number: %ld\n",a[i][j]);
            }
        }
    }
    
    
    return 0;
}