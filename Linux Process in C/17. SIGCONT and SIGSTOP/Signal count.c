 

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<errno.h>

#include<sys/stat.h>
#include<sys/types.h>

#include<fcntl.h>

#include<signal.h>


int main(int argc, char* argv[]){

    int pid= fork();
    if(pid==-1){return 1;}
    if(pid == 0){
        //cld
        while (1){
            printf("Singnal\n");
            usleep(50000);
        }

    }else{
        //pnt
        kill(pid, SIGSTOP);

        int t;
        
        do{
            printf("Time for executions: ");
            scanf("%d", &t);

            if(t>0){
                kill(pid, SIGCONT);
                sleep(t);
                kill(pid, SIGSTOP);
            }

        }while (t>0);
        
        /*kill(pid, SIGSTOP);
        sleep(1);
        kill(pid, SIGCONT);
        sleep(1);*/
        kill(pid, SIGKILL);
        wait(NULL);


    }


return 0;

}