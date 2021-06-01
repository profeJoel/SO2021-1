#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

#define NUM_HIJOS 10

int hace_algo()
{
	int r;
	srand(getpid());
	r = (rand() %256);
	printf("HIJO: pid= %d, Random = %d\n", getpid(), r);
	return r;
}

int main()
{
	pid_t pid_Hijo, pid_HIJOS[NUM_HIJOS];
	int i, estado;

	//Sección de Creación de Procesos
	for(i=0; i<NUM_HIJOS; i++)
	{
		pid_HIJOS[i] = fork();//Crea a los Procesos Hijo
		if(pid_HIJOS[i] == 0) //Esta parte la ve el proceso hijo
			exit(hace_algo()); // recibe e informa error desde [0,255] , Termina un procesos
	}

	
	pid_Hijo = waitpid(pid_HIJOS[0], &estado, 0);
	printf("Proceso Padre = %d >> Proceso Hijo = %d (estado= %d)\n", getpid(), pid_Hijo, WEXITSTATUS(estado));

	while(1)
		sleep(10);

	return 0;

}