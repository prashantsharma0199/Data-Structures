#include<stdio.h>
#include<stdlib.h>

char *compress(char * s){
    char *res= (char* ) malloc(sizeof(char));
    char current = s[0];
    int count =1;
    int initial= 0;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i]==current){
            count++;
        }
        else{
            res[initial]= current;
            res[initial+1]=count+48;
            initial=initial+2;
            // printf("%c%d",current, count);
            current= s[i];
            count= 1;
        }
    }
    res[initial]= current;
    res[initial+1]=count+48;
    // printf("%c%d", current, count);

    return res;
}

int main(){
    char input[]= "aaaabbbbccc";
    char *output = compress(input);
    printf("Input is: %s\n", input);
    printf("String Compression: %s\n", output);
}

