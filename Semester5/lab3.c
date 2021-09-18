#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

struct strings{
     int num_of_lines;
     char** lines;
};

void * thread_body(struct strings* param) {
     for(int i = 0; i < param->num_of_lines; i++){
        printf("%s ", param->lines[i]);
     }
}

int main(int argc, char *argv[]) {
    pthread_t thread1, thread2, thread3, thread4;
    char* s1 = "aaa";
    char* s2 = "hello!";
    char* s3 = "I have an apple";
    char* s4 = "LOL";
    char* strs1[] = {s1, s2, s3};
    char* strs2[] = {s4, s4, s1, s1, s2};
    char* strs3[] = {s2, s1, s4, s2};
    char* strs4[] = {s1, s3};
    struct strings param1 =  {3, strs1};
    int thread1_creating_code = pthread_create(&thread1, NULL, thread_body, &param1);
    if (thread1_creating_code != 0) {
        printf("Error in  creating thread: error_code: %d\n", thread1_creating_code);
        return (EXIT_FAILURE);
    }
    int thread1_joining_code = pthread_join(thread1, NULL);
    if (thread1_creating_code!=0) {
        printf("Error in  joining thread: error_code: %d\n", thread1_joining_code);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
