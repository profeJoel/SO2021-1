#include<stdio.h>
#include<unistd.h>

int SO = 2021;

int main(void)
{
	pid_t pid_Hijo; //es un enterio modificado a Long
	printf(">> PID del Proceso Padre = %d >> Comienza ejecucion\n", getpid());
	pid_Hijo = fork(); // clona el proceso y crea un proceso hijo
	printf(">> PID = %d >> PID Hijo = %d >> EN EJECUCION\n", getpid(), pid_Hijo);

	while(1)
	{	
		if(pid_Hijo > 0) // Es la ejecucion del proceso padre
			//SO = 2020;
			SO--;
		else if(pid_Hijo == 0)
			SO++;
		else
			printf("Hubo un Error\n");
	
		sleep(2);
		printf("El valor de SO = %d por PID= %d\n", SO, getpid());
	}

	return 0;
}