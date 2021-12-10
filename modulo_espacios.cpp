#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<string.h>

/*hola*/

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

void iniciarSesion(FILE *puntero,bool &iniciar);

main()
{
	system("COLOR 0A");
	FILE *arch;
	int num;
	bool inicio=false;
	
	arch = fopen("Usuarios.dat","ab");
	fclose(arch);
	arch = fopen("Profesionales.dat","ab");
	fclose(arch);
	arch = fopen("Clientes.dat","ab");
	fclose(arch);
	arch = fopen("Turnos.dat","ab");
	fclose(arch);
	
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
					arch = fopen("Usuarios.dat","ab");
					iniciarSesion(arch,inicio);
					fclose(arch);
					system("pause");
			        break;
			case 2:
					system("cls");
					if(inicio == true)
					{
						printf("\nUsted ha elegido la opcion 'Visulizar lista de espera de turnos (Informe)'\n");
					
						system("pause");
					}
					else
					{
						printf("\nUsted no ha iniciado sesion.");
					}
			        break;
			case 3:
					system("cls");
					if(inicio == true)
					{
						printf("\nUsted ha elegido la opcion 'Registrar evolucion del tratamiento'\n");
				  	
				  		system("pause");
					}
				    else
				    {
				    	printf("\nUsted no ha iniciado sesion.");
				    }
				 	break;
					
			case 4:
					break;		
		}
	}
	while(num!=4);
	
}

void iniciarSesion(FILE *puntero,bool &iniciar)
{
	Usuario user;
	char nombreDeUsuario[10];
	char clave[10];
	
	printf("\nNombre de usuario: ");
	_flushall();
	gets(nombreDeUsuario);
	
	printf("\nContraseña: ");
	_flushall();
	gets(clave);
	
	fread(&user,sizeof(Usuario),1,puntero);
	while(!feof(puntero))
	{
		if((strcmp(user.usuario,nombreDeUsuario) && strcmp(user.clave,clave)) == 0)
		{
			iniciar=true;
			printf("\nSesion iniciada!");
			break;
		}
		fread(&user,sizeof(Usuario),1,puntero);
	}
}
