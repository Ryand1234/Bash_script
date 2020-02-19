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
}data;
int main(int argc, char const *argv[])
{
	int msqid;
	msqid = msgget(1234,0600|IPC_CREAT);
	int cen_temp = atoi(argv[1]);
	if(msqid<0)
	{
		fprintf(stderr, "Error in Opening\n" );
		return 1;
	}	
	else
	{
		int i=0,sum=0,j=0;
		int Temp[4] = {0};
		int A[4] = {0};
		while(j!=4)
		{
			i+=1;
			for(int k=0;k<4;k++)
				j+=A[k];
			if(msgrcv(msqid,&data,sizeof(data)-sizeof(long),2,0)<0)
			{
				perror("msgrecv");
				exit(1);
			}
			else
			{
				printf("%d\n", sum);
				sum+=data.temp;
				if(Temp[i%4]!=data.temp)
				{
					data.temp = (data.temp*3+2*cen_temp)/5;
					if(msgsnd(msqid,&data,sizeof(data)-sizeof(long),0)>=0)
						printf("Message sent\n");
					else
					{
						perror("msgsnd");
						exit(1);
					}	
				}	
				else
				{
					printf("Yes 1!!!!!!!!!!!!!!!!!!!!!!!!\n");
					data.stable = 1;
					A[i%4]=1;
				}
				Temp[i%4] = data.temp;
				printf("%d %d %d\n",j,data.pid,data.temp );
			
			}
			if((i%4==1)&&(i>1))
			{
				printf("hello\n");
				cen_temp = (2*cen_temp+sum)/6;
				sum = 0;
				j=0;
			}
		}
		for(int q = 0;q<4;q++)
			printf("%d : %d \n",&Temp[i],&A[i] );
	}

	return 0;
}