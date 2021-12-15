#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

bool VerificarNomenclaturaNombreUsuario(char nombre[10])
{
	int tamano = 0;
	int contadormayusculas=0;
	int contadorNumeros = 0;
	int contadordigitos=0;
	
	bool esValido=false;
	
	
	
	tamano=strlen(nombre);
	
    if(tamano<6 || tamano>10)
	{
		esValido=false;
	}
		
	for(int i=0;i<tamano;i++)
	{
		
		if(i == 0 && nombre[i]<=122 && nombre[i]>=97)
		{
			esValido = true;
		}
		
		if(nombre[i]==33 || nombre[i]==42 || nombre[i]==43 || nombre[i]==45 || nombre[i]==47 || nombre[i]==63 || nombre[i]==168 || nombre[i]==173)
		{
			if(i!=0)
			{
				contadordigitos++;
			}
		}
		
		if(nombre[i]<=57 && nombre[i]>=48)
		{
			if(i!=0)
			{
				contadorNumeros++;
			}
		}
		
		if(nombre[i]<=90 && nombre[i]>=65)
		{
			if(i!=0)
			{
				contadormayusculas++;
			}
	   }
				
	}
	
	if(contadordigitos + contadorNumeros == 3 && contadormayusculas == 2)
	{
		esValido = true;
	}	
	
	return esValido;
	
}

bool VerificarNomenclaturaPassword(char clave[10])
{
	int tamano = 0; 
	int contadormayusculas=0, contadorminusculas=0, contadornumeros=0, numdigito;
	
	bool esValido = false;
	
	tamano=strlen(clave);
	

	
	if(tamano<6 || tamano>32)
	{
		return false;
	}
	
	for(int i=0;i<tamano;i++)
	{	
		if(clave[i]==32 || clave[i]==33 || clave[i]==40 || clave[i]==44 || clave[i]==45 || clave[i]==46 || clave[i]==58 || clave[i]==59 || clave[i]==63 || clave[i]==91 || clave[i]==95 || clave[i]==168 || clave[i]==173)
		{
			return false;
		}
		
			
			
		if(clave[i]<=57 && clave[i]>=48)
		{
			contadornumeros++;
				
			numdigito=clave[i];
				
				
				
			if(clave[i+1]==numdigito+1 && clave[i+2] == numdigito+1)
			{
				
				return false;
				
		   }
	   }
			
			
		if(clave[i]<=90 && clave[i]>=65)
		{
			contadormayusculas++;
					
			numdigito=clave[i];
					
			if(clave[i+1]==numdigito+1)
			{
				return false;
				
			}
	   }
				
		if(clave[i]<=122 && clave[i]>=97)
		{	
			contadorminusculas++;
						
			numdigito=clave[i];
						
			if(clave[i+1]==numdigito+1)
			{
				return false;
			}
						
		}
				
	}
	
	if(contadormayusculas >0 && contadorminusculas >0 && contadornumeros >0)
	{
		esValido = true;
	}
	
	return esValido;
}
