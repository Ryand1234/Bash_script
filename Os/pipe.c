#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#define read_pipe 0
#define write_pipe 1
#define buffer_size 25
int main(int argc, char const *argv[])
{
	int fd[2];
	int fd1[2];
	char message[buffer_size] = "Hi There";
	char c_message[buffer_size]; 
	char n_message[buffer_size];
	int i=-1;
	printf("Enter message\n");
	fgets(message,buffer_size,stdin);
	int rc = fork();
	if(pipe(fd)==-1)
	{
		fprintf(stderr, "Pipe Error\n");
		return 1;
	}
	if(pipe(fd1)==-1)
	{
		fprintf(stderr, "Pipe Error\n");
		return 1;
	}
	if(rc<0)
	{
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	else
	{
		if(rc==0)
		{
			i=0;
			
			int rc1 = fork();
			if(rc1<0)
			{
				fprintf(stderr, "Fork Error\n");
				exit(1);
			}
			else
				{
					if(rc1==0)
					{
						i=1;
						close(fd[read_pipe]);
						write(fd[write_pipe],message,buffer_size);
						close(fd[write_pipe]);
					}
					else
					{
						//int r = wait(NULL);
						i=2;
						int c = 0;
						char ch;
						close(fd[write_pipe]);
						close(fd1[read_pipe]);
						read(fd[read_pipe],c_message,buffer_size);
						while (c_message[c] != '\0') {
	      					ch = c_message[c];
    	  					if (ch >= 'A' && ch <= 'Z')
        	 					c_message[c] = c_message[c] + 32;
      						else if (ch >= 'a' && ch <= 'z')
					         c_message[c] = c_message[c] - 32;  
      						c++;  
 					  	}
						write(fd1[write_pipe],c_message,buffer_size);
						close(fd1[write_pipe]);
						close(fd1[read_pipe]);
					}
				}	
				if(i==2)
				{

			close(fd1[write_pipe]);
			read(fd1[read_pipe],c_message,buffer_size);
			printf("%s",c_message);
			close(fd1[read_pipe]);
				}
		}
		else
		{
			int k = wait(NULL);
			
		}
	}
	return 0;
}