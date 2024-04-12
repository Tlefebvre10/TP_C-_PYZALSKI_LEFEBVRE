#include"Generateur_Save.h"
#include <unistd.h>
Generateur_Save::Generateur_Save()
{
	io=acces_memoire(&shmid);
	if(io==NULL)
	printf("erreur pas de mem sh\n");


}

void Generateur_Save::Generer_PWM(int valeur)
{
	if(valeur==1)
	{
		(io->gene_pwm)=AC_1K;
	}
	else
	{
		if(valeur==2)
		{
			while((io->gene_u)!=6);
			(io->gene_pwm)=AC_CL;

		}		
	}
}

void Generateur_Save::Charger()
{
	io->gene_pwm=DC;
	sleep(1);
	while((io->gene_u)!=9)cout<<"waiting for connection..."<<endl;
}
void Generateur_Save::OuvrirAC()
{
	
		(io->contacteur_AC)=0;
	
}
void Generateur_Save::FermerAC()
{
	while(!((io->gene_u==6)&&(io->gene_pwm==AC_1K)));
	io->contacteur_AC=1;
}
void Generateur_Save::Deconnecter()
{
	while((io->gene_pwm)!=DC);
	OuvrirAC();
	io->led_trappe=OFF;
}

void Generateur_Save::PriseDeco()
{
	while((io->gene_pwm)!=DC);
	OuvrirAC();
	io->led_trappe=OFF;
}
