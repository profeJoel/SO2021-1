#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define CANT_HILOS 5

pthread_t hilo[CANT_HILOS];
int recurso = 0;
sem_t semaforo;

void* hacer_algo(void *arg)
{
	long id = (long) arg;
	pthread_t tid = pthread_self(); //indica el idenficador del hilo
	sem_wait(&semaforo); //wait()
	printf("HILO %ld (%ld): antes Recurso = %d\n", id, tid, recurso);
	recurso += 1;
	printf("HILO %ld (%ld): despues Recurso = %d\n", id, tid, recurso);
	sleep(2);
	sem_post(&semaforo); //signal()
}

int main()
{
	long i;
	int confirmacion;
	sem_init(&semaforo, 0, 4); //1 -> se comportará como un cerrojo

	for(i=0; i<CANT_HILOS; i++)
	{
		confirmacion = pthread_create(&hilo[i], NULL, &hacer_algo, (void *) i);
		if(confirmacion != 0)
			printf("ERROR: %d, al lanzar el hilo\n", confirmacion);
	}

	for (i = 0; i < CANT_HILOS; ++i)
	{
		pthread_join(hilo[i],NULL);
	}


}