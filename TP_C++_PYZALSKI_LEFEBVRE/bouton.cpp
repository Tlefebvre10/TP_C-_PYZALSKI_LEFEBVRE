#include"bouton.h"

Bouton::Bouton()
{
	io=acces_memoire(&shmid);
	if(io==NULL)
	printf("erreur pas de mem sh\n");
	_charge=0;
	_stop=0;
}

void Bouton::SetCharge()
{
	if((io->bouton_charge)==1)
		{
		_charge=1;
		}
	else
	{
		if((io->bouton_charge)==0)
		{
			_charge=0;
		}
	
	}


}

void Bouton::SetStop()
{
	if((io->bouton_stop)==1)
		{
		_stop=1;
		}
	else
	{
		if((io->bouton_stop)==0)
		{
			_stop=0;
		}
	
	}
}

int Bouton::GetStop()
{
	return _stop;
}

int Bouton::GetCharge()
{
	return _charge;
}
