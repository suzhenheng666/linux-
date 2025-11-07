#include<stdio.h>
#include<unistd.h>
#include <errno.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
	for(int i=0;i<4;i++)
	{
		pid_t pid = fork();//指令
		if(pid<0)
		{
			perror("fork");
		}else if(pid == 0)
		{
			printf("son pid=%d\n",getpid());
			printf("son parent's pid=%d\n",getppid());
			sleep(5);
			exit(0);
		}else
		{
			printf("parent pid=%d\n",pid);
		}
	}
	for(int i=0;i<4;i++)
	{
		int status;
		pid_t get_pid=waitpid(-1,&status,0);
		if(WIFEXITED(status))
		{
			printf("子进程%d退出,推出码：%d\n",get_pid,WEXITSTATUS(status));
		}
	}
	return 0;
}
