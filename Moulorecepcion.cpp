#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

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

struct  Profesional
{
	char apeNom [60];
	int idProfesional;
	int  dni;
	char telefono[25];
};


struct Cliente 
{
	char apeNom [60];
	char domicilio[60];
	int dniCliente;
	char localidad [60];
	fecha fecnac ;
	float peso ;
	char telefono[25];
};

struct turnos
{
	int idProfesional;
	fecha fechaTurno;
	int dniCliente;
	char detalle [380];	
	bool borrado;
};

bool iniciosesion();
void registroCliente();
void registroturno();
void listadoturnos();

main()
{
	system("COLOR 0A");
	setlocale(LC_ALL,"spanish");
	
	int opcionmenu, intentarnuevamente;
	
	bool usuarioconfirmado, iniciado=false;
	
	do{
		system("cls");
		
		printf("\nMódulo de Recepción\n");
		printf("=================================================\n\n");
		
		printf("1.- Iniciar sesión\n");
		printf("2.- Registrar Cliente\n");
		printf("3.- Registrar turno\n");
		printf("4.- Listado de Atenciones por Especialista y Fecha\n\n");
		
		printf("5.- Cerrar la aplicación\n\n");
		
		printf("Ingrese una opción: ");
		scanf("%d", &opcionmenu);
		
		switch(opcionmenu)
		{
			case 1:
				system("cls");
				
				printf("-INICIO DE SESIÓN-\n\n");
				
				usuarioconfirmado=iniciosesion();
				
				if(usuarioconfirmado==true)
				{
					printf("\n>Se ha iniciado sesión.");
					
					iniciado=true;
				}
				
				while(usuarioconfirmado==false)
				{
					printf("\nEl usuario o la contraseña ingresada son incorrectas.");
					
					printf("\n\n----------\n\n");
					
					do
					{
						printf("¿Quiere intentarlo nuevamente?");
						printf("\n1.- Si");
						printf("\n2.- No");
						
						printf("\n\nOpcion: ");
						scanf("%d", &intentarnuevamente);
						
						switch(intentarnuevamente)
						{
							case 1:
								//
							break;
							
							case 2:
								//
							break;
							
							default:
								printf("\nLa opción ingresada es inexistente. Intentelo nuevamente.");
							break;
						}
						
						printf("\n\n----------\n\n");												
						
					}while(intentarnuevamente!=1 && intentarnuevamente!=2);
					
					if(intentarnuevamente==1)
					{
						usuarioconfirmado=iniciosesion();
					}
					
					if(usuarioconfirmado==true)
					{
						printf("\n>Se ha iniciado sesión.");
						
						iniciado=true;
					}
					
					if(intentarnuevamente==2)
					{
						usuarioconfirmado=true;
					}
				}
				
				printf("\n>");
				system("pause");
			break;
			
			case 2:
				system("cls");
				
				printf("-REGISTRO DE CLIENTE-\n\n");
				
				if(iniciado==true)
				{
					registroCliente();
					
					printf("\nEL Cliente se ha registrado con éxito.\n");
				}
				else
				{
					printf("Aún no se ha iniciado sesión.\n");
				}
				
				printf("\n>");
				system("pause");
			break;
			
			case 3:
				system("cls");
				
				printf("-REGISTRO DE TURNO-\n\n");
				
				if(iniciado==true)
				{
					registroturno();
					
					printf("\nEl turno se ha registrado con éxito.\n");
				}
				else
				{
					printf("Aún no se ha iniciado sesión.\n");
				}
				
				printf("\n>");
				
				system("pause");
			break;
			
			case 4:
				system("cls");
				
				printf("-LISTADO DE ATENCIONES-\n\n");
				
				if(iniciado==true)
				{
					listadoturnos();
				}
				else
				{
					printf("Aún no se ha iniciado sesión.\n");
				}
				
				printf("\n\n>");
				system("pause");
			break;
			
			case 5:
				printf("\nUd. ha salido de la aplicación.\n\n>");
				
				system("pause");
			break;
			
			default:
				printf("\nUd. no ha seleccionado una opción existente.\n\n>");
				
				system("pause");
				
			break;
		}
		
	}while(opcionmenu!=5);
}

bool iniciosesion()
{
	FILE *arch;
	
	Usuario comparacion;
	
	bool confirmacion=false;
	
	char usuario[15],contrasena[35];	
		
	arch=fopen("Recepcionistas.dat","rb");
	
	if(arch==NULL)
	{
		printf("No existe ningún usuario registrado hasta el momento.");
		
		confirmacion=false;
	}
	else
	{
		printf("Usuario: ");
		_flushall();
		
		gets(usuario);
		
		printf("Contraseña: ");
		_flushall();
		
		gets(contrasena);
		
		fread(&comparacion, sizeof(Usuario),1,arch);
	
		while(!feof(arch))
		{
			if(strcmp(usuario,comparacion.usuario)==0)
			{
				if(strcmp(contrasena,comparacion.clave)==0)
				{
					confirmacion=true;
				}
			}
			
			fread(&comparacion, sizeof(Usuario), 1, arch);
		}
	}
	return confirmacion;
}

