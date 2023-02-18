

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<errno.h>

#include<sys/stat.h>
#include<sys/types.h>

#include<fcntl.h>

int main(int argc, char* argv[]){

    if(mkfifo("myFifo", 0777)==-1){
        if(errno != EEXIST){
            printf("could not craete fifo file");
            return 1;
        }
        
    }
    printf("Opening....\n");
    int fd=open("myFifo", O_RDWR);//instead O_WRONLY
    printf("Opened\n");
    int x=100;
    if(write(fd, &x, sizeof(int))==-1){
        return 2;
    }
    printf("Written\n");
    close(fd);
    printf("Closed\n");

    printf("\n");
    return 0;
}