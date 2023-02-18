
 

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#include<semaphore.h>

#define THREAD_NUM 4

sem_t sem;


void* routine(void* arg){

    sem_wait(&sem);
    sleep(1);
    printf("Hello from Thread: %d\n", *(int*)arg);
    sem_post(&sem);
    free(arg);

    
}

int main(int argc, char* argv[]) {

    pthread_t t[10];
    sem_init(&sem, 0, 2);  


    int i;
    for(i=0; i<THREAD_NUM;i++){
         int *a= malloc(sizeof(int));
         *a=i;
        if(pthread_create(t+i, NULL, &routine, a) !=0){
            perror("fail to create\n");
       
        }
       
        
    }
    for(i=0; i<THREAD_NUM;i++){
        if(pthread_join(t[i], NULL) !=0){
            perror("fail to join.\n");
           
        }
        
    }
    sem_destroy(&sem);
    
printf("\n");
return 0;
}