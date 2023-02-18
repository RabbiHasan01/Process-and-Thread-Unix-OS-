
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    fork();
    fork();  //N.B. n times fork, 2^n times result.
    printf("Hello world.");
    /*if(id==0){
        printf("child process\n");
    }else{
        printf("main process\n");
    }*/
    printf("\n");
    return 0;
}