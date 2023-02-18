

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

     int p1[2];
     if(pipe(p1)==-1){ return 1;}

     int pid= fork();

     if(pid==0){//clh
     int x;
     if(read(p1[0], &x, sizeof(x))==-1){return 3;}
     printf("Recieved:%d\n",x);
     x*=4;
     if(write(p1[1], &x, sizeof(x))==-1){return 4;}
     printf("Wrote= %d\n", x);


     }else{
        //parent
        srand(time(NULL));
        int y= rand()%10;

        if(write(p1[1], &y, sizeof(y))==-1){return 2;}
        printf("Wrote: %d\n", y);

        if(read(p1[0], &y, sizeof(int))==-1){return 6;}
        printf("Result: %d\n",y);

     }
     close(p1[0]);
     close(p1[1]);
    
    printf("\n");
    return 0;
}