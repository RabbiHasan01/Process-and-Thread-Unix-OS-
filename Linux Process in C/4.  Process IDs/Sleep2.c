

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

    
    int res=wait(NULL);
    if(res==-1){
        printf("No child to wait for.");
    }else{
        printf("%d process is executed.", res);
    }
    
    printf("\n");
    return 0;
}