



#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){

    int id=fork();

    printf("Current Id: %d, Parent Id: %d\n",getpid(), getppid());
    
    printf("\n");
    return 0;
}