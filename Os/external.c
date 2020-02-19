#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include <sys/msg.h>
#include<sys/types.h>
#include <sys/ipc.h>
#define buffer_size 25
struct {
	long priority;
	int temp;
	int pid;
	int stable;
}data ;
int main(int argc, char const *argv[])
{
	int msqid;
	msqid = msgget(1234,0600|IPC_CREAT);
	if(msqid<0)
	{
		fprintf(stderr, "Error in Opening\n" );
		return 1;
	}	
	else
	{
		data.priority = 2;
		data.temp =	atoi(argv[1]);
		data.pid = atoi(argv[2]);
		data.stable = 0;
		
			if(msgsnd(msqid,&data,sizeof(data)-sizeof(long),0)>=0)
			printf("Message sent\n");
		else
			{
				perror("msgsnd");
				exit(1);
			}
		
	}
	return 0;
}