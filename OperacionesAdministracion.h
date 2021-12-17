#include<windows.h>
#include <conio.h>
#include<stdio.h>
#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include "validaciones.h"



struct Fecha{

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
	int id;
	int  dni;
	char telefono[25];
};


struct Cliente 
{
	char apeNom [60];
	char domicilio[60];
	int dniCliente;
	char localidad [60];
	Fecha fecnac ;
	float peso ;
	char telefono[25];
};

struct Turno
{
	int idProfesional;
	Fecha fechaTurno;
	int dniCliente;
	char detalle [380];	
	bool borrado;
};



void MostrarMenu()
{
	setlocale(LC_ALL,"spanish");
	system("COLOR 0A");
	
	system("cls");
		
		printf("\nM�dulo de Administraci�n\n");
		printf("===========================================\n\n");
		
		printf("1.- Registrar Profesional\n");
		printf("2.- Registrar Usuario Recepcionista\n");
		printf("3.- Atenci�n por Profesional\n");
		printf("4.- Ranking de Profesionales por Atenci�n\n\n");
		printf("5.- Cerrar la aplicaci�n\n\n");
		
		printf("Ingrese una opci�n: ");
}

void CrearNombreUsuario(Usuario usuarioNuevo)
{
	printf("REGISTRAR PROFESIONAL\n\n");
				char usuario[10];
				bool esValido = false;
				
				printf("-NOMBRE DE USUARIO\n\n");
								
				printf("Condiciones para nombre de usuario\n");
				
				printf("- Cantidad m�nima 6 caracteres. Cantidad m�xima 10 caracteres.\n");
				printf("- Podran ser letras, n�meros y/o simbolos del conjunto {+,-,/,*,?,�,!,�}\n\n");
				printf("> Ser �nico para cada usuario registrado.\n");
				printf("> Comenzar con una letra min�scula.\n");
				printf("> Tener al menos 2 letras may�sculas.\n");
				printf("> Tener como m�ximo 3 d�gitos.\n\n");
				
				printf("Ingrese nombre de usuario: ");
				_flushall();
				gets(usuario);
				
				esValido = VerificarNomenclaturaNombreUsuario(usuario);
			
				
				while(!esValido){
				
				
					printf("\n----------\n\n");
					
					printf("El nombre de usuario ingresado es invalido o ya fue registrado.\n");
					printf("Por favor, vuelva a intentarlo.\n");
					
					printf("\n----------\n\n");
					
					printf("Condiciones para nombre de usuario\n");
				
					printf("- Cantidad m�nima 6 caracteres. Cantidad m�xima 10 caracteres.\n");
					printf("- Podran ser letras, n�meros y/o simbolos {+,-,/,*,?,�,!,�}\n\n");
					printf("> Debe Ser �nico para cada usuario registrado.\n");
					printf("> Debe Comenzar con una letra min�scula.\n");
					printf("> Debe Tener al menos 2 letras may�sculas.\n");
					printf("> Debe Tener como m�ximo 3 d�gitos.\n\n");
					
					printf("Ingrese nombre de usuario: ");
					_flushall();
					gets(usuario);
					
					esValido = VerificarNomenclaturaNombreUsuario(usuario);
				}
				
	strcpy(usuarioNuevo.usuario, usuario);
				
	   
}

int GenerarIdAsc()
{
	Profesional pro;
	int id =0;
	int cont =0;
	
	FILE *pros;
	pros = fopen("Profesionales.dat", "rb");
	
	fread(&pro, sizeof(Profesional), 1, pros);


	/*fseek(pros, 0, SEEK_END);
	if(ftell(pros)==0)
	{
		return 1;
	}*/
		
	while(!feof(pros))
	{
		id = pro.id;
		printf("%d", pro.id);
		fread(&pro, sizeof(Profesional), 1, pros);
	}
	
	return id + 1;
}

int CrearUsuario(FILE *arch)
{
	Usuario usuarioNuevo;
	
	int esValido =0;
	char clave [10];
	char usuario [10];
	
	printf("REGISTRAR PROFESIONAL\n\n");
				
	printf("-NOMBRE DE USUARIO\n\n");
								
	printf("Condiciones para nombre de usuario\n");
				
	printf("- Cantidad m�nima 6 caracteres. Cantidad m�xima 10 caracteres.\n");
	printf("- Podran ser letras, n�meros y/o simbolos del conjunto {+,-,/,*,?,�,!,�}\n\n");
	printf("> Ser �nico para cada usuario registrado.\n");
	printf("> Comenzar con una letra min�scula.\n");
	printf("> Tener al menos 2 letras may�sculas.\n");
	printf("> Tener como m�ximo 3 d�gitos.\n\n");
				
	printf("Ingrese nombre de usuario: ");
	_flushall();
	gets(usuario);
				
	esValido = VerificarNomenclaturaNombreUsuario(usuario);
			
	while(esValido==0){
				
	printf("\n----------\n\n");
	printf("El nombre de usuario ingresado es invalido o ya fue registrado.\n");
	printf("Por favor, vuelva a intentarlo.\n");
	printf("\n----------\n\n");
	printf("Condiciones para nombre de usuario\n");
	printf("- Cantidad m�nima 6 caracteres. Cantidad m�xima 10 caracteres.\n");
	printf("- Podran ser letras, n�meros y/o simbolos {+,-,/,*,?,�,!,�}\n\n");
	printf("> Debe Ser �nico para cada usuario registrado.\n");
	printf("> Debe Comenzar con una letra min�scula.\n");
	printf("> Debe Tener al menos 2 letras may�sculas.\n");
	printf("> Debe Tener como m�ximo 3 d�gitos.\n\n");
					
	printf("Ingrese nombre de usuario: ");
	_flushall();
	gets(usuario);
					
	esValido = VerificarNomenclaturaNombreUsuario(usuario);
	}
	
	printf("\n\n>>>NOMBRE DE USUARIO CORRECTO<<<\n");
	
	strcpy(usuarioNuevo.usuario, usuario);
	
	
    printf("\n----------\n\n");
				
	printf("-CONTRASE�A DE USUARIO\n\n");
				
	printf("Condiciones para contrase�a de usuario\n");
				
	printf("- Cantidad m�nima 6 caracteres. Cantidad m�xima 32 caracteres.\n");
	printf("- Debe contener al menos una may�scula, una min�scula y un n�mero.\n");
	printf("- No podr� contener ning�n car�cter de puntuaci�n, ni acentos, ni espacios. S�lo caracteres alfanum�ricos.\n");
	printf("- No debe tener m�s de 3 caracteres num�ricos consecutivos\n");
	printf("- No debe tener 2 caracteres consecutivos que refieran a letras alfab�ticamente consecutivas (ascendentemente).\n\n");
				
	printf("Ingrese contrase�a de usuario: ");
	_flushall();
	gets(clave);
				
	esValido = VerificarNomenclaturaPassword(clave);
	_flushall();
	printf("%s", clave);
				
	while(esValido==0)
	{
		printf("\n----------\n\n");
					
		printf("La contrase�a del usuario ingresada es invalida.\n");
		printf("Por favor, vuelva a intentarlo.\n");
					
		printf("\n----------\n\n");
					
		printf("Condiciones para contrase�a de usuario\n");
				
		printf("- Cantidad m�nima 6 caracteres. Cantidad m�xima 32 caracteres.\n");
		printf("- Debe contener al menos una may�scula, una min�scula y un n�mero.\n");
		printf("- No podr� contener ning�n car�cter de puntuaci�n, ni acentos, ni espacios. S�lo caracteres alfanum�ricos.\n");
		printf("- No debe tener m�s de 3 caracteres num�ricos consecutivos\n");
		printf("- No debe tener 2 caracteres consecutivos que refieran a letras alfab�ticamente consecutivas (ascendentemente).\n\n");
					
		printf("Ingrese contrase�a de usuario: ");
		_flushall();
		gets(clave);
					
		esValido = VerificarNomenclaturaPassword(clave);
	}
				
		printf("\n-CONTRASE�A CORRECTA-\n\n");
		_flushall();
		strcpy(usuarioNuevo.clave, clave);
				
		printf("\n----------\n\n");
					
		printf("Ingrese apellido y nombre: ");
		scanf("%s",&usuarioNuevo.apeNom);
				
		printf("\n\n>>>USUARIO REGISTRADO CORRECTAMENTE<<<\n");
				
		printf("\n>");
		system("pause");
   
	
	
	
	int contador = 1; //para validar si se carga el registro
	try{ // try para manejar excepciones si se produce una pasa al catch
		if (fwrite(&usuarioNuevo,sizeof(Usuario),contador,arch) < contador)
		{
		    printf("\nError al guardar el registro...");
		    exit(EXIT_FAILURE);
		}	
		return 0;
	}
	catch (int e)
	{
	    return 1;
	}		
	
	
}

int AgregarProfesional(FILE *arch)
{
	Profesional profesionalNuevo;
	int tamano =0;
	int contador=1;
	
	
	printf("-DATOS DE PROFESIONAL\n\n");
	
	printf("Ingresar apellido y nombre: ");
	_flushall();
				
	gets(profesionalNuevo.apeNom);
	
	tamano=strlen(profesionalNuevo.apeNom);
	
	if(tamano==0)
	{
		printf("\n>El campo no puede permanecer vacio. Vuelva a intentarlo.\n\n");
		
		printf("Ingresar apellido y nombre: ");
		_flushall();
					
		gets(profesionalNuevo.apeNom);
		
		tamano=strlen(profesionalNuevo.apeNom);
	}
	
		
	
		
		profesionalNuevo.id = GenerarIdAsc();
		
		printf("\n Ingresar DNI del Profesional: ");
		_flushall();
		scanf("%d", &profesionalNuevo.dni);
		
		printf("\n Ingresar telefono del Profesional: ");
		_flushall();
		gets(profesionalNuevo.telefono);

	
			
		
		try{ // try para manejar excepciones si se produce una pasa al catch
		if (fwrite(&profesionalNuevo,sizeof(Profesional),1,arch) < contador)
		{
		    printf("\nError al guardar el registro...");
		    exit(EXIT_FAILURE);
		}	
		return 0;
	}
	catch (int e)
	{
	    return 1;
	}	
	

		
		
		
	
		
		
	
	
	
}

 

int MostrarAtencionPorProfesional(int idProfesional, FILE *profesionales, FILE *turnos)
{
	Profesional profesional;
	Turno turno;
	char nombreProfesional[60];
	
	fread(&profesional, sizeof(Profesional), 1, profesionales);
	fread(&turno, sizeof(Turno), 1, turnos);
	
	printf("pro %d", profesional.id);	
	
	int existeProfesional =0;
	
	while(!feof(profesionales))
	{
		if(profesional.id == idProfesional)
		{
			existeProfesional = 1;
		}
		
		fread(&profesional, sizeof(Profesional), 1, profesionales);
	}
	
	if(existeProfesional == 0)
	{
		printf("No se encontr� profesional\n");
		return 0;
	}
	else
	{
		strcpy(nombreProfesional, profesional.apeNom);
		printf("Profesional: %s\n", nombreProfesional);
	}
	
	
	
	if(turnos == NULL || strcmp(turno.detalle, ""))
	{
		printf("No se encontraron turnos\n");
		return 0;
	}
	
	/*if(profesional.idProfesional==idProfesional)
	{
		strcpy(nombreProfesional, profesional.apeNom);
		printf("Profesional: %s\n", nombreProfesional);
	}*/
	
	
	while(!feof(turnos))
	{
		while(!feof(profesionales))
		{
			if(turno.idProfesional==idProfesional)
					{
						printf("\n----------\n\n");
				
						printf("Fecha de atenci�n: %-0.2d/%-0.2d/%d", turno.fechaTurno.dia, turno.fechaTurno.mes, turno.fechaTurno.anio);
								
						printf("\nDNI del Cliente: %d", turno.dniCliente);
						
						printf("\nMatricula del Profesional que atendi�: %d", turno.idProfesional);
						
						
				
						printf("\nDetalle de la consulta: %s", turno.detalle);
				
						printf("\n\n");
					}
					
					fread(&profesional, sizeof(Profesional), 1, profesionales);
		}
		
		fread(&turno, sizeof(Turno), 1, turnos);
	}
	
	
	
		
	return 1;	
		
	
	}	
	
int RankingProfesional()
	{
			
	FILE *archprofesional, *archturnos;
	
	int mes, idProfesional, cont, matriculamayor, contmayor=0;
	
	Usuario auxusuarios;
	Profesional auxprofesional;
	Turno auxturnos;
	
	archprofesional=fopen("Profesionales.dat", "rb");
	
	if(archprofesional==NULL)
	{
		printf("A�n no se han registrado Profesionales.\n");
	}
	else
	{
		archturnos=fopen("Turnos.dat", "rb");
	
		if(archturnos==NULL)
		{
			printf("A�n no se han registrado turnos.\n");
		}
		else
		{
			printf("Ingresar mes del que quiere conocer el ranking: ");
			scanf("%d", &mes);
			
			printf("\n\n");
			
			fread(&auxusuarios, sizeof(Usuario), 1, archprofesional);
	
			while(!feof(archprofesional))
			{
				cont=0;
				
				fread(&auxprofesional, sizeof(Profesional), 1, archprofesional);
				
				idProfesional=auxprofesional.id;
				
				fread(&auxturnos, sizeof(Turno), 1, archturnos);
				
				while(!feof(archturnos))
				{
					if(idProfesional==auxturnos.idProfesional)
					{
						if(auxturnos.borrado==true && mes==auxturnos.fechaTurno.mes)
						{
							cont++;
						}
					}
					
					fread(&auxturnos, sizeof(Turno), 1, archturnos);
				}
				
				fseek(archturnos, 0, SEEK_SET);
				
				printf("Matricula: %d", idProfesional);
				printf("\nCantidad de atenciones: %d", cont);
				
				printf("\n\n----------\n\n");
				
				if(cont>contmayor)
				{
					contmayor=cont;
					matriculamayor=idProfesional;
				}
				
				fread(&auxusuarios, sizeof(Usuario), 1, archprofesional);
			}
		}
		
		if(contmayor==0)
		{
			printf("Ning�n Profesional a realizado atenciones en este periodo.\n");	
		}
		else
		{
			printf("Matricula de Profesional ganador del ranking: %d\n", matriculamayor);
		}
}
	}
	


