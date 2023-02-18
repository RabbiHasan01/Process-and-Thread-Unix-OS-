#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<errno.h>

#include<sys/stat.h>
#include<sys/types.h>

#include<fcntl.h>


int main(int argc, char* argv[]){

    int id=fork();
    if(id==-1){ return 1;}

    if(id==0){

        execlp("ping","ping", "-c", "3", "google.com", NULL);

    }else{
        //pnt
        wait(NULL);
        printf("Successful!\n");
    }


    return 0;

}