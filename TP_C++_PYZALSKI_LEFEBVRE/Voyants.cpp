#include"voyants.h"
#include"Timers.h"

Voyants::Voyants();
{
	io=acces_memoire(&shmid);
	if(io==NULL)
	printf("erreur pas de mem sh\n");
	Timers Tim_1;
	
}

void Voyants::SetDispo()
{
	if(Dispo==0)
	{
		io->led_dispo=VERT;
		Dispo=1;
	}
	if(Dispo==1)
	{
		io->led_dispo=OFF;
		Dispo=0;
	}
}
int Voyants::GetDispo()
{
	return Dispo;
}
void Voyants::SetCharge()
{
	if(Charge==0)
	{
		io->led_charge=VERT;
		Charge=1;
	}
	if(Charge==1)
	{
		io->led_charge=OFF;
		Charge=0;
	}
}

void Voyants::SetBlinkCharge()
{
	Tim_1.raz();
	while((Tim_1.GetValue()<8)
	 {
	 	io->led_charge=VERT;
	 	sleep(1);
	 	io->led_charge=OFF;
	 	sleep(1);
	 
	 }
	


}
