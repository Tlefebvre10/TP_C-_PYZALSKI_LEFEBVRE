//Déclaration des fonction de la classe Timers

/*! 
* \brief Fonctions du Timers
* \author Thomas LEFEBVRE & Luca PYZALSKI
*/

#include "Timers.h"

Timers::Timers()
{
	/*!
	*\brief Constructeur,  Réalise l'initialisation de l'accès mémoire et la mise à 0 des autres attributs
	*/
	io=acces_memoire(&shmid);
	if(io==NULL)
	printf("erreur pas de mem sh\n");
	_value=0;
	depart_timer=0;
	depart_timer=io->timer_sec;
}

void Timers::raz()
{
	/*!
	*\brief Remise à 0 de la valeur du compteur
	*/
	_value=0;
}
int Timers::GetValue()
{
	return ((io->timer_sec)-depart_timer);///retourne la valeur du compteur
}
