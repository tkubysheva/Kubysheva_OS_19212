#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * thread_end(void * param){
     printf("\nTHE END!\n");
}

void * thread_body(void * param) {
     pthread_cleanup_push(thread_end, NULL);
     while(1){
        printf("Hello, I'm child!");
     }
}

int main(int argc, char *argv[]) {
    pthread_t thread;
    int thread_creating_code = pthread_create(&thread, NULL, thread_body, NULL);
    if (thread_creating_code != 0) {
        printf("Error in  creating thread: error_code: %d\n", thread_creating_code);
        return (EXIT_FAILURE);
      
    }
    sleep(2);
    int thread_cancel_code = pthread_cancel(thread);
    if (thread_cancel_code != 0) {
        printf("Error in canceling thread: error_code: %d\n", thread_cancel_code);
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

