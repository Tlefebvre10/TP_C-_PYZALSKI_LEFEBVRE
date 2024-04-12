//Déclaration des fonction de la classe Bouton

/*! 
* \brief Fonction de la base client
* \author Thomas LEFEBVRE & Luca PYZALSKI
*/

#include"bouton.h"

Bouton::Bouton()
{
	/*!
	*\brief Réalise la mise à 0 des status des boutons et  réalise l'accès à la mémoire partagé
	*/
	io=acces_memoire(&shmid);
	if(io==NULL)
	printf("erreur pas de mem sh\n");
	_charge=0;
	_stop=0;
}

void Bouton::SetCharge()
{
	/*!
	*\brief Réalise la mise à jour de l'état de bouton charge
	*/
	if((io->bouton_charge)==1) /// si le bouton charge dans la mémoire partagé est appuyé:
		{
		_charge=1;///stockage du status dans la variable charge
		}
	else
	{
		if((io->bouton_charge)==0)/// si le bouton charge dans la mémoire partagé n'est pas appuyé:
		{
			_charge=0;///stockage du status dans la variable charge
		}
	
	}


}

void Bouton::SetStop()
{
	/*!
	*\brief Réalise la mise à jour de l'état de bouton Stop
	*/
	if((io->bouton_stop)==1)/// si le bouton Stop dans la mémoire partagé est appuyé:
		{
		_stop=1;///stockage du status dans la variable charge
		}
	else
	{
		if((io->bouton_stop)==0)/// si le bouton Stop dans la mémoire partagé n'est pas appuyé:
		{
			_stop=0;///stockage du status dans la variable charge
		}
	
	}
}

int Bouton::GetStop()
{
	return _stop; ///récupération de l'état du bouton Stop
}

int Bouton::GetCharge()
{
	return _charge;///récupération de l'état du bouton Charge
}
