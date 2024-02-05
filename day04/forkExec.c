#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main(){
	int pid;
	int counter = 1;
	pid = fork();
	if(pid < 0){
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if(pid == 0){
		printf("Child here!\n");
		printf("execl start!\n");
		execl("/bin/ls","ls","-l",NULL);
		printf("if you read this message, fail creating execl func...\n");
	}
	else{
		printf("i'm parent\n");
		wait(NULL);
		printf("process complete\n");
	}
	return 0;
}
