#include<stdio.h>
#include<unistd.h>
// #include<stdlib.h>

int main(){
//int main(int argc, char* argv[])
	printf("execl start!\n");
	execl("/bin/ls","ls","-l",NULL);
	//system("/bin/ls -l");
	printf("if you read this message, fail creating execl func...\n");
	return 0;
}
