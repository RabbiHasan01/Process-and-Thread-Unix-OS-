

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int  primes[10]={2,3,5,7,11,13,17,19,23,29};


void* routine(void* arg){

    int idx= *(int*) arg;
    printf("%d ", primes[idx]);
    free(arg);
    
}

int main(int argc, char* argv[]) {

    pthread_t t[10];
    int i;
    for(i=0; i<10;i++){
        int *a= malloc(sizeof(int));
        *a=i;
        if(pthread_create(t+i, NULL, &routine, a) !=0){
            perror("fail to create\n");
       
        }
        free(a);
        
    }
    for(i=0; i<10;i++){
        if(pthread_join(t[i], NULL) !=0){
            perror("fail to join.\n");
           
        }
        
    }
    
printf("\n");
return 0;
}