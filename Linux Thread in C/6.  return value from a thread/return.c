


#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#include<time.h>

void* rollDice(){
    int val= rand()%6 +1;
    //printf("%d\n",val);

    int *result=malloc(sizeof(int));
    *result=val;

    return (void*) result;

       
}

int main(int argc, char* argv[]) {

    srand(time(NULL));

    int *res;

    pthread_t th;

    if(pthread_create(&th, NULL, &rollDice, NULL) !=0){
        return 1;
    }
         
    if(pthread_join(th, (void**) &res)!=0){
        return 2;
    }

    printf("result: %d\n", *res);
    free(res);


printf("\n");
return 0;
}