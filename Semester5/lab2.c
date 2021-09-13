#include <error.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * thread_body(void * param) {
     for(int i = 0; i < 10; i++){
        printf("%d. Hello, I'm child! ", i);
     }
}

int main(int argc, char *argv[]) {
    pthread_t thread;
    int code;

    code=pthread_create(&thread, NULL, thread_body, NULL);
    if (code!=0) {
        printf("Error in  creating thread: error_code: %d\n", code);
        exit(1);
    }
    code = pthread_join(thread, NULL);
    for(int i = 0; i < 10; i++){
        printf("%d. Hello, I'm parent! ", i);
    }
    return (EXIT_SUCCESS);
}
