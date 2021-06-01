#include<stdio.h>

int main()
{
	printf("Algoritmo FCFS\n");

	int np=11, procesos[10];
	double tf = 0, tp; //tiempo promedio
	do{
		printf("cantidad de procesos:\n");
		scanf("%d", &np);
	}while(np<=0 || np>10);

	for(int i=0; i<np; i++)
	{
		printf("Inserte el proceso %d :\n", i+1);
		scanf("%d", &procesos[i]);
	}

	//Algoritmo FCFS
	for(int i=0; i<np; i++)
	{
		tf += procesos[i];//orden FIFO
		tp += tf;
		printf("Proceso %d > concluye en %2.1f\n", i+1,tf); 
	}

	printf("\n\nLa suma de los procesos %2.1f\n", tp);
	tp = tp / np;
	printf("\nTiempo promedio en FCFS es de: %2.2f:\n", tp);
	return 0;
}