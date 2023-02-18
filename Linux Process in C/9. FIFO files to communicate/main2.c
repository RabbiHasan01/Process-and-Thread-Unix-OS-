

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<errno.h>

#include<sys/stat.h>
#include<sys/types.h>

#include<fcntl.h>

#include<time.h>

int main(int argc, char* argv[]){

    int a[5];
    
    int fd= open("sum",O_RDONLY);
    if(fd==-1){//chk err
        return  1;
    }

    for(int i=0;i<5;i++){
        if(read(fd, &a[i], sizeof(int))==-1){
            return 2; 
        }
        printf("Recieved: %d\n", a[i]);
    }
    close(fd);
    
    printf("\n");
    return 0;
}