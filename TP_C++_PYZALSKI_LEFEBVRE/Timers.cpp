#include "Timers.h"

Timers::Timers()
{
	io=acces_memoire(&shmid);
	if(io==NULL)
	printf("erreur pas de mem sh\n");
	_value=0;
	depart_timer=0;
	depart_timer=io->timer_sec;
}

void Timers::raz()
{
	_value=0;
}
int Timers::GetValue()
{
	return ((io->timer_sec)-depart_timer);
}
