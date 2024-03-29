#include<stdio.h>
#include<pthread.h>

void *cancel_thread(void *arg){
	int i, state;
	for(i=0;;i++){
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &state);
		printf("Thread: cancel state disabled\n");
		sleep(1);
		pthread_setcancelstate(state, &state);
		printf("Thread: cancel state enabled\n");
		if(i % 5 == 0)
			pthread_testcancel;
	}
	return arg;
}

int main(int  argc, char argv[]){
	pthread_t tid;
	int arg, status;
	void *result;
	int a = 0;

	if(argc < 2){
		fprintf(stderr, "USAGE: cancelthread time(sec)\n");
		exit(1);
	}

	status = pthread_create(&tid, NULL, cancel_thread, NULL);

	if(status != 0){
		fprintf(stderr, "create thread: %d", status);
		exit(1);
	}
	pthread_detach(tid);
	arg = atoi (argv[1]);
	if(status != 0){
		fprintf(stderr, "Join thread: %d", status);
		exit(1);
	}
	while(a < 1000){ // if main thread is terminated, the other threads are terminated too.
		a++	// so, we gonna delay the termination of main thread.
	}
	return (int)result; // 
}
