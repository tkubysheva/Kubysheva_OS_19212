#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct strings{
    int num_of_lines;
    char** lines;
};

void * thread_body(void* par) {
<<<<<<< HEAD
     if(par == NULL){
	     return NULL;
     }
     struct strings param = *(struct strings*)par;
     for(int i = 0; i < param.num_of_lines; i++){
        printf("%s ", param.lines[i]);
        free(param.lines[i]);
     }
     free(param.lines);
     free(par);
     pthread_exit(NULL);
=======
    if(par == NULL){
        return NULL;
    }
    struct strings param = *(struct strings*)par;
    for(int i = 0; i < param.num_of_lines; i++){
        printf("%s ", param.lines[i]);
        free(param.lines[i]);
    }
    free(param.lines);
    free(par);
    return NULL;
>>>>>>> 2bfd2b3738bdd2985f1a9facfe1d12684cf1c81d
}

int creating_thread(pthread_t thread, struct strings* param){
    int thread_creating_code = pthread_create(&thread, NULL, thread_body, param);
    if (thread_creating_code != 0) {
        printf("Error in  creating thread: error_code: %d\n", thread_creating_code);
        return 0;
    }
    return 1;
}




int main(int argc, char *argv[]) {
    pthread_t thread1, thread2, thread3, thread4;
    pthread_t threads[] = {thread1, thread2, thread3, thread4};
    char** strs1 = (char**)malloc(sizeof(char*)*3);
    for(int i = 0; i < 3; ++i){
        strs1[i] = (char*)malloc(sizeof(char)*4);
<<<<<<< HEAD
        strcpy(strs1[i], "aaa");
=======
        strs1[i] = "aaa";
>>>>>>> 2bfd2b3738bdd2985f1a9facfe1d12684cf1c81d
    }
    char** strs2 = (char**)malloc(sizeof(char*)*5);
    for(int i = 0; i < 5; ++i){
        strs2[i] = (char*)malloc(sizeof(char)*7);
<<<<<<< HEAD
        strcpy(strs2[i], "hello!");        
=======
        strs2[i] = "hello!";
>>>>>>> 2bfd2b3738bdd2985f1a9facfe1d12684cf1c81d
    }
    char** strs3 = (char**)malloc(sizeof(char*)*4);
    for(int i = 0; i < 4; ++i){
        strs3[i] = (char*)malloc(sizeof(char)*11);
<<<<<<< HEAD
        strcpy(strs3[i], "good night");
    }
    char** strs4 = (char**)malloc(sizeof(char*)*2);
    for(int i = 0; i < 2; ++i){
        strs4[i] = (char*)malloc(sizeof(char)*4);
        strcpy(strs4[i], "dog");
    }
    struct strings* param = (struct strings*) malloc(sizeof(struct strings)*4);
    param[0].num_of_lines = 3;
    param[0].lines =  strs1;
    param[1].num_of_lines = 5;
    param[1].lines =  strs2;
    param[2].num_of_lines = 4;
    param[2].lines =  strs3;
    param[3].num_of_lines = 2;
    param[3].lines =  strs4;

=======
        strs3[i] = "good night";
    }
    char** strs4 = (char**)malloc(sizeof(char*)*2);
    for(int i = 0; i < 2; ++i){
        strs4[i] = (char*)malloc(sizeof(char)*17);
        strs4[i] = "Where is my bag?";
    }
    struct strings* param = (struct strings*) malloc(sizeof(struct strings)*4);
    param[0].num_of_lines = 3; param[0].lines= strs1;
    param[1].num_of_lines = 5; param[1].lines= strs2;
    param[2].num_of_lines = 4; param[2].lines= strs3;
    param[3].num_of_lines = 2; param[3].lines= strs4;
>>>>>>> 2bfd2b3738bdd2985f1a9facfe1d12684cf1c81d
    for(int i = 0; i < 4; i++){
        if (creating_thread(threads[i], &param[i]) == 0) {
            return (EXIT_FAILURE);
        }
    }
    pthread_exit(NULL);
    return (EXIT_SUCCESS);
}
