#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>



int arr0[10];
int sum;
int sum2;
int sum3;

void* FirstSum(void *arg)
{


	for(int i = 0; i < 10; i++)
		arr0[i] = rand() % 101;

	for(int i = 0; i < 10; i++)
		sum += arr0[i];


	return (void *) sum;


}



void* SecondSum(void *arg)
{

        for(int i = 0; i < 10; i++)
                arr0[i] = rand() % 101;

        for(int i = 0; i < 10; i++)
                sum2 += arr0[i];


        return (void *) sum2;


}


void* ThirdSum(void *arg)
{

        for(int i = 0; i < 10; i++)
                arr0[i] = rand() % 101;

        for(int i = 0; i < 10; i++)
                sum3 += arr0[i];


        return (void *) sum3;


}


int main(void)
{

	int i;
	void *status;
	void *status2;
	void *status3;
	srand((unsigned)time(NULL));


	pthread_t thread1,thread2, thread3;
	pthread_create(&thread1, NULL, (void*)&FirstSum, NULL);
	pthread_create(&thread2, NULL, (void*)&SecondSum, NULL);
	pthread_create(&thread3, NULL, (void*)&ThirdSum, NULL);

	pthread_join(thread1, &status);
	pthread_join(thread2, &status2);
	pthread_join(thread3, &status3);


	printf("The sum of Thread 1 is: %d",(int)status);
	printf("\n");
	printf("The sum of thread 2 is: %d",(int)status2);
	printf("\n");
	printf("The sum of thread 3 is: %d",(int)status3);
	printf("\n");


	if(status > status2)
	{
		if(status > status3)
			printf("Thread 1 had the largest sum: %d ", (int)status);

		else if(status3 > status)
			printf("Thread 3 had the largest sum: %d ", (int)status3);



	}


	else if(status2 > status)
	{
		if(status2 > status3)
                        printf("Thread 2 had the largest sum: %d ", (int)status2);

		else if(status3 > status2)
                        printf("Thread 3 had the largest sum: %d ", (int)status3);


	}
	printf("\n");





	return 0;

}
