#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include"OperacionesAdministracion.h"



main()
{
	//Leer todo
	
	FILE *archProfesional;
	
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
				
			   AgregarProfesional(profesional);
			   
				printf("\n>");
				system("pause");
			break;
			
			case 2:
				system("cls");
				
				AgregarUsuario();
				
				printf("\n>");
				system("pause");
			break;
			
			case 3:
				system("cls");
				
				printf("ATENCIONES POR PROFESIONAL\n\n");
				
			    
			    printf("Ingrese id del profesional a consultar turnos:\n");
			    scanf("%d", &id);
			    
			    MostrarAtencionPorProfesional(id);
				
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
				printf("\nUd. ha salido de la aplicaci�n.\n\n>");
				
				system("pause");
			break;
			
			default:
				printf("\nUd. no ha seleccionado una opci�n existente.\n\n>");
				
				system("pause");
				
			break;
	   }
    }
	while(opcionmenu!=5);
	
	//terminar toda persistencia
	



}




