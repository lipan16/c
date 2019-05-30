/*
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

pid_t wait(int *stat_loc);
void perror(const char *s);
#include <errno.h>

int errno,global=0;

int main(){
	int local=0,i;
	pid_t child;
	child=fork();
	if(child== -1)//瀛愯繘绋�
		printf("Fork Error\n");
	if(child== 0){
		printf("\nNow it is child process\n");
		if(execl("/home/asus/test","test.c",NULL)== -1)
			perror("Error in child process");//鍔犺浇澶辫触
		global=local+ 2;
		exit(0);
	}
 	//鐖惰繘绋�
	printf("Now it is parent process\n");
	for(i= 0;i< 10;i ++){
		sleep(2);
		printf("Parent loop:%d\n",i);
		if(i== 2){
			if((child=fork())== -1)
				printf("Fork Error\n");
			if(child== 0){
				printf("\nNow it is in child process\n");
				if(execl("/home/asus/test","test.c",NULL)== -1)
					perror("Error in child process");
				global=local+ 2;
				exit(0);
			}
		}
		if(i== 3){
			pid_t temp;
			temp=wait(NULL);
			printf("Child process ID:%d\n",temp);
		}
	}
	global =local + 1;
	printf("global is :%d,	local is :%d\n",global,local);
	exit(0);
	return 0;
}
*/
