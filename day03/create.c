#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define NUM_TREADS 3

void *hello(void *arg){
	printf("Thread %d: Hello, World!\n" , arg);
	return arg;
}


void main(){
	pthread_t tid[NUM_TREADS];
	int i, status;


	for(i = 0; i < NUM_TREADS; i++){
		status = pthread_create (&tid[i], NULL, hello, (void *) i);
		if(status != 0){
			fprintf(stderr, "Create thread %d: %d", i, status);
			exit(1);
		}
	}
	pthread_exit(NULL);
}


