


#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<errno.h>

#include<signal.h>

void handler_sigtstp(int sig){
    printf("Stop not allowed.\n");

}
int main(int argc, char* argv[]){

    /*
    //background handle

    struct sigaction sa;
    sa.sa_handler= &handler_sigtstp;
    sigaction(SIGTSTP, &sa, NULL);*/

    //or
    signal(SIGTSTP, &handler_sigtstp);
    

    int x;
    printf("Enter input: ");
    scanf("%d", &x);

    printf("Result of %d *5 =  %d\n", x,x*5);


return 0;
}