/*
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pid_t getpid(void);
pid_t getppid(void);
int global;

int main(){
	int local=0,i;
	pid_t CurrentProcessID,ParentProcessID;
	CurrentProcessID=getpid();
	ParentProcessID=getppid();
	printf("Now it is in the program TEST\n");
	for(i=0;i<10;i++){
	sleep(1);
	printf("Parent:%d,Current:%d,Number:%d\n",ParentProcessID,CurrentProcessID,i);
	}
	global=local+1;
	printf("global is :%d,	local is :%d\n",global,local);
	exit(1);
	return 0;
}
*/
