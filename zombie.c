#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
	pid_t childPid;
	childPid = fork();

	if(childPid > 0) {
		printf("parent pid : %d\n", getpid());
		sleep(30);
		printf("parent terminated\n");
		exit(0);
	}
	else if(childPid == 0){
		printf("child\n");
		exit(0);
	}
	else {
		perror("fork Fall!\n");
		return -1;
	}
	return 0;
}
