#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	pid_t childPid;
	int i;
	childPid = fork();

	if(childPid > 0) {
		printf("parent pid : %d\n", getpid());
		sleep(2);
		printf("parent terminated\n");
		exit(0);
	}
	else if(childPid == 0){
		printf("child\n");
		sleep(1);
		for(i=0; i< 10; i++){
			printf("child pid: %d, parent pid: %d\n", getpid(), getppid());
			sleep(1);
		}
		printf("child terminated\n");
		exit(0);
	}
	else {
		perror("fork Fall!\n");
		return -1;
	}
	return 0;
}
