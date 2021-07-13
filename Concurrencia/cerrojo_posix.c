//Cerrojo Simple
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define N 5

pthread_t hilos[N];
int recurso = 0;

pthread_mutex_t cerrojo;

void* hacer_algo(void *arg)
{
	long id = (long) arg;
	pthread_mutex_lock(&cerrojo); //lock
	//INICIO SECCIÓN CRÍTICA
	printf("HILO <%ld>: valor recurso = %d\n", id, recurso);
	recurso++;
	printf("HILO <%ld>: valor recurso = %d\n", id, recurso);
	//FINAL SECCIÓN CRíTICA
	pthread_mutex_unlock(&cerrojo); //unlock
}

int main()
{
	long i;
	int confirmacion;

	if(pthread_mutex_init(&cerrojo, NULL) != 0)
		printf("CERROJO INICIADO...\n");

	for(i=0; i<N; i++)
	{
		confirmacion = pthread_create(&hilos[i], NULL, &hacer_algo, (void *) i);
		if(confirmacion != 0)
			printf("ERROR: %d, al lanzar el hilo\n", confirmacion);
	}

	for (i = 0; i < N; ++i)
	{
		pthread_join(hilos[i],NULL);
	}

	return 0;
}