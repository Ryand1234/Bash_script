#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<fcntl.h>
#define Max_sequence 10
typedef struct {
	int Fibonacci[Max_sequence];
	int sequence_size;
}shared_data;
int main()
{
	int t,id;
	shared_data *shared_memory;
	printf("Fibonacci Series \n");
	scanf("%d",&t);
	id = shmget(IPC_PRIVATE,sizeof(shared_data),S_IRUSR|S_IWUSR);
	shared_memory = (shared_data *) shmat(id,NULL,0);
	shared_memory->sequence_size = t;
	int rc = fork();
	if(rc<0)
	{
		fprintf(stderr, "Error in forking\n" );
		exit(0);
	}
	else if(rc ==0)
	{
		int c,a=0,b=1;
		//Child process
		printf("Child Process\n");
		for(int i=0;i<t;i++)
		{
			shared_memory->Fibonacci[i]=a;
			c = a+b;
			a = b;
			b = c;
		}
		printf("\n");
	}
	else
	{
		int rc_wait = wait(NULL);
		printf("Parent Process\n");
		for(int j=0;j<t;j++)
		{
			printf("%d ",shared_memory->Fibonacci[j]);
		}
		printf("\n");
		shmdt(shared_memory);
		shmctl(id,IPC_RMID,NULL);
	}
}