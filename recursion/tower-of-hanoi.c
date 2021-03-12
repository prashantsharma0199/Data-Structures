#include<stdio.h>
int TOH(); 

int main(){
    int n;
    printf("\nEnter the number of disks: ");
    scanf("%d",&n);

    printf("\nS denotes Source Rod\nA denotes Auxillary Rod\nD denotes Destination Rod\n");

    printf("\nThe steps are as follows: \n\n");
    TOH(n,'S','D','A');
    return 0;
}

int TOH(n, A, C, B){
    
    if(n==1){
        printf("Move %d disk from %c to %c\n", n,A,C);
    }

    else{
        TOH(n-1,A,B,C);
        printf("Move %d disk from %c to %c\n", n, A, C);
        TOH(n-1,B,C,A); 
    }


    return 0;
}