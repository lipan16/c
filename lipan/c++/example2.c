/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	printf("Just 1 process now\n");
	printf("Parent calling fork()......\n");
	pid=fork();
	if(pid==0){
			printf("I am the child\n");
			execl("/bin/ls","ls","-l","fork-test.c",(char *)0);
			perror("exec error:");
			exit(0);
	}
	else if(pid>0){
			wait();
			printf("I am the parent\n");
	}
	else
		printf("fork failed\n");
	printf("Program end\n");
	return 0;
}
*/
