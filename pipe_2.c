#include<signal.h>
#include<unistd.h>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
int count;
void alrm_action(int);

void main(){
	int p[2];
	int pipe_size;
	char c = 'x';
	static struct sigaction act;
	act.sa_handler - alrm_action;
	sigfillset(&(act.sa_mask));

	if(pipe(p) == -1){
		perror("pipe call");
		exit(1);
	}
	
	pipe_size = fpathconf(p[0], _PC_PIPE_BUF);
	printf("Maximum size of write to pipe: %d bytes \n", pipe_size);

	sigaction(SIGALRM, &act, NULL);

	while(count <= pipe_size){
	
		write(p[1], &c, 1);
		alarm(0);

		if((++count % 1024)==0)
			printf("%d characters in pipe \n", count);

		if(pipe_size == count)
			alarm(0);
	}
}

void alrm_action(int signo){
	printf("write blocked after %d chararcters \n", count);
	exit(0);
}
