#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include <fcntl.h>
int main()
{
	int fd=open("666.txt",O_RDONLY);
	int fd1=open("999.txt",O_RDWR | O_CREAT | O_TRUNC,0644);
	char buf[1024];
	ssize_t flag=sendfile(fd1,fd,NULL,1024);
	if(flag>0)
	{
		printf("成功\n");
	}
	close(fd);
	close(fd1);
	return 0;

}
