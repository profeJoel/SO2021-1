#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct dd_mes_anho{
	int dia;
	int mes;
	int anho;
}fecha;

typedef struct persona{
	int rut;
	char dig_verificador;
	char nombre[20];
	fecha fecha_nacimiento;
}alumnos;

/***********************************************************/
void ingreso_fecha(fecha *f){
	int dd, mm, aa;

	do{
		printf("Ingrese el día:\n");
		scanf("%d", &dd);
	}while(dd <= 0 || dd > 31);
	f->dia = dd;
	do{
		printf("Ingrese el mes:\n");
		scanf("%d", &mm);
	}while(mm <= 0 || mm > 12);
	f->mes = mm;
	do{
		printf("Ingrese el anho:\n");
		scanf("%d", &aa);
	}while(aa <= 0 || aa > 2021);
	f->anho = aa;
}

//ingreso de datos en estructura
void ingreso_datos_alumno(alumnos *ingresado){
	int rut;
	char dv;
	do{
		printf("Ingrese el Rut del ALumno:\n");
		scanf("%d", &rut);
	}while(rut <= 0 || rut >= 30000000);
	ingresado->rut = rut;

	fflush(stdin);
	getchar();
	do{
		printf("Ingrese el digito verificador:\n");
		scanf("%c", &dv);
	}while((dv < '0' || dv > '9') && (dv!='K' || dv != 'k'));
	ingresado->dig_verificador = dv;
	
	fflush(stdin);
	getchar();
	printf("Ingrese el Nombre: \n");
	fgets(ingresado->nombre, 20, stdin);

	printf("Ingrese Fecha de Cumpleanhos:\n");
	ingreso_fecha(&ingresado->fecha_nacimiento);
}

void imprimir_datos_alumno(alumnos *a){
	printf("\nNombre: %s\trut: %d-%c\tfecha nacimiento: %d/%d/%d", a->nombre,	
		a->rut, a->dig_verificador, a->fecha_nacimiento.dia, a->fecha_nacimiento.mes, a->fecha_nacimiento.anho);
}

int calcular_edad(fecha *f){
	time_t s;
	struct tm* fecha_actual;
	s = time(NULL);
	fecha_actual = localtime(&s);
	int anho_actual = fecha_actual->tm_year + 1900;

	int edad = anho_actual - f->anho;

	return edad;
}

void imprimir_datos_alumno_con_edad(alumnos *a){
	printf("Nombre: %s\trut: %d-%c\tedad%d\n", a->nombre,	
		a->rut, a->dig_verificador, calcular_edad(&a->fecha_nacimiento));
}

/***********************************************************/
int main(){
	int cant_alumnos = 3, i;
	alumnos estudiantes[cant_alumnos];

	for(i=0; i< cant_alumnos; i++)
		ingreso_datos_alumno(&estudiantes[i]);


	for(i=0; i< cant_alumnos; i++)
		imprimir_datos_alumno(&estudiantes[i]);


	for(i=0; i< cant_alumnos; i++)
		imprimir_datos_alumno_con_edad(&estudiantes[i]);

	return 0;
}