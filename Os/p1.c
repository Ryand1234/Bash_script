#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>
int main(int argc, char *argv[])
{
	printf("This is a process of id : %d \n",(int)getpid() );
	int rc = fork();
	if(rc < 0)
	{
		fprintf(stderr, "Fork Failed \n");
		exit(1);
	}
	else
		if(rc==0)
		{ //Child Process
			//close(STDOUT_FILENO);
			printf("This is child process with pid: %d\n", (int)getpid());
		}
	else
		{
			// Parent Process
			int rc_wait = wait(NULL);
			
			printf("This is parent process of (%d)  with pid: %d\n",rc,(int)getpid() );
			int rc1 = fork();
			if(rc1 < 0)
			{
				fprintf(stderr, "Fork Failed \n");
				exit(1);
			}
			else
				if(rc1==0)
				{ //Child Process
					//close(STDOUT_FILENO);
				printf("This is 2nd child process with pid: %d\n", (int)getpid());
				}
				else
				{
				// Parent Process
					int rc_wait = wait(NULL);

					printf("This is parent process of (%d)  with pid: %d\n",rc1,(int)getpid() );
				}		
		}
		printf("Outside IF \n");
	return 0;
}