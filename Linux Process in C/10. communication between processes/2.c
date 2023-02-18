

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

     int p1[2]; //c=>p
     int p2[2];// p=>c

     if(pipe(p1)==-1){ return 1;}
     if(pipe(p2)==-1){ return 1;}

     int pid= fork();

     if(pid==0){//clh

     close(p1[0]);
     close(p2[1]);

     int x;
     if(read(p2[0], &x, sizeof(x))==-1){return 3;}
     printf("Recieved:%d\n",x);
     x*=4;
     if(write(p1[1], &x, sizeof(x))==-1){return 4;}
     printf("Wrote= %d\n", x);

     close(p2[0]);
     close(p1[1]);


     }else{

        //parent

        close(p1[1]);
        close(p2[0]);

        srand(time(NULL));
        int y= rand()%10;

        if(write(p2[1], &y, sizeof(y))==-1){return 2;}
        //printf("Wrote: %d\n", y);

        if(read(p1[0], &y, sizeof(int))==-1){return 6;}
        printf("Result: %d\n",y);

        close(p1[0]);
        close(p2[1]);
        wait(NULL);

     }
    
    printf("\n");
    return 0;
}