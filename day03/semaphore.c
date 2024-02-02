#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>

sem_t semaphore;
int num = 2;

void *threadF1(void *arg){
	int i;
	if(num != 0){
		num --;
		sem_wait(&semaphore);
		printf("thread 1 is using a toilet.\n");

		for(i = 0; i < 1000000; i++){} // using toilet...

		printf("thread 1 end using a toilet.\n");
		num++;
		sem_post(&semaphore);
	}
	else if(num == 0){
		printf("toilet is occupied. thread1 is waiting.\n");

		while(num == 0){}// waiting for out
		sem_wait(&semaphore); // now use
		num--;

		printf("thread 1 use toilet and now it is out\n");
		num++;
		sem_post(&semaphore);
	}
	return NULL;
}

void *threadF2(void *arg){
        int i;
        if(num != 0){
                num --;
                sem_wait(&semaphore);
                printf("thread 2 is using a toilet.\n");

                for(i = 0; i < 1000000; i++){} // using toilet...

                printf("thread 2 end using a toilet.\n");
                num++;
                sem_post(&semaphore);
        }
        else if(num == 0){
                printf("toilet is occupied. thread1 is waiting.\n");

                while(num == 0){}
                sem_wait(&semaphore); // now use
		num--;

                printf("thread 2 use toilet and now it is out\n");
                num++;
                sem_post(&semaphore);
        }
        return NULL;
}

void *threadF3(void *arg){
        int i;
        if(num != 0){
                num --;
                sem_wait(&semaphore);
                printf("thread 3 is using a toilet.\n");

                for(i = 0; i < 1000000; i++){} // using toilet...

                printf("thread 3 end using a toilet.\n");
                num++;
                sem_post(&semaphore);
        }
        else if(num == 0){
                printf("toilet is occupied. thread1 is waiting.\n");

                while(num == 0){}
                sem_wait(&semaphore); // now use
		num--;

                printf("thread 3 use toilet and now it is out\n");
                num++;
                sem_post(&semaphore);
        }
        return NULL;
}

int main(){
	pthread_t thread1, thread2, thread3;

	sem_init(&semaphore, 0, num); // create semaphore obj

	printf("Semaphore test Start\n");

	pthread_create(&thread1, NULL, threadF1, NULL);
	pthread_create(&thread2, NULL, threadF2, NULL);
	pthread_create(&thread3, NULL, threadF3, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	printf("every semaphore have used toilet.\n");

	sem_destroy(&semaphore);

	return 0;
}
