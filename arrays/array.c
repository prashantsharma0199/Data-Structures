#include<stdio.h>

#define MAX 100
int ins();
int del();
int disp();


int main(){
    int a[MAX];
    int n,op,dummy;

    printf("Enter the number of elements you want in an array: ");
    scanf("%d",&n);

    printf("Enter the elements of the array: \n");
    for (int i=0; i<n; i++){ 
        scanf("%d",&a[i]);
    }

    do{
        printf("\n\nDO you want to \n1)insert a new element? \n2)delete an element? \n3)display the array? \n4)exit \nChoice: ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            n=ins(a,n);
            break;
        
        case 2:
            n=del(a,n);
            break;

        case 3:
            disp(a,n);
            break;
        
        case 4:
            break;
        
        default:
            printf("Invalid input");
            break;
        }
        
    }while (op<=3);
    
    return 0;
}

int ins(int arr[],int n){
    int index,total,value;
    
    total = n;

    printf("\nArray before insertion:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }

    printf("\nEnter the index at which you want your element to be inserted: ");
    scanf("%d",&index);

    printf("\nEnter the value of the element: ");
    scanf("%d", &value);

    n=n+1;
    index=index-1;


    for (int i=total-1;i>=0;i--){
        if (i>index){
            arr[i+1]=arr[i];
        }
        else if(i==index)
        {
            arr[i+1]=arr[i];
            arr[i]=value;  
            break;
        } 
    }

    printf("\nArray after insertion:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    
    return n;
}

int del(int arr[],int n){
    int len=n;
    int index;

    printf("\nArray before deletion:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }

    printf("\nEnter the index you want to delete: ");
    scanf("%d",&index);

    index=index-1;

    for (int i = 0; i < len; i++)
    {
        if (i==index)
        {
            arr[i]=0;
            while (i<=len)
            {
                arr[i]=arr[i+1];
                i=i+1;
                if (i==len)
                {
                    arr[i]=0;
                }
                
            }
        }         
    }

    n=n-1;

    printf("The array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    return n;
}

int disp(int arr[],int n){
    int len= n;
    printf("The array is:\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",arr[i]);
    }
    
    return 0;
}