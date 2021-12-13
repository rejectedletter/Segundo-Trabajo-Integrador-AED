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

bool verificacionnombre(int vou, char nombre[15]);
bool verificacionclave(char clave[35]);
void registracionconfirmada(int vou, char nombre[15], char contra[35]);
void atencionporprofesional();
void ranking();

main()
{
	setlocale(LC_ALL,"spanish");
	
	int opcionmenu, Usuarioprofesional;
	
	char usuario[10], clave[35], apellidonombre[60];
	
	bool filtronombre, filtroclave;
	
	do
	{
		system("cls");
		
		printf("Módulo de Administración\n");
		printf("==============================\n");
		
		printf("1.- Registrar Profesional\n");
		printf("2.- Registrar Usuario Recepcionista\n");
		printf("3.- Atencion por Profesional\n");
		printf("4.- Ranking de Profesionales  por Atencion\n\n");
		printf("5.- Cerrar la aplicación\n\n");
		
		printf("Ingrese una opción: ");
		scanf("%d", &opcionmenu);
		
		switch(opcionmenu)
		{
			case 1:
				system("cls");
				
			    Usuarioprofesional=0;
				
				printf("REGISTRAR PROFESIONAL\n\n");
				
				printf("-NOMBRE DE USUARIO\n\n");
								
				printf("Condiciones para nombre de usuario\n");
				
				printf("- Cantidad mínima 6 caracteres. Cantidad máxima 10 caracteres.\n");
				printf("- Podran ser letras, números y/o simbolos del conjunto {+,-,/,*,?,¿,!,¡}\n\n");
				printf("> Ser único para cada usuario registrado.\n");
				printf("> Comenzar con una letra minúscula.\n");
				printf("> Tener al menos 2 letras mayúsculas.\n");
				printf("> Tener como máximo 3 dígitos.\n\n");
				
				printf("Ingrese nombre de usuario: ");
				_flushall();
				gets(usuario);
				
			filtronombre=verificacionnombre(Usuarioprofesional, usuario);
				filtronombre=true;
				while(filtronombre==false)
				{
					printf("\n----------\n\n");
					
					printf("El nombre de usuario ingresado es invalido o ya fue registrado.\n");
					printf("Por favor, vuelva a intentarlo.\n");
					
					printf("\n----------\n\n");
					
					printf("Condiciones para nombre de usuario\n");
				
					printf("- Cantidad mínima 6 caracteres. Cantidad máxima 10 caracteres.\n");
					printf("- Podran ser letras, números y/o simbolos {+,-,/,*,?,¿,!,¡}\n\n");
					printf("> Debe Ser único para cada usuario registrado.\n");
					printf("> Debe Comenzar con una letra minúscula.\n");
					printf("> Debe Tener al menos 2 letras mayúsculas.\n");
					printf("> Debe Tener como máximo 3 dígitos.\n\n");
					
					printf("Ingrese nombre de usuario: ");
					_flushall();
					gets(usuario);
					
					filtronombre=verificacionnombre(Usuarioprofesional, usuario);
				}
				
				printf("\n-NOMBRE CORRECTO-\n");
				
				printf("\n----------\n\n");
				
				printf("-CONTRASEÑA DE USUARIO\n\n");
				
				printf("Condiciones para contraseña de usuario\n");
				
				printf("- Cantidad mínima 6 caracteres. Cantidad máxima 32 caracteres.\n");
				printf("- Debe contener al menos una mayúscula, una minúscula y un número.\n");
				printf("- No puede contener ningún carácter de puntuación, ni acentos, ni espacios. Sólo caracteres alfanuméricos.\n");
				printf("- No debe tener más de 3 caracteres numéricos consecutivos\n");
				printf("- No debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas (ascendentemente).\n\n");
				
				printf("Ingrese contraseña de usuario: ");
				_flushall();
				gets(clave);
				
				filtroclave = verificacionclave(clave);
			
				while(filtroclave==false)
				{
					printf("\n----------\n\n");
					
					printf("La contraseña del usuario ingresada es invalida.\n");
					printf("Por favor, vuelva a intentarlo.\n");
					
					printf("\n----------\n\n");
					
					printf("Condiciones para contraseña de usuario\n");
				
					printf("- Cantidad mínima 6 caracteres. Cantidad máxima 32 caracteres.\n");
					printf("- Debe contener al menos una mayúscula, una minúscula y un número.\n");
					printf("- No podrá contener ningún carácter de puntuación, ni acentos, ni espacios. Sólo caracteres alfanuméricos.\n");
					printf("- No debe tener más de 3 caracteres numéricos consecutivos\n");
					printf("- No debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas (ascendentemente).\n\n");
					
					printf("Ingrese contraseña de usuario: ");
					_flushall();
					gets(clave);
					
					filtroclave=verificacionclave(clave);
				}
				
				printf("\n-CONTRASEÑA CORRECTA-\n\n");
				
				registracionconfirmada(Usuarioprofesional, usuario, clave);
				
				printf("\n\n>>>USUARIO REGISTRADO CORRECTAMENTE<<<\n");
				
				printf("\n>");
				system("pause");
			break;
			
			case 2:
				system("cls");
				
				Usuarioprofesional=1;
				
				printf("REGISTRAR USUARIO RECEPCIONISTA\n\n");
				
				printf("-NOMBRE DE USUARIO\n\n");
								
				printf("Condiciones para nombre de usuario\n");
				
				printf("- Cantidad mínima 6 caracteres. Cantidad máxima 10 caracteres.\n");
				printf("- Podran ser letras, números y/o simbolos del conjunto {+,-,/,*,?,¿,!,¡}\n\n");
				printf("> Ser único para cada usuario registrado.\n");
				printf("> Comenzar con una letra minúscula.\n");
				printf("> Tener al menos 2 letras mayúsculas.\n");
				printf("> Tener como máximo 3 dígitos.\n\n");
				
				printf("Ingrese nombre de usuario: ");
				_flushall();
				gets(usuario);
				
				filtronombre=verificacionnombre(Usuarioprofesional, usuario);
				
				while(filtronombre==false)
				{
					printf("\n----------\n\n");
					
					printf("El nombre de usuario ingresado es invalido o ya fue registrado.\n");
					printf("Por favor, vuelva a intentarlo.\n");
					
					printf("\n----------\n\n");
					
					printf("Condiciones para nombre de usuario\n");
				
					printf("- Cantidad mínima 6 caracteres. Cantidad máxima 10 caracteres.\n");
					printf("- Podran ser letras, números y/o simbolos del conjunto {+,-,/,*,?,¿,!,¡}\n\n");
					printf("> Ser único para cada usuario registrado.\n");
					printf("> Comenzar con una letra minúscula.\n");
					printf("> Tener al menos 2 letras mayúsculas.\n");
					printf("> Tener como máximo 3 dígitos.\n\n");
					
					printf("Ingrese nombre de usuario: ");
					_flushall();
					gets(usuario);
					
					filtronombre=verificacionnombre(Usuarioprofesional, usuario);
				}
				
				printf("\n-NOMBRE CORRECTO-\n");
				
				printf("\n----------\n\n");
				
				printf("-CONTRASEÑA DE USUARIO\n\n");
				
				printf("Condiciones para contraseña de usuario\n");
				
				printf("- Cantidad mínima 6 caracteres. Cantidad máxima 32 caracteres.\n");
				printf("- Debe contener al menos una mayúscula, una minúscula y un número.\n");
				printf("- No podrá contener ningún carácter de puntuación, ni acentos, ni espacios. Sólo caracteres alfanuméricos.\n");
				printf("- No debe tener más de 3 caracteres numéricos consecutivos\n");
				printf("- No debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas (ascendentemente).\n\n");
				
				printf("Ingrese contraseña de usuario: ");
				_flushall();
				gets(clave);
				
				filtroclave=verificacionclave(clave);
				
				while(filtroclave==false)
				{
					printf("\n----------\n\n");
					
					printf("La contraseña del usuario ingresada es invalida.\n");
					printf("Por favor, vuelva a intentarlo.\n");
					
					printf("\n----------\n\n");
					
						printf("Condiciones para contraseña de usuario\n");
				
					printf("- Cantidad mínima 6 caracteres. Cantidad máxima 32 caracteres.\n");
					printf("- Debe contener al menos una mayúscula, una minúscula y un número.\n");
					printf("- No podrá contener ningún carácter de puntuación, ni acentos, ni espacios. Sólo caracteres alfanuméricos.\n");
					printf("- No debe tener más de 3 caracteres numéricos consecutivos\n");
					printf("- No debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas (ascendentemente).\n\n");
					
					printf("Ingrese contraseña de usuario: ");
					_flushall();
					gets(clave);
					
					filtroclave=verificacionclave(clave);
				}
				
				printf("\n-CONTRASEÑA CORRECTA-\n\n");
				
				registracionconfirmada(Usuarioprofesional, usuario, clave);
				
				printf("\n\n>>>USUARIO REGISTRADO CORRECTAMENTE<<<\n");
				
				printf("\n>");
				system("pause");
			break;
			
			case 3:
				system("cls");
				
				printf("ATENCIONES POR PROFESIONAL\n\n");
				
				atencionporprofesional();
				
				printf(">");
				system("pause");
			break;
			
			case 4:
				system("cls");
				
				printf("RANKING DE PROFESIONALES POR ATENCION\n\n");
				
				ranking();
				
				printf("\n>");
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

bool verificacionnombre(int vou, char nombre[15])
{
	int i, tamano, contadormayusculas=0, contadordigitos=0;
	
	bool controldigitos, filtro, verificacion;
	
	Usuario aux;
	
	tamano=strlen(nombre);
	
	//printf("%d", tamano);
	
	if(tamano<6 || tamano>10)
	{
		verificacion=false;
		
		return verificacion;
	}
		
	for(i=0;i<tamano;i++)
	{
		controldigitos=false;
		
		if(nombre[i]==33 || nombre[i]==42 || nombre[i]==43 || nombre[i]==45 || nombre[i]==47 || nombre[i]==63 || nombre[i]==168 || nombre[i]==173)
		{
			controldigitos=true;
			
			if(i!=0)
			{
				contadordigitos++;
			}
		}
		else
		{
			if(nombre[i]<=57 && nombre[i]>=48)
			{
				controldigitos=true;
				
				if(i!=0)
				{
					contadordigitos++;
				}
			}
			else
			{
				if(nombre[i]<=90 && nombre[i]>=65)
				{
					controldigitos=true;
					
					if(i!=0)
					{
						contadormayusculas++;
					}
				}
				else
				{
					if(nombre[i]<=122 && nombre[i]>=97)
					{
						controldigitos=true;
						
						if(i==0)
						{
							filtro=true;
						}
					}
				}
			}
		}
		
		if(controldigitos==false)
		{
			verificacion=false;
			
			return verificacion;
		}
	}
	
	if(filtro==true && contadormayusculas>=2 && contadordigitos<=3)
	{
		verificacion=true;
	}
	else
	{
		verificacion=false;
		
		return verificacion;
	}
	
	FILE *arch;
	
	if(vou==0)
	{
		arch=fopen("Profesionales.dat", "rb");
	
		if(arch==NULL)
		{
			verificacion=true;
		}
		else
		{
			fread(&aux, sizeof(Usuario), 1, arch);
			
			while(!feof(arch))
			{
				if(strcmp(nombre, aux.usuario)==0)
				{
					verificacion=false;
					
					return verificacion;
				}
				
				fread(&aux, sizeof(Usuario), 1, arch);
			}
		}
	}
	else
	{
		arch=fopen("Recepcionistas.dat", "rb");
	
		if(arch==NULL)
		{
			verificacion=true;
		}
		else
		{
			fread(&aux, sizeof(Usuario), 1, arch);
			
			while(!feof(arch))
			{
				if(strcmp(nombre, aux.usuario)==0)
				{
					verificacion=false;
					
					return verificacion;
				}
				
				fread(&aux, sizeof(Usuario), 1, arch);
			}
		}
	}
	
	fclose(arch);
	
	return verificacion;
}

bool verificacionclave(char clave[35])
{
	int i, tamano, contadormayusculas=0, contadorminusculas=0, contadornumeros=0, numdigito;
	
	bool controldigitos, filtro, verificacion;
	
	tamano=strlen(clave);
	
	//printf("%d", tamano);
	
	if(tamano<6 || tamano>32)
	{
		verificacion=false;
		
		return verificacion;
	}
	
	for(i=0;i<tamano;i++)
	{	
		if(clave[i]==32 || clave[i]==33 || clave[i]==40 || clave[i]==44 || clave[i]==45 || clave[i]==46 || clave[i]==58 || clave[i]==59 || clave[i]==63 || clave[i]==91 || clave[i]==95 || clave[i]==168 || clave[i]==173)
		{
			verificacion=false;
			
			return verificacion;
		}
		else
		{
			if(clave[i]<=57 && clave[i]>=48)
			{
				contadornumeros++;
				
				numdigito=clave[i];
				
				//printf("\n-%d-\n", numdigito);
				
				if(clave[i+1]==numdigito+1)
				{
					if(clave[i+2]==numdigito+2)
					{
						verificacion=false;
						
						return verificacion;
					}
				}
			}
			else
			{
				if(clave[i]<=90 && clave[i]>=65)
				{
					contadormayusculas++;
					
					numdigito=clave[i];
					
					if(clave[i+1]==numdigito+1 || clave[i+1]==numdigito+33)
					{
						verificacion=false;
						
						return verificacion;
					}
				}
				else
				{
					if(clave[i]<=122 && clave[i]>=97)
					{	
						contadorminusculas++;
						
						numdigito=clave[i];
						
						if(clave[i+1]==numdigito+1 || clave[i+1]==numdigito-31)
						{
							verificacion=false;
							
							return verificacion;
						}
						
					}
				}
			}
		}
	}
	
	if(contadormayusculas>0 && contadorminusculas>0 && contadornumeros>0)
	{
		verificacion=true;
		
		return verificacion;
	}
	else
	{
		verificacion=false;
		
		return verificacion;
	}
}

void registracionconfirmada(int vou, char nombre[15], char contra[35])
{
	int tamano;
	char usuario[10];
    char clave[10];
	char apeNom[60];
	
	printf("\n----------\n\n");
	
	printf("-DATOS DE USUARIO\n\n");
	
	printf("Ingresar apellido y nombre: ");
	_flushall();
				
	gets(apeNom);
	
	tamano=strlen(apeNom);
	
	if(tamano==0)
	{
		printf("\n>El campo no puede permanecer vacio. Vuelva a intentarlo.\n\n");
		
		printf("Ingresar apellido y nombre: ");
		_flushall();
					
		gets(apeNom);
		
		tamano=strlen(apeNom);
	}
	
	FILE *arch;
	
	if(vou==0)
	{
		arch=fopen("Profesionales.dat", "ab+");
	
		Usuario confirmado;
		Profesional datosconfirmado;
		
		strcpy(confirmado.usuario, usuario);
		strcpy(confirmado.clave, clave);
		strcpy(confirmado.apeNom, apeNom);
		
		fwrite(&confirmado, sizeof(Usuario), 1, arch);
		
		strcpy(datosconfirmado.apeNom, apeNom);
		
		printf("\nIngresar matricula del Profesional: ");
		scanf("%d", &datosconfirmado.idProfesional);
		
		printf("\n Ingresar DNI del Profesional: ");
		scanf("%d", &datosconfirmado.dni);
		
		printf("\nIngresar número telefonico del veterinario: ");
		scanf("%s", &datosconfirmado.telefono);
		_flushall();
		
		gets(datosconfirmado.telefono);
		
		fwrite(&datosconfirmado, sizeof(Profesional), 1, arch);
	}
	else
	{
		arch=fopen("Recepcionistas.dat", "ab+");
	
		Usuario confirmado;
		
		strcpy(confirmado.usuario, nombre);
		strcpy(confirmado.clave, clave);
		strcpy(confirmado.apeNom, apeNom);
		
		fwrite(&confirmado, sizeof(Usuario), 1, arch);
	}
	
	
	fclose(arch);
}

void atencionporprofesional()
{
	FILE *archturnos, *archcliente;
	
	int mes;
	
	bool existe=false;
	
	turnos auxturnos;
	Cliente  auxcliente;
	
	printf("Ingresar mes del que quiere conocer las atenciones: ");
	scanf("%d", &mes);
	
	archturnos=fopen("Turnos.dat", "rb");
	
	if(archturnos==NULL)
	{
		printf("Aun no se ha registrado ningún turno.\n");
	}
	else
	{
		fread(&auxturnos, sizeof(turnos), 1, archturnos);
	
		while(!feof(archturnos))
		{
			if(auxturnos.fechaTurno.mes==mes && auxturnos.borrado==true)
			{
				printf("\n----------\n\n");
				
				printf("Fecha de atención: %-0.2d/%-0.2d/%d", auxturnos.fechaTurno.dia, auxturnos.fechaTurno.mes, auxturnos.fechaTurno.anio);
								
				printf("\nDNI del Cliente: %d", auxturnos.dniCliente);
				
				printf("\nMatricula del Profesional que atendió: %d", auxturnos.idProfesional);
				
				printf("\nDetalle de la consulta: %s", auxturnos.detalle);
				
				printf("\n\n");
				
				existe=true;
			}
			
			fread(&auxturnos, sizeof(turnos), 1, archturnos);
		}
		
		if(existe==false)
		{
			printf("\n>No se ha realizado ningún turno en el mes seleccionado.\n\n");
		}
	}	
}

void ranking()
{
	FILE *archprofesional, *archturnos;
	
	int mes, idProfesional, cont, matriculamayor, contmayor=0;
	
	Usuario auxusuarios;
	Profesional auxprofesional;
	turnos auxturnos;
	
	archprofesional=fopen("Profesionales.dat", "rb");
	
	if(archprofesional==NULL)
	{
		printf("Aún no se han registrado Profesionales.\n");
	}
	else
	{
		archturnos=fopen("Turnos.dat", "rb");
	
		if(archturnos==NULL)
		{
			printf("Aún no se han registrado turnos.\n");
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
				
				idProfesional=auxprofesional.idProfesional;
				
				fread(&auxturnos, sizeof(turnos), 1, archturnos);
				
				while(!feof(archturnos))
				{
					if(idProfesional==auxturnos.idProfesional)
					{
						if(auxturnos.borrado==true && mes==auxturnos.fechaTurno.mes)
						{
							cont++;
						}
					}
					
					fread(&auxturnos, sizeof(turnos), 1, archturnos);
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
			printf("Ningún Profesional a realizado atenciones en este periodo.\n");	
		}
		else
		{
			printf("Matricula de Profesional ganador del ranking: %d\n", matriculamayor);
		}
	}
}
