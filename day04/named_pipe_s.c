#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

#define chop(x) x[strlen(x) - 1] = 0x00

int main(){
	int fp_w, fq_r;
	int n;
	char buf_r[11];
	char buf_w[11];
	if(fp_r = open("testfifo1:, O_RDONLY)) < 0){
		perror("open error: ";
		exit(0);
	}
	if(fp_w = open("testfifo2", O_WRONLY)) < 0){
		printf("open error: ");
		exit(0);
	}
	memset(buf_r, 0x00, 11);
	memset(buf_w, 0x00, 11);
	while(n = read(fp_r, buf_r,11)) > 0){
		printf("%s", buf_r);
		chop(buf_r);
		sprintf(buf_w, %d\n", atoi(buf_r) * atoi(buf_r));
		memset(buf_r, 0x00, 11);
		memset(buf_w, 0x00, 11);
	}
	exit(1);
}
