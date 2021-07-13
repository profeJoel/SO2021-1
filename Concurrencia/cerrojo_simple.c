//Cerrojo Simple
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define N 5
#define LIBERADO 1
#define BLOQUEADO -1

pthread_t hilos[N];
int recurso = 0;
int cerrojo = LIBERADO;

bloquear_cerrojo(int *c, long id)
{
	do{
		printf("HILO <%ld>: Esperando Turno...\n", id);
		sleep(0.15);
	}while(*c == BLOQUEADO);
	if(*c == LIBERADO)
	{
		*c = BLOQUEADO;
		printf("CERROJO BLOQUEADO\n");
	}
}

desbloquear_cerrojo(int *c)
{
	*c = LIBERADO;
	printf("CERROJO LIBERADO\n");
}

void* hacer_algo(void *arg)
{
	long id = (long) arg;
	bloquear_cerrojo(&cerrojo, id); //lock
	//INICIO SECCIÓN CRÍTICA
	printf("HILO <%ld>: valor recurso = %d\n", id, recurso);
	recurso++;
	printf("HILO <%ld>: valor recurso = %d\n", id, recurso);
	//FINAL SECCIÓN CRíTICA
	desbloquear_cerrojo(&cerrojo); //unlock
}

int main()
{
	long i;
	int confirmacion;
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