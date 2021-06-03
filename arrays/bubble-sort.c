#include<stdio.h>

int main(){
    int n;
    printf("Enter the total number of elements in the array: ");
    scanf("%d",&n);
    int a[n];

    printf("\n");

    for(int i=0; i<n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d",&a[i]);
    }

    printf("\nUnsorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d\t", a[i]);
    }
    
    int pass=n;
    for(int i=0; i<n;i++){
        int swap=0;
        for(int j=0; j<pass-1; j++){
            if(a[j]>a[j+1]){
                int temp= a[j];
                a[j]= a[j+1];
                a[j+1]= temp;
                swap+=1;
            }
        }
        if(swap==0){
            break;
        }

        pass=pass-1;
    }

    printf("\n\nSorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d\t", a[i]);
    }

    return 0;
}