void registroCliente()
{
	FILE *arch;
	
	Cliente registro;
	
	printf("Apellido y Nombre: ");
	_flushall();
	
	gets(registro.apeNom);
	
	printf("\nDomicilio: ");
	_flushall();
	
	gets(registro.domicilio);
	
	printf("\nDNI: ");
	scanf("%d", &registro.dniCliente);
	
	printf("\nFecha de nacimiento: ");
	printf("\nDia: ");
	scanf("%d", &registro.fecnac.dia);	
	printf("Mes: ");
	scanf("%d", &registro.fecnac.mes);
	printf("Año: ");
	scanf("%d", &registro.fecnac.anio);
	
	printf("\nLocalidad: ");
	_flushall();
	
	gets(registro.localidad);
	
	printf("\nPeso: ");
	scanf("%f", &registro.peso);
	
	printf("\nNúmero telefonico: ");
	_flushall();
	
	gets(registro.telefono);
	
	arch=fopen("Cliente.dat", "ab+");
	
	fwrite(&registro, sizeof(Cliente), 1, arch);
	
	fclose(arch);
}

void registroturno()
{
	FILE *arch;
	
	int matricula, dni;
	
	bool matriculaencontrada=false, dniencontrado=false;
	
	Usuario aux;
	Profesional aux2;
	Cliente aux3;
	
	turnos registro;
	
	printf("Matricula de especialista que va a atender a la Cliente: ");
	scanf("%d", &matricula);
	
	arch=fopen("Profesionales.dat", "rb");
	
	fread(&aux, sizeof(Usuario), 1, arch);
	
	while(!feof(arch))
	{
		fread(&aux2, sizeof(Profesional), 1, arch);
		
		if(matricula==aux2.idProfesional)
		{
			matriculaencontrada=true;
		}
		
		fread(&aux, sizeof(Usuario),1,arch);
	}
	
	fclose(arch);
	
	while(matriculaencontrada==false)
	{
		printf("\n>La matricula ingresada no pertenece a ningún Profesional. Intentelo nuevamente.\n\n");
		
		printf("Matricula deL Profesional  que va a atender a la Cliente: ");
		scanf("%d", &matricula);
		
		arch=fopen("Profesionales.dat","rb");
		
		fread(&aux, sizeof(Usuario),1,arch);
		
		while(!feof(arch))
		{
			fread(&aux2, sizeof(Profesional),1,arch);
			
			if(matricula==aux2.idProfesional)
			{
				matriculaencontrada=true;
			}
			
			fread(&aux, sizeof(Usuario),1,arch);
		}
		
		fclose(arch);
	}
	
	registro.idProfesional=matricula;
	
	printf("\nFecha de la consulta: ");
	printf("\nDia: ");
	scanf("%d", &registro.fechaTurno.dia);	
	printf("Mes: ");
	scanf("%d", &registro.fechaTurno.mes);
	printf("Año: ");
	scanf("%d", &registro.fechaTurno.anio);
	
	printf("\nDNI del Cliente: ");
	scanf("%d", &dni);
	
	arch=fopen("Cliente.dat", "rb");
	
	fread(&aux3, sizeof(Cliente), 1, arch);
	
	while(!feof(arch))
	{
		if(dni==aux3.dniCliente)
		{
			dniencontrado=true;
		}
		
		fread(&aux3, sizeof(Cliente), 1, arch);
	}
	
	fclose(arch);
	
	while(dniencontrado==false)
	{
		printf("\n>EL DNI no pertenece a ningún Cliente registrado. Intentelo nuevamente.\n\n");
		
		printf("DNI del Cliente: ");
		scanf("%d", &dni);
		
		arch=fopen("Cliente.dat", "rb");
		
		fread(&aux3, sizeof(Cliente),1,arch);
		
		while(!feof(arch))
		{
			if(dni==aux3.dniCliente)
			{
				dniencontrado=true;
			}
			
			fread(&aux3, sizeof(Cliente),1,arch);
		}
		
		fclose(arch);
	}
	
	registro.dniCliente=dni;
	
	registro.detalle[0]='-';
	
	registro.borrado=false;
	
	arch=fopen("Turnos.dat", "ab+");
	
	fwrite(&registro, sizeof(turnos), 1, arch);
	
	fclose(arch);
}

void listadoturnos()
{
	FILE *arch, *arch2;
	
	turnos registro;
	Cliente aux;
	
	int i, dni;
	
	char Cliente[60];
	
	arch=fopen("Turnos.dat", "rb");
	arch2=fopen("Cliente.dat", "rb");
	
	if(arch==NULL)
	{
		printf("Todavía no se han registrado turnos.\n");
	}
	else
	{	
		printf("%*s|%*s|%*s\n", -14, "FECHA", -12, "MATRICULA", -30, "CLIENTE");
	
		for(i=0;i<50;i++)
		{
			printf("=");
		}
		
		printf("\n");
		
		fread(&registro, sizeof(turnos), 1, arch);

		while(!feof(arch))
		{
			dni=registro.dniCliente;
			
			fread(&aux, sizeof(Cliente), 1, arch2);
			
			while(!feof(arch2))
			{	
				if(dni==aux.dniCliente)
				{
					strcpy(Cliente,aux.apeNom);
				}
				
				fread(&aux,sizeof(Cliente),1,arch2);
			}
			
			fseek(arch2, 0, SEEK_SET);
			
			if(registro.borrado==false)
			{
				printf("%-0.2d/%-0.2d/%*d|%*d|%*s\n", registro.fechaTurno.dia, registro.fechaTurno.mes, -8, registro.fechaTurno.anio, -12, registro.idProfesional, -30, Cliente);
			}
			
			fread(&registro, sizeof(turnos), 1, arch);
		}
		
		fclose(arch);
		
		fclose(arch2);
	}
	
}
