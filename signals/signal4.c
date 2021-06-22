#include<stdio.h>
#include <unistd.h>
#include<signal.h>

void mi_accion(int s)
{
	printf(">>>>>>>>Signal %d capturada e ignorada con exito\n", s);
	raise(SIGALRM);

}

int main()
{
	//signal(int signal, void accion(funcion, signal));
	//signal(SIGALRM, SIG_IGN); //signal ignore
	signal(SIGALRM, &mi_accion);
	//raise(SIGALRM);
	int i = 0;
	while(1){
		printf(">> Ejecucion: %d\n", i++);
		sleep(2);
	}
	return 0;
}