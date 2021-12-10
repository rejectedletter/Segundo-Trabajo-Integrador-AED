#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<string.h>

struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct Usuario
{
    char usuario[10];
    char clave[10];
    char apeNom[60];
};

struct Profesional
{
    char apeNom[60];
    int idProfesional;
    int dni;
    char telefono[25];
};

struct Cliente
{
    char apeNom[60];
    char domicilio[60];
	int dniCliente;
    char localidad[60];
    fecha fecnac;
    float peso;
	char telefono[25];
    
};

struct Turnos
{
    int idProfesional;
    fecha fechaTurno;
    int dniCliente;
    char detalleAtencion[380];
};

void iniciarSesion();

main()
{
	system("COLOR 0A");
	int num;
	
	
	cargar_registros(num_usuarios,num_vets,num_mascotas,num_turnos);
	do
	{
		system("cls");
		printf("Modulo espacios\n");
    	printf("========================================================================");
		printf("\n\nIngrese el numero de opcion\n\n");
		printf("1---> Iniciar Sesion\n");
		printf("2---> Visulizar lista de espera de turnos (Informe)\n");
		printf("3---> Registrar evolucion del tratamiento\n");
		printf("4---> Salir\n");
		
		printf("\nOpcion a seleccionar: ");
		scanf("%d",&num);	
		
		switch(num)
		{
			case 1: 
					system("cls");
					printf("\nUsted ha elegido la opcion 'Iniciar Sesion'\n");
					iniciarSesion();
					system("pause");
			        break;
			case 2:
					system("cls");
					printf("\nUsted ha elegido la opcion 'Visulizar lista de espera de turnos (Informe)'\n");
					
					system("pause");
			        break;
			case 3:
					system("cls");
				    printf("\nUsted ha elegido la opcion 'Registrar evolucion del tratamiento'\n");
				  	
				  	system("pause");
				 	break;
					
			case 4:
					break;		
		}
	}
	while(num!=4);
	
	
	
	
}
