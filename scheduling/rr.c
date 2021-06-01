#include<stdio.h>

int main()
{
	printf("Algoritmo R-R\n");

	int np=11, procesos[10], quantum = 0, nq = 0;
	double tf = 0, tp; //tiempo promedio
	int finalizado = 0;
	do{
		printf("cantidad de procesos:\n");
		scanf("%d", &np);
	}while(np<=0 || np>10);

	for(int i=0; i<np; i++)
	{
		printf("Inserte el proceso %d :\n", i+1);
		scanf("%d", &procesos[i]);
	}

	//Algoritmo Round Robin
	do{
		printf("Ingrese el tamanno del quantum: \n");
		scanf("%d", &quantum);
	}while(quantum <= 0);

	while(finalizado == 0){
		finalizado = 1; //para terminar ciclo

		for(int i=0; i<np; i++){
			if(procesos[i] > 0){
				procesos[i] -= quantum;
				nq++;
				printf("Quantum[%d] > proceso %d\n", nq, i+1);
				if(procesos[i] > 0)//proceso sobrevive al quantum
					finalizado = 0; //Sigue ejecución de estados
				else
					tp += nq * quantum;
			}
		}
	}

	printf("\n\nLa suma de los procesos %2.1f\n", tp);
	tp = tp / np;
	printf("\nTiempo promedio en R-R es de: %2.2f:\n", tp);
	return 0;
}