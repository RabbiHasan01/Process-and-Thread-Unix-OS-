

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
    srand(time(NULL)) ;

    for(int i=0;i<5;i++){
        a[i]=rand()%100;
    }

    int fd= open("sum",O_WRONLY);
    if(fd==-1){//chk err
        return  1;
    }

    for(int i=0;i<5;i++){
        if(write(fd, &a[i], sizeof(int))==-1){
            return 2; 
        }
        printf("Wrote %d", a[i]);
    }
    close(fd);
    
    printf("\n");
    return 0;
}