#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_OF_PHRASE_REPEAT 10

void * thread_body(void * param) {
     for(int i = 0; i < NUM_OF_PHRASE_REPEAT; i++){
        printf("%d. Hello, I'm child!\n", i);
     }
     pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t thread;
    int thread_creating_code = pthread_create(&thread, NULL, thread_body, NULL);
    if (thread_creating_code != 0) {
        printf("Error in  creating thread: error_code: %d\n", thread_creating_code);
        return (EXIT_FAILURE);
    }
    int thread_joining_code;
    thread_joining_code = pthread_join(thread, NULL);
    if (thread_creating_code!=0) {
        printf("Error in  joining thread: error_code: %d\n", thread_joining_code);
        return (EXIT_FAILURE);
    }
    for(int i = 0; i < NUM_OF_PHRASE_REPEAT; i++){
        printf("%d. Hello, I'm parent!\n", i);
    }
    return (EXIT_SUCCESS);
}
    

