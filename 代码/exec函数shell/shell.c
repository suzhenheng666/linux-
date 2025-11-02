#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#define NUM 100

int parse_command(char *input,char *arg[])
{
	int arg_count=0;
	char *token=strtok(input," \t\n");
	while(token!=NULL && arg_count<NUM-1)
	{
		arg[arg_count++]=token;
		token=strtok(NULL," \t\n");
	}
	arg[arg_count]=NULL;
	return arg_count;
}

void execute_command(char* arg[])
{
	pid_t pid = fork();
	if(pid<0)
	{
		perror("fork");
	}
	else if(pid==0)
	{
		execvp(arg[0],arg);
		printf("执行失败");
		exit(1);
	}
	else
	{
		int status;
		wait(&status);
		if(!WEXITSTATUS(status))
		{
			printf("执行完毕");
		}
	}

}

int main()
{
	char *arg[NUM];
        char input[NUM];
        printf("简单shell交互界面\n");
        printf("输入 'exit' 或 'quit' 退出\n\n");
	while(1)
	{
		printf("myshell>");
		if(fgets(input,sizeof(input),stdin)==NULL)
		{
			printf("再见\n");
			break;
		}
		input[strcspn(input,"\n")]='\0';
		if(strlen(input)==0)
		{
			continue;
		}
		if(strcmp(input,"exit")==0 || strcmp(input,"quit")==0)
		{
			printf("再见\n");
			break;
		}
		int arg_count=parse_command(input,arg);
		if(arg_count>0)
		{
			printf("执行命令: %s", arg[0]);
                        for (int i = 1; i < arg_count; i++) {
                                printf(" %s", arg[i]);
                        }
                        printf("\n");
			if(strcmp(arg[0],"cd")==0)
			{
				char *path;
				if(arg_count==1)
				{
					path=getenv("HOME");
				}
				else if(arg_count==2)
				{
					path=arg[1];
				}
				else
				{
					fprintf(stderr,"too many dirs\n");
					continue;
				}
				if (chdir(path) != 0) {
			                perror("cd failed");
            			}
				continue;
			}
			else
			{
				execute_command(arg);
			}
		}
			printf("\n");
	}
	return 0;
}
