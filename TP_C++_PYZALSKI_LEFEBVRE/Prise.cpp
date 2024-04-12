#include"Prise.h"
#include <unistd.h>

Prise::Prise()
{
	io=acces_memoire(&shmid);
	if(io==NULL)
	printf("erreur pas de mem sh\n");
	status=1;
	
}

void Prise::VerrouillerTrappe()
{
		io->led_trappe=OFF;
		status=0;
}

void Prise::DeverrouillerTrappe()
{
		io->led_trappe=VERT;
		status=1;
	
}

void Prise::SetPrise()
{
	


}
