#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * thread_body(void * param) {
     int num_of_phrase_repeat = 10;
     for(int i = 0; i < num_of_phrase_repeat; i++){
        printf("%d. Hello, I'm child!\n", i);
     }
}

int main(int argc, char *argv[]) {
    pthread_t thread;
    int thread_creating_code = pthread_create(&thread, NULL, thread_body, NULL);
    if (thread_creating_code != 0) {
        printf("Error in  creating thread: error_code: %d\n", thread_creating_code);
        return (EXIT_FAILURE);
    }

    int num_of_phrase_repeat = 10;
    for(int i = 0; i < num_of_phrase_repeat; i++){
        printf("%d. Hello, I'm parent!\n", i);
    }

    sleep(5);

    return (EXIT_SUCCESS);
}
