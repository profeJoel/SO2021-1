#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct asignatura{
	char codigo[6];
	char nombre[30];
	float notas[3];
}curso;

typedef struct dd_mes_anho{
	int dia;
	int mes;
	int anho;
}fecha;

typedef struct persona{
	int rut;
	char dig_verificador;
	char nombre[20];
	char apellido[20];
	fecha fecha_nacimiento;
	int telefono;
	curso cursos[5];
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

//agregar un curso a la vez
void agregar_asignatura(curso *nuevo){
	int i;
	float nota;
	
	printf("Ingrese el codigo de la asignatura: \n");
	fflush(stdin);
	getchar();
	fgets(nuevo->codigo, 6, stdin);

	printf("Ingrese el Nombre de la asignatura: \n");
	fflush(stdin);
	getchar();
	getchar();
	fgets(nuevo->nombre, 30, stdin);

	printf("Ingrese las tres notas del estudiante:\n");
	//Ingreso de notas
	for(i = 0; i < 3; i++){
		do{
			printf("Ingrese la nota %d\n", i+1);
			scanf("%f", &nota);
		}while(nota < 1 || nota > 7); //escala de 1 a 7
		nuevo->notas[i] = nota;
	}
}

//ingreso de datos en estructura
void ingreso_datos_alumno(alumnos *ingresado){
	int rut, telefono, i;
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

	fflush(stdin);
	printf("Ingrese el Apellido: \n");
	fgets(ingresado->apellido, 20, stdin);

	printf("Ingrese Fecha de Cumpleanhos:\n");
	ingreso_fecha(&ingresado->fecha_nacimiento);

	do{
		printf("Ingrese telefono:\n");
		scanf("%d", &telefono);
	}while(telefono < 10000000 || telefono > 99999999); //numero de 8 digitos
	ingresado->telefono = telefono;

	//Agregar cursos
	for(i = 0; i < 5; i++)
		agregar_asignatura(&ingresado->cursos[i]);
}

float calcular_promedio_asignatura(curso *c){
	float suma = 0, promedio;
	int i, cant_notas = 3;

	for(i = 0; i < 3; i++)
		suma += c->notas[i];
	promedio = suma/cant_notas;
	return promedio;
}

void imprimir_datos_alumno(alumnos *a){
	int i;
	printf("\n\nNombre: %s\tApellido: %s\trut: %d-%c\tfecha nacimiento: %d/%d/%d\tTelefono: %d\nAsignaturas:", a->nombre,	a->apellido,
		a->rut, a->dig_verificador, a->fecha_nacimiento.dia, a->fecha_nacimiento.mes, a->fecha_nacimiento.anho,a->telefono);
	for(i = 0; i < 5; i++)
		printf("\nCurso: %s (%s) > Promedio: %.1f\n", a->cursos[i].nombre, a->cursos[i].codigo, calcular_promedio_asignatura(&a->cursos[i]));
	printf("\n\n");
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
	int cant_alumnos = 1, i;
	alumnos estudiantes[cant_alumnos];

	for(i=0; i< cant_alumnos; i++)
		ingreso_datos_alumno(&estudiantes[i]);


	for(i=0; i< cant_alumnos; i++)
		imprimir_datos_alumno(&estudiantes[i]);


	//for(i=0; i< cant_alumnos; i++)
	//	imprimir_datos_alumno_con_edad(&estudiantes[i]);

	return 0;
}