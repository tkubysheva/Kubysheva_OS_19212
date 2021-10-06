#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

struct strings{
     int num_of_lines;
     char** lines;
};

void * thread_body(void* par) {
     struct strings* param = par;
     for(int i = 0; i < param->num_of_lines; i++){
        printf("%s ", param->lines[i]);
     }
}

int creating_thread(pthread_t thread, struct strings* param){
    int thread_creating_code = pthread_create(&thread, NULL, thread_body, &param);
    if (thread_creating_code != 0) {
        printf("Error in  creating thread 1: error_code: %d\n", thread_creating_code);
        return 0;
    }
    return 1;
}




int main(int argc, char *argv[]) {
    pthread_t thread1, thread2, thread3, thread4;
    pthread_t threads[] = {thread1, thread2, thread3, thread4};
    char* s1 = "aaa";
    char* s2 = "hello!";
    char* s3 = "I have an apple";
    char* s4 = "LOL";
    char* strs1[] = {s1, s2, s3};
    char* strs2[] = {s4, s4, s1, s1, s2};
    char* strs3[] = {s2, s1, s4, s2};
    char* strs4[] = {s1, s3};
    struct strings param[] =  {{3, strs1}, {5, strs2}, {4, strs3},  {2, strs4}};
    for(int i = 0; i < 4; i++){
         if (creating_thread(threads[i], &param[i]) == 0) {
              return (EXIT_FAILURE);
         }
    }
   
  
    return (EXIT_SUCCESS);
}
