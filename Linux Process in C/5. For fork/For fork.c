

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){

    int id1=fork();
    int id2= fork();

    if(id1==0){
        if(id2==0){
            printf("Process y");
        }else{
            printf("Process x");
        }
    }else{
        if(id2==0){
            printf("Process z");
        }else{
            printf("Parent process");
        }

    }
    

    
    printf("\n");
    return 0;
}