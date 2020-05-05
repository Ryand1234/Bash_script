#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

void start()
{
	int available = 0;
	printf("AV: %d\n",available);
	available = 1;
	printf("AV: %d\n",available);
}	

int main()
{
	int rc = fork();
	if(rc< 0)
	{
		printf("Fork Failuer\n");
		exit(1);
	}
	else
	{
		if(rc == 0)
		{
			 printf("This is child process with pid: %d\n", (int)getpid());
			 start();
		}
		else
		{
			 printf("This is parent process with pid: %d\n", (int)getpid());
			 start();
		}
	}


	return 0;
}
