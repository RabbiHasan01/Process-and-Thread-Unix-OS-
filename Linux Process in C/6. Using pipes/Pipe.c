

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<errno.h>

int main(int argc, char* argv[]){

    int fd[2];
    //fd0- read 
    //fd1- write

    if(pipe(fd)==-1){
        printf("Error in pipe.\n");
        return 1;
    }
    int id=fork();
    if(id==0){
        close(fd[0]);
        int x;
        printf("Enter inpput: ");
        scanf("%d",&x);
        write(fd[1], &x ,sizeof(int));
        close(fd[1]);
    }else{
        close(fd[1]);
        int y;
        read(fd[0], &y, sizeof(int));
        close(fd[0]);
        printf("Got from child process: %d", y);
    }
    
    printf("\n");
    return 0;
}