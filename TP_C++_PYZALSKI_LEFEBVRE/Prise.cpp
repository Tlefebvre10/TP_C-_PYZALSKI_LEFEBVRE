//Déclaration des fonction de la classe prise

/*! 
* \brief Fonction da la prise
* \author Thomas LEFEBVRE & Luca PYZALSKI
*/

#include"Prise.h"
#include <unistd.h>

/*!
	*\brief Constructeur,
	* Réalise l'accès à la mémoire partagé et initialise le status à 1
	*/
Prise::Prise()
{
	io=acces_memoire(&shmid);
	if(io==NULL)
	printf("erreur pas de mem sh\n");
	status=1;
	
}

/*!
	*\brief VerrouillerTrappe,
	* Réalise le verrouilage de la trappe en mettant son voyant à OFF
	*/
void Prise::VerrouillerTrappe()
{
		io->led_trappe=OFF; ///mise à OFF de la LED trappe dans l'accès mémoire
		status=0;/// mise à jour de l'état de la led dans l'attribut status
}

/*!
	*\brief DeverrouillerTrappe,
	* Réalise le deverrouilage de la trappe en mettant son voyant à VERT
	*/
void Prise::DeverrouillerTrappe()
{
		io->led_trappe=VERT; ///mise à VERT de la LED trappe dans l'accès mémoire
		status=1;/// mise à jour de l'état de la led dans l'attribut status
}

