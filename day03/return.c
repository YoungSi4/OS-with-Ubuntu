#include<pthread.h>
#include<stdio.h>

void *threadRoutine(void* arg){
	long argument;
	argument = *((long *)arg);
	return (void *)(argument + 100);
}

int main(){
	pthread_t threadID;
	printf("Create thread!\n");
	long argument = -1;
	int status;
	void *value;

	status = pthread_create(&threadID, NULL, threadRoutine, (void *)argument);

	printf("Main Thread is no waitinf for Thread!\n");

	pthread_join(threadID, &value);

	printf("Return value (0 success) : %d\n", status);
	printf("recieve value :: %d\n", (long)value);

	return 0;
}
