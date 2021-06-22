#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> //avisar al compilador del uso de la libreria

#define N 5

int dato_publico = 0;

void *dice_hola(void *t)
{
	long hilo_id;
	hilo_id = (long) t;
	dato_publico++;
	printf("HILO %ld (%d) dice: HOLA CLASE de SO -> dato_publico = %d\n", hilo_id, getpid(), dato_publico);
	pthread_exit(NULL);//termina la ejecución del hilo
}


int main()
{
	pthread_t hilos[N];
	int confirmacion;
	long i; // solamente para pasar por referencia

	for(i=0; i<N; i++)
	{
		printf("MAIN: creando hilo %ld\n", i);
		printf("MAIN: dato public = %d\n", dato_publico);
		//pthread_create(almacenamiento, attr == NULL, funcion, (void) *arg)
		confirmacion = pthread_create(&hilos[i], NULL, dice_hola, (void *)i);
		if(confirmacion > 0)
		{
			printf("ERROR al crear hilo: %d\n", confirmacion);
			exit(-1);
		}
	}

	for(i=0; i<N; i++)
	{
		confirmacion = pthread_join(hilos[i], NULL);
		if(confirmacion > 0)
		{
			printf("ERROR al recibir hilo: %d\n", confirmacion);
			exit(-1);
		}
	}

	printf("\nMAIN: el valor del dato_publico es %d\n", dato_publico);
	pthread_exit(NULL);
}