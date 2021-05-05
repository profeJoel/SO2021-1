#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct licence_plate{
	char left[3];
	char center[3];
	int right;
}licence;

typedef struct color_rgb{
	int r;
	int g;
	int b;
}color;

typedef struct vehiculo{
	licence id;
	char brand[20];
	char model[20];
	color car_color;
	int year;
}car;

/************************************************************************/

//Ingreso de valores a estructura car
void add_new_car(licence id, char *brand, char *model, color car_color, int year, car *new)
{
	new->id = id;
	strcpy(new->brand, brand);
	strcpy(new->model, model);
	new->car_color = car_color;
	new->year = year;
}

void add_licence_plate_info(licence *new)
{
	printf("Add left info:\n");
	fflush(stdin);
	getchar();
	fgets(new->left, 3, stdin);

	printf("Add center info:\n");
	fflush(stdin);
	getchar();
	fgets(new->center, 3, stdin);

	printf("Add right info:\n");
	fflush(stdin);
	getchar();
	scanf("%d", &new->right);
}

void add_color_info(color *new)
{
	do{
		printf("Add R number (0-255):\n");
		scanf("%d", & new->r);
	}while(new->r < 0 || new->r >255);
	do{
		printf("Add G number (0-255):\n");
		scanf("%d", & new->g);
	}while(new->g < 0 || new->g >255);
	do{
		printf("Add B number (0-255):\n");
		scanf("%d", & new->b);
	}while(new->b < 0 || new->b >255);
}

//Ingresar los valores desde el usuario para estructura car
void read_user_data(car *new_car)
{
	licence id_aux;
	char brand_aux[20], model_aux[20];
	color car_color_aux;
	int year_aux;

	printf("Add car information: \n");
	printf("Licence Plate: \n");
	add_licence_plate_info(&id_aux);

	printf("Brand:\n");
	getchar();
	fflush(stdin);
	fgets(brand_aux, 20, stdin);

	printf("Model:\n");
	getchar();
	fflush(stdin);
	fgets(model_aux, 20, stdin);

	printf("Color:\n");
	add_color_info(&car_color_aux);

	do{
		printf("Year:\n");
		scanf("%d", &year_aux);
	}while(year_aux < 1900 || year_aux > 2021);

	add_new_car(id_aux, brand_aux, model_aux, car_color_aux, year_aux, new_car);
}


void show_licence_plate(licence *id)
{
	printf("%s-%s-%d\n", id->left, id->center, id->right);
}

void show_color(color *new_color)
{
	printf("[%d,%d,%d]\n", new_color->r,new_color->g,new_color->b);
}

//Mostrar datos de autos
void show_car_data(car *new)
{
	printf("\n\nLicence: ");
	show_licence_plate(&new->id);
	printf("Brand: %s - Model: %s\n", new->brand, new->model);
	printf("Color: ");
	show_color(&new->car_color);
	printf("Year: %d\n", new->year);
}




/************************************************************************/

int main()
{
	int i, n = 3;
	car registro_circulacion[n];

	for(i=0; i<n;i++)
		read_user_data(&registro_circulacion[i]);


	for(i=0; i<n;i++)
		show_car_data(&registro_circulacion[i]);

	return 0;
}