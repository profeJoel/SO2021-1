#include<stdio.h>

int main()
{
	printf("Algoritmo SJF\n");

	int np=11, procesos[10][2];
	double tf = 0, tp; //tiempo promedio
	do{
		printf("cantidad de procesos:\n");
		scanf("%d", &np);
	}while(np<=0 || np>10);

	for(int i=0; i<np; i++)
	{
		printf("Inserte el proceso %d :\n", i+1);
		scanf("%d", &procesos[i][0]); //Valor de tiempo de uso
		procesos[i][1] = i+1;//el identificador
	}
	//Algoritmo SJF
	//ordenamiento: burbuja
	for(int i=0; i<np-1; i++)
	{
		for(int j=i+1; j<np; j++)
		{
			if(procesos[j][0] < procesos[i][0])
			{
				int aux[2] = {procesos[j][0], procesos[j][1]};

				procesos[j][0] = procesos[i][0];
				procesos[j][1] = procesos[i][1];

				procesos[i][0] = aux[0];
				procesos[i][1] = aux[1];
			}
		}
	}

	//Se realiza el mismo procedimiento, pero con la cola ordenada por prioridad
	for(int i=0; i<np; i++)
	{
		tf += procesos[i][0];//orden FIFO
		tp += tf;
		printf("Proceso %d > concluye en %2.1f\n", procesos[i][1],tf); 
	}

	printf("\n\nLa suma de los procesos %2.1f\n", tp);
	tp = tp / np;
	printf("\nTiempo promedio en FCFS es de: %2.2f:\n", tp);
	return 0;
}