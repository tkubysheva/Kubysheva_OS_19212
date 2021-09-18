#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <bool.h>

struct strings{
     int num_of_lines;
     char** lines;
};

void * thread_body(struct strings* param) {
     for(int i = 0; i < param->num_of_lines; i++){
        printf("%s ", param->lines[i]);
     }
}

bool creating_thread(pthread_t thread, struct strings* param){
    int thread_creating_code = pthread_create(&thread, NULL, thread_body, &param);
    if (thread_creating_code != 0) {
        printf("Error in  creating thread 1: error_code: %d\n", thread_creating_code);
        return 0;
    }
    return 1;
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
    struct strings param1 =  {3, strs1}, param2 = {5, strs2}, param3 = {4, strs3}, param4 = {2, strs4};
    if (creating_thread(thread1, param1) && creating_thread(thread2, param2) && creating_thread(thread3, param3) && creating_thread(thread4, param4) == 0) {
        return (EXIT_FAILURE);
    }
     /*
    int thread1_joining_code = pthread_join(thread1, NULL);
    if (thread1_creating_code!=0) {
        printf("Error in  joining thread: error_code: %d\n", thread1_joining_code);
        return (EXIT_FAILURE);
    }
    */
    sleep(5);
    return (EXIT_SUCCESS);
}
