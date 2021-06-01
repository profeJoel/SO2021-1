#include<stdio.h>
#include <unistd.h>
#include<signal.h>

void mi_accion(int s)
{
	printf(">>>>>>>>>Signal: %d capturada\n", s);
}

int main()
{
	pause();
	int i = 0;
	while(1){
		printf(">> Ejecucion: %d\n", i++);
		sleep(2);
	}
	return 0;
}