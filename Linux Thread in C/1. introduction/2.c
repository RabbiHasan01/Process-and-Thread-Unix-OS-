

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* routine(){
    printf("Test thread\n");
}

int main(int argc, char* argv[]) {

    pthread_t t1, t2;

    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);


printf("\n");
return 0;
}