#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

struct 

void * thread_body(char** s) {
     int str_num = atoi(s[0]);
     for(int i = 1; i < str_num; i++){
        printf("%s", s[i]);
     }
}

int main(int argc, char *argv[]) {
    pthread_t thread1, thread2, thread3, thread4;
     
    int thread1_creating_code = pthread_create(&thread1, NULL, thread_body, NULL);
    if (thread1_creating_code != 0) {
        printf("Error in  creating thread: error_code: %d\n", thread1_creating_code);
        return (EXIT_FAILURE);
    }
    int thread1_joining_code = pthread_join(thread, NULL);
    if (thread1_creating_code!=0) {
        printf("Error in  joining thread: error_code: %d\n", thread1_joining_code);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
