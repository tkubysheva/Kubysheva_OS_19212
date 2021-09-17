#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void * thread_body(char** s) {
     int str_num = atoi(s[0]);
     for(int i = 1; i < str_num; i++){
        printf("%s", s[i]);
     }
}

int main(int argc, char *argv[]) {
    pthread_t thread1, thread2, thread3, thread4;
    int code;

    code=pthread_create(&thread1, NULL, thread_body, {"3", "one ", "two"});
    if (code!=0) {
        printf("Error in  creating thread: error_code: %d\n", code);
        exit(1);
    }
    code = pthread_join(thread1, NULL);
    return (EXIT_SUCCESS);
}
