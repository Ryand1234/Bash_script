#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

typedef struct {
	int available;
}lock ;

int compare_and_swap(lock *mutex, int old, int new);

void acquire(lock *mutex)
{

	int i = 1;
	while(i > 0)
	{
		if(compare_and_swap(mutex, 0, 1))
			break;
	}
	
}

void release(lock *mutex)
{
	int k = compare_and_swap(mutex, 1, 0);
}

int compare_and_swap(lock *mutex, int old, int new)
{	
	if(mutex->available == old)
	{
		mutex->available = new;
		return 1;
	}
	else
		return 0;
}


void start()
{
	lock *mutex = (lock*)malloc(sizeof(lock));
	
	acquire(mutex);
	printf("AVAILABLE: %d\n",mutex->available);
	release(mutex);
	printf("AVAILABLE: %d\n",mutex->available);
}

int main()
{
	int rc = fork();
	if(rc < 0)
	{
		printf("Fork Unsuccessfull\n");
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
