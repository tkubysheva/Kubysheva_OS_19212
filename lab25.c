#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

void makeUpper(char* buff, size_t n){
        for(size_t i = 0; i < n && buff[i] != '\0'; ++i){
                buff[i] = toupper(buff[i]);
        }
}

int closePipe(int pf[2])
{
        if(close(pf[0]) == -1 || close(pf[1]) == -1)
        {
                perror("Error in closing pipe");
                return -1;
        }
        return 0;
}

int main(){
        char* str = "Hello, my name is Tanya!\0";
        int str_len = strlen(str);
        int fd[2];
        if(pipe(fd) == -1){
                perror("Fail in pipe\n");
                return -1;
        }
        //write process
        int pidW = fork();
        if(pidW == -1) {
                perror("Fork failture");
                closePipe(fd);
                return 1;
        }
        if(pidW == 0){
                int write_count;
                close(fd[0]);
                while(write_count = write(fd[1], str, str_len + 1) == -1){
                        if(errno == EINTR){
                                errno = 0;
                                continue;
                        }
                        else {
                                perror("Error in writing to pipe");
                                return 1;
                        }

                }
                close(fd[1]);
                return 0;
        }
        int statW;
        while(wait(&statW) == -1){
                perror("Error in wait");
                closePipe(fd);
                return 1;
        }

        //read process
        int pidR = fork();
        if (pidR == -1) {
                perror("Fork failure");
                closePipe(fd);
                return 1;
        }
        if (pidR == 0) {
                close(fd[1]);
                char buff[100];
                int read_count;
                while(read_count = read(fd[0], buff, 100) == -1){
                        if(errno == EINTR)
                        {
                                errno = 0;
                                continue;
                        } else
                        {
                                perror("Error in reading from pipe");
                                return 1;
                        }
                }
                close(fd[0]);
                makeUpper(buff, 100);
                fprintf(stderr, "%s\n", buff);
                return 0;
        }
        int statR;
        while(wait(&statR) == -1){
                perror("Error in wait\n");
                closePipe(fd);
                return 1;
        }
        closePipe(fd);
        return 0;
}
