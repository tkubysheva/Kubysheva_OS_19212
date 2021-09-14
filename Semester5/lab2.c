#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * thread_body(void * param) {
     int num_of_phrase_repeat = 10;
     for(int i = 0; i < num_of_phrase_repeat; i++){
        printf("%d. Hello, I'm child! ", i);
     }
}

int main(int argc, char *argv[]) {
    pthread_t thread;
    int thread_creating_code;

    thread_creating_code=pthread_create(&thread, NULL, thread_body, NULL);
    if (thread_creating_code!=0) {
        printf("Error in  creating thread: error_code: %d\n", thread_creating_code);
        return (EXIT_FAULT);
    }
    int thread_joining_code;
    thread_joining_code = pthread_join(thread, NULL);
    if (thread_creating_code!=0) {
        printf("Error in  joining thread: error_code: %d\n", thread_joining_code);
        return (EXIT_FAULT);
    }
    int num_of_phrase_repeat = 10;
    for(int i = 0; i < num_of_phrase_repeat; i++){
        printf("%d. Hello, I'm parent! ", i);
    }
    return (EXIT_SUCCESS);
}
