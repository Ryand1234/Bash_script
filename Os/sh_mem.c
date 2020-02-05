#include<stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>
int main()
{
	int id;
	char *shared_mem;
	const int size = 4096;
	id = shmget(IPC_PRIVATE,size, S_IRUSR|S_IWUSR );
	shared_mem = (char *) shmat(id,NULL,0);
	sprintf(shared_mem,"Hello Shared Memory!!!!!");
	printf("%s\n",shared_mem);
	shmdt(shared_mem);
	shmctl(id,IPC_RMID,NULL);
	return 0;	
}