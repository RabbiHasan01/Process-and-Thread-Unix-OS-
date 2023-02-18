

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<errno.h>

int main(int argc, char* argv[]){

    int arr[]={1,2,3,4,1,2,7};
    int arrSize= sizeof(arr)/sizeof(int);
    int str, end;

    int fd[2];
    //fd0- read 
    //fd1- write

    if(pipe(fd)== -1){
        printf("Error in pipe.\n");
        return 1;
    }
    int id=fork();
    if(id ==-1){
        return 2;
    }

    if(id==0){//child
        str=0;
        end= arrSize/2;
    }else{//perent
        str=arrSize/2;
        end=arrSize;
    }

    int sum=0,i;
    for(i=str; i<end; i++){
        sum+=arr[i];
    }
    printf("Pertial sum: %d\n",sum);

    if(id==0){
        close(fd[0]);
        write(fd[1], &sum, sizeof(int));
        close(fd[1]);
    }else{
        
        close(fd[1]);
        int childSum;
        read(fd[0], &childSum, sizeof(int));
        close(fd[0]);

        int total= sum+ childSum;
        printf("Total: %d\n", total);
        wait(NULL);

    }
    
    printf("\n");
    return 0;
}