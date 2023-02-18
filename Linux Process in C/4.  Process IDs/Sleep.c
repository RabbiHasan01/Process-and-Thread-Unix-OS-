

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){

    int id=fork();
    if(id==0){
        sleep(1);
    }
    printf("Current Id: %d, Parent Id: %d\n",getpid(), getppid());
    if(wait(NULL)==-1){
        printf("No child to wait for.");
    }
    
    printf("\n");
    return 0;
}