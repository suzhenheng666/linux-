#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
        int fd[2];
        pipe(fd);
        pid_t pid=fork();
        if(pid<0)
        {
                perror("fork");
        }
        else if(pid==0)
        {
                char buf[1024];
                read(fd[0],buf,1024);
                printf("%s\n",buf);
                close(fd[0]);
		sleep(1);
		write(fd[1],"Hello parent",13);
		close(fd[1]);
                exit(0);
        }
        else
        {
                int status;
		char buf[1024];
                write(fd[1],"Hello son",10);
                close(fd[1]);
		sleep(1);
                read(fd[0],buf,1024);
		printf("%s\n",buf);
		wait(&status);
        }
	return 0;
}
