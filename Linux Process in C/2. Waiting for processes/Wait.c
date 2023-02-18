

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char* argv[]){

    int n;
    int id=fork();

    if(id==0){
        n=1;
    }else{
        n=6;
    }
    if(id !=0){
        wait();
    }

    int i;
    for(i=n;i<n+5;i++){
        printf("%d\t",i);
        fflush(stdout);
    }
     
    printf("\n");
    return 0;
}