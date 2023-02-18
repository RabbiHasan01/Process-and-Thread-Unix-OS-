

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int   mails=0;
pthread_mutex_t mu;

void* routine(){

    for(int i=0;i<100000000;i++){

        pthread_mutex_lock(&mu);
        mails++;
        pthread_mutex_unlock(&mu);
    }
    
    //read value
    //increment
    // write value in mem 
    
}

int main(int argc, char* argv[]) {

    pthread_t t1, t2;
    pthread_mutex_init(&mu, NULL);
    if(pthread_create(&t1, NULL, &routine, NULL) !=0){return 1;}
    if(pthread_create(&t2, NULL, &routine, NULL)!=0){return 2;}
    if(pthread_join(t1, NULL)!=0){return 3;}
    if(pthread_join(t2, NULL)!=0){return 4;}

    pthread_mutex_destroy(&mu);

    printf("mails no: %d\n",mails);


printf("\n");
return 0;
}