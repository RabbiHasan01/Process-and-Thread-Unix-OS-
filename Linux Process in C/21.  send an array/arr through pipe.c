

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<errno.h>

#include<sys/stat.h>
#include<sys/types.h>

#include<fcntl.h>

#include<signal.h>
#include<time.h>

int main(int argc, char* argv[]){

    int pid= fork();
    if(pid==-1){
        return 1;
    }

    int fd[2];
    if(pipe(fd)==-1){
        return 2;
    }

    if(pid==0){
        //chl : create arr and send to pnt.
        close(fd[0]); //rd close
        int arr[10];

        srand(time(NULL));
        int n=10;
        //n= rand()%10 +1;

        printf("Generate: ");
        for(int i=0;i<n;i++){
            arr[i]=rand() % 10;
            printf("%d\t", arr[i]);
        }
        printf("\n");

        if(write(fd[1], &n, sizeof(n))<0){return 4;}
        printf("Sent n = %d\n",n);

        if(write(fd[1], arr, sizeof(int)*n) < 0){
            return 3;
        }
        printf("Sent array\n");

        close(fd[1]);

    }/*else{
        //pnt 
        close(fd[1]);

        int arr[10];

        int n;

        if(read(fd[0], &n, sizeof(n))<0){return 5;}
        printf("Recieved n = %d\n",n);
        if(read(fd[0], arr, sizeof(int)*n)<0){
            return 6;
        }
        printf("recieved array.\n");

        close(fd[0]);

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
        }
        printf("Sum= %d\n",sum);
        wait(NULL);
        

    }*/

return 0;  
}