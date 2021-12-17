#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include"OperacionesAdministracion.h"



main()
{
	//Leer todo
	FILE *arch;
	
		arch = fopen("Usuarios.dat","r+b"); //si no existe lo abro creando
	
	if(arch == NULL){ //
		arch = fopen("Usuarios.dat","a+b"); 
	}
	
	FILE *archProfesional;
	
		archProfesional = fopen("Profesionales.dat","r+b"); //si no existe lo abro creando
	
	if(archProfesional == NULL){ //
		archProfesional = fopen("Profesionales.dat","a+b"); 
	}
	
	FILE *archTurnos;
	
		archTurnos = fopen("Turnos.dat","r+b"); //si no existe lo abro creando
	
	if(archTurnos == NULL){ //
		archTurnos = fopen("Turnos.dat","a+b"); 
	}
	
//	FILE *archProfesional;
	
	Profesional profesional;
	Turno turnos[100];
	



	
	int opcionmenu,Usuarioprofesional;
	char usuario[10],clave[35],apellidonombre[60];
	bool filtronombre,filtroclave;
	Usuario usuarioNuevo;
	int id =0;
	do
	{
	
		MostrarMenu();
	
		scanf("%d", &opcionmenu);
	
		switch(opcionmenu)
		{
		
			case 1:
				system("cls");
				
			   AgregarProfesional(archProfesional);
			   
				printf("\n>");
				system("pause");
			break;
			
			case 2:
				system("cls");
				
				CrearUsuario(arch);
				
				printf("\n>");
				system("pause");
			break;
			
			case 3:
				system("cls");
				
				printf("ATENCIONES POR PROFESIONAL\n\n");
				
			    
			    printf("Ingrese id del profesional a consultar turnos:\n");
			    scanf("%d", &id);
			    
			    MostrarAtencionPorProfesional(id, archProfesional, archTurnos);
				
				printf(">");
				system("pause");
			break;
			
			case 4:
				system("cls");
				
				printf("RANKING DE PROFESIONALES POR ATENCION\n\n");
				
			  RankingProfesional();
				
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
    }
	while(opcionmenu!=5);
	
	//terminar toda persistencia
	



}




