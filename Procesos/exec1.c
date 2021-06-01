#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	if(argc > 1){
		execlp("/bin/cat", "cat", argv[1], (char *) NULL);
		perror("Error al ejecutar");
		exit(1);
	}
	fprintf(stderr, "Modo de Uso: %s archivo_texto", *argv);
	exit(1);
}

/*se ejecuta <executable> <nombre_archivo>*/