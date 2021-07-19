#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>


pthread_t productor, consumidor;
int respaldo, buffer = 0; //limite del buffer es 1
sem_t seguro_buffer, en_espera;

void* produce(void* arg)
{
	while(1)
	{
		long id = (long) arg;
		pthread_t tid = pthread_self(); //indica el idenficador del hilo
		sem_wait(&seguro_buffer); //wait()
		printf("HILO PRODUCTOR%ld (%ld): antes Buffer = %d\n", id, tid, buffer);
		buffer += 1;
		printf("HILO PRODUCTOR %ld (%ld): despues Buffer = %d\n", id, tid, buffer);
		if(buffer == 1) 
			sem_post(&en_espera);
		//sleep(2);
		sem_post(&seguro_buffer);
	}
}

void* consume(void* arg)
{
	sem_wait(&en_espera);
	while(1)
	{
		long id = (long) arg;
		pthread_t tid = pthread_self(); //indica el idenficador del hilo
		sem_wait(&seguro_buffer); //wait()
		printf("HILO CONSUMIDOR %ld (%ld): antes Buffer = %d\n", id, tid, buffer);
		buffer -= 1;
		respaldo = buffer;
		printf("HILO CONSUMIDOR %ld (%ld): despues Buffer = %d\n", id, tid, buffer);
		sem_post(&seguro_buffer);
		if(respaldo == 0)
			sem_wait(&en_espera);
		//sleep(2);
	}
}


int main()
{
	long i;
	int confirmacion;
	sem_init(&seguro_buffer, 0, 1); //1 -> se comportará como un cerrojo
	sem_init(&en_espera, 0, 1); //1 -> se comportará como un cerrojo

	sem_wait(&en_espera);
	
	confirmacion = pthread_create(&productor, NULL, &produce, (void *) i);
	if(confirmacion != 0)
		printf("ERROR: %d, al lanzar el hilo\n", confirmacion);

	confirmacion = pthread_create(&consumidor, NULL, &consume, (void *) i);
	if(confirmacion != 0)
		printf("ERROR: %d, al lanzar el hilo\n", confirmacion);

	pthread_join(productor,NULL);
	pthread_join(consumidor,NULL);
}