#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){
	// int kill(pid, signal)
	/*
	pid > 0 significa que se identifica un proceso
	pid == 0 siginifica que se envia la signal al grupo de procesos al que pertenece el emisor
	pid < -1 significa que la signal será enviada a un grupo de procesos en específico
	pid ==-1 la signal es lanzada a todos los procesos.

	$> kill -SIGKILL -1 significa que se eliminan todos los procesos vigentes (sudo)
	*/

	//retorno
	//0 -> signal se envió correctamente
	//-1 -> error al enviar
	int confirmacion;
	confirmacion = kill(4483, SIGALRM);
	if(confirmacion == 0)
		printf("Si se envió la signal\n");
	else
		printf("Error al enviar\n");
	return 0;
}