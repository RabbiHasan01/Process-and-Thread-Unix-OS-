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

        int err=execlp("ping","ping", "-c", "3", "google.con", NULL);
        if(err==-1){
            printf("Could not find  execution\n");
            return 1;
        }

    }else{
        //pnt
        int wstat;

        wait(&wstat);
        if(WIFEXITED(wstat)){
            int statusCode= WEXITSTATUS(wstat);
            if(statusCode==0){
                printf("Success\n");
            }else{
                printf("Fail status: %d\n",statusCode);
            }
        }
        
    }


    return 0;

}