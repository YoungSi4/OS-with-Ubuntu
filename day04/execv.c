#include<stdio.h>
#include<unistd.h>

int main(){
// int main(int argc, char* argv[])
	char *argv[] = {"ls","-l",NULL};
	printf("execv start!\n");
	execv("/bin/ls", argv);
	// execl("bin/ls","ls","-l",NULL)
	printf("if you read this message, fail creating execv func...\n");
	return 0;
}
