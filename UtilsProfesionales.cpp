#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>



struct Profesional{
	char ApYNom [1];
	int IdProfesional;
	int Dni;
	char Telefono[25];
};

Profesional BuscarProfesionalPorId(int idProfesional, Profesional profesionales[50]);

main()
{
	Profesional pro;
	
	pro.ApYNom[0] = 'a';
	pro.Dni = 39975846;
	pro.IdProfesional = 1;
	
	Profesional profesionales[50];
	profesionales[0]=pro;
	
	Profesional test;
	
	test = BuscarProfesionalPorId(pro.IdProfesional, profesionales);
	
	printf("test name -> %s\n", test.ApYNom);
	printf("test dni -> %d\n", test.Dni);
	printf("test id -> %d\n", test.IdProfesional);
	printf("test ph -> %s\n", test.Telefono);
}


Profesional BuscarProfesionalPorId(int idProfesional, Profesional profesionales[50])
{
	Profesional retornoProfesional;
	
	 for(int i=0; i<50; i++)
	 {
	 	if(profesionales[i].IdProfesional == idProfesional)
	 	{
	 		retornoProfesional = profesionales[i];
		}
	 }
	 
	 return retornoProfesional;
}
