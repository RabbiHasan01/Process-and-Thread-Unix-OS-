

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<errno.h>

int main(int argc, char* argv[]){

    int id1=fork();
    int id2= fork();

    for(int i=0;i<10;i++){
        fork();
    }

    if(id1==0){
        if(id2==0){
            printf("Process y\n");
        }else{
            printf("Process x\n");
        }
    }else{
        if(id2==0){
            printf("Process z\n");
        }else{
            printf("Parent process\n");
        }

    }

    while ((wait(NULL) !=-1 || errno != ECHILD))
    {
        /* code */
        printf("Waited for a child to finish.\n");
    }
    
    

    
    printf("\n");
    return 0;
}