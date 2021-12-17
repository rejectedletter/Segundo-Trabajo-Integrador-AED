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

void iniciarSesion(FILE *puntero,bool &iniciar,int &id);
void listado(FILE *puntero,FILE *puntero2,int id);
void registrarEvolucion(FILE *puntero,int id);

main()
{
	setlocale(LC_ALL,"spanish");
	system("COLOR 0A");
	FILE *arch,*p;
	int num,id;
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
		printf("\nModulo espacios\n");
    	printf("================================================");
		printf("\n\nIngrese el numero de opcion\n\n");
		printf("1.- Iniciar Sesion\n");
		printf("2.- Visulizar lista de espera de turnos (Informe)\n");
		printf("3.- Registrar evolucion del tratamiento\n");
		printf("4.- Cerrar la aplicacion\n");
		
		printf("\nOpcion a seleccionar: ");
		scanf("%d",&num);	
		
		switch(num)
		{
			case 1: 
					system("cls");
					printf("\nUsted ha elegido la opcion 'Iniciar Sesion'\n");
					arch = fopen("Profesionales.dat","rb");
					iniciarSesion(arch,inicio,id);
					fclose(arch);
					system("pause");
			        break;
			case 2:
					system("cls");
					if(inicio == true)
					{
						printf("\nUsted ha elegido la opcion 'Visulizar lista de espera de turnos (Informe)'\n");
						arch = fopen("Turnos.dat","rb");
						p = fopen("Cliente.dat","rb");
						listado(arch,p,id);
						fclose(arch);
						fclose(p);
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
				  		arch = fopen("Turnos.dat","r+b");
						registrarEvolucion(arch,id);
						fclose(arch);
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

void iniciarSesion(FILE *puntero,bool &iniciar,int &id)
{
	Usuario user;
	Profesional prof;
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
		if(strcmp(user.usuario,nombreDeUsuario) == 0)
		{
			if(strcmp(user.clave,clave) == 0)
			{
				iniciar=true;
				printf("\nSesion iniciada!");
				id=prof.idProfesional;
				break;
			}	
		}
		fread(&user,sizeof(Usuario),1,puntero);
	}
	if(iniciar == false)
	{
		printf("\nNo se ha podido iniciar sesion.\n\n");
	}
}

void listado(FILE *puntero,FILE *puntero2,int id)
{
    fecha buscar;
    Turnos paciente; 
	Cliente reg;
	
    printf("\nIngrese la fecha: ");
    printf("\nDia: ");
    scanf("%d",&buscar.dia);
    printf("\nMes: ");
    scanf("%d",&buscar.mes);
    printf("\nAnio: ");
    scanf("%d",&buscar.anio);

	system("cls");
	printf("Pacientes para ser atendidos: ");
	
	fread(&paciente,sizeof(Turnos),1,puntero);
	fread(&reg,sizeof(Cliente),1,puntero2);
    while(!feof(puntero) && !feof(puntero2))
    {
    	if(paciente.borrado == false)
    	{
    		if(buscar.dia == paciente.fechaTurno.dia && buscar.mes == paciente.fechaTurno.dia && buscar.anio == paciente.fechaTurno.anio)
    		{
    			printf("\nApellido y nombres: %s",reg.apeNom);
    			printf("\nDni: %d",reg.dniCliente);
    			printf("\nDomicilio: %s",reg.domicilio);
    			printf("\nEdad: %d",2021-reg.fecnac.anio);
				printf("\nPeso: %f",reg.peso);	
				printf("\n===========================================");
    		}
    	}
    	fread(&buscar,sizeof(fecha),1,puntero);	
    	fread(&reg,sizeof(Cliente),1,puntero2);
    } 
}

void registrarEvolucion(FILE *puntero,int id)
{
	fecha buscar;
    Turnos paciente; 
    Cliente reg;
    char buscarApeNom[60];
    bool b=false;
    	
	printf("\nIngrese el apellido y nombre del cliente que atendera: ");
    _flushall();
    gets(buscarApeNom);
    
    fread(&paciente,sizeof(Cliente),1,puntero);
    while(!feof(puntero))
    {
    	if(buscar.dia == paciente.fechaTurno.dia && buscar.mes == paciente.fechaTurno.dia && buscar.anio == paciente.fechaTurno.anio)
    	{
    		if((strcmp(buscarApeNom,reg.apeNom)==0) && paciente.borrado==false)
    		{
    			printf("\nEvolucion de los tratamientos dados: ");
    			_flushall();
    			gets(paciente.detalleAtencion);
    			printf("\n\nIngrese la fecha de atencion: ");
    			printf("\nDia: ");
    			scanf("%d",&paciente.fechaTurno.dia);
    			printf("\nMes: ");
    			scanf("%d",&paciente.fechaTurno.mes);
    			printf("\nAnio: ");
    			scanf("%d",&paciente.fechaTurno.anio);
    			paciente.idProfesional = id;
    			paciente.borrado = true;
    			b=true;
    		}
    	}
    	fread(&buscar,sizeof(fecha),1,puntero);	
    }

	if(b==false)
	{
		printf("\nError. Apellido y nombres incorrectos.");
	}
}
