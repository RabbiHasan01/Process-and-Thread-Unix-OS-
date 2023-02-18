



#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define THREAD_NUM 8

pthread_mutex_t muFuel;
int  fuel=50;

pthread_mutex_t muWater;
int  water=10;


void* routine(void* arg){

    if(rand()%2==0){
        pthread_mutex_lock(&muFuel);
        sleep(1);
        pthread_mutex_lock(&muWater);
    }else{
        pthread_mutex_lock(&muWater);
        sleep(1);
        pthread_mutex_lock(&muFuel);
    }
     
     fuel+=50;
     water= fuel;
     printf("Increment fuel: %d\n Set water %d\n", fuel, water);
     pthread_mutex_unlock(&muFuel);
     pthread_mutex_unlock(&muWater);

    
}

int main(int argc, char* argv[]) {

    pthread_t t[10];
    pthread_mutex_init(&muFuel, NULL);
    pthread_mutex_init(&muWater, NULL);
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
    printf("Water: %d\n", water);
    pthread_mutex_destroy(&muFuel);
    pthread_mutex_destroy(&muWater);
    
printf("\n");
return 0;
}