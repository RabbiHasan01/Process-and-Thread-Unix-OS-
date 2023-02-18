

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define THREAD_NUM 8

pthread_mutex_t muFuel;
int  fuel=50;


void* routine(void* arg){

     pthread_mutex_lock(&muFuel);
     fuel+=50;
     printf("Increment fuel: %d\n", fuel);
     pthread_mutex_unlock(&muFuel);

    
}

int main(int argc, char* argv[]) {

    pthread_t t[10];
    pthread_mutex_init(&muFuel, NULL);
    int i;
    for(i=0; i<THREAD_NUM;i++){
         
        if(pthread_create(t+i, NULL, &routine, NULL) !=0){
            perror("fail to create\n");
       
        }
       
        
    }
    for(i=0; i<THREAD_NUM;i++){
        if(pthread_join(t[i], NULL) !=0){
            perror("fail to join.\n");
           
        }
        
    }
    printf("fuel: %d\n", fuel);
    pthread_mutex_destroy(&muFuel);
    
printf("\n");
return 0;
}