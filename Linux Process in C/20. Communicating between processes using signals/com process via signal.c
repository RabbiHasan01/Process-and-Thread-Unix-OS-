#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<errno.h>

#include<signal.h>

int x=0;


void handler_sigusr1(int sig){
    if(x==0){
        printf("Hint:");
    }
    
}

int main(int argc, char* argv[]){

    int pid = fork();

    if(pid==-1){
        return 1;
    }

    if(pid==0){
        //cld

        sleep(5);
        kill(getppid(), SIGUSR1);

    }else{
        //pnt 

        struct sigaction sa ;
        sa.sa_flags= SA_RESTART;
        sa.sa_handler= &handler_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);

         
         printf("Result of 3 x 5?: ");
         scanf("%d", &x);

         if(x==15){
            printf("Right\n");

         }else{
            printf("wrong\n");
         }
    }


}