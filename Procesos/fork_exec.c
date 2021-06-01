#include<stdio.h>
#include<unistd.h>

int display_msg(char *m){
	char err_msg[30];
	switch(fork()){
		case 0: 
			execlp("/bin/echo", "echo", m, NULL);
			return 0;
		case -1: 
			perror("Ocurrio una falla en la creacion del FORK()");
			return 2;
		default:
			return 0;
	}
}

void main(){
	static char *msg[] = {"hola", "que", "tal"};
	int i;

	for(i = 0; i < 3; ++i)
		(void) display_msg(msg[i]);
	sleep(2);
}