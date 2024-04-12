//Déclaration des fonction de la classe Voyants

/*! 
* \brief Fonctions des voyants
* \author Thomas LEFEBVRE & Luca PYZALSKI
*/

#include"voyants.h"
#include"Timers.h"

Voyants::Voyants();
{
	/*!
	*\brief Constructeur,  Réalise l'initialisation de l'accès mémoire et l'instanciation de la classe Timer en un objet Tim_1
	*/
	io=acces_memoire(&shmid);
	if(io==NULL)
	printf("erreur pas de mem sh\n");
	Timers Tim_1;/// Création de l'objet Tim_1
	
}

void Voyants::SetDispo()
{
		/*!
	*\brief SetDispo
	*Si l'attribut dispo est à 0, il le met à vert et si il état à 1, il met OFF
	*/
	if(Dispo==0) ///Si l'attribut vaut 0:
	{
		io->led_dispo=VERT;///Mise de la led  dispo à VERT
		Dispo=1;///Mise à jour du status (vert donc 1)
	}
	if(Dispo==1)///Si l'attribut vaut 1:
	{
		io->led_dispo=OFF;///Mise de la led  dispo à OFF
		Dispo=0;///Mise à jour du status (off donc 0)
	}
}
int Voyants::GetDispo()
{
	return Dispo; ///retourne l'état actuel de dispo
}
void Voyants::SetCharge()
{
		/*!
	*\brief SetCharge
	*Si l'attribut charge est à 0, il le met à vert et si il état à 1, il met OFF
	*/
	if(Charge==0)///Si l'attribut vaut 0:
	{
		io->led_charge=VERT;;///Mise de la led  charge à VERT
		Charge=1;///Mise à jour du status (vert donc 1)
	}
	if(Charge==1)///Si l'attribut vaut 1:
	{
		io->led_charge=OFF;///Mise de la led  dispo à OFF
		Charge=0;///Mise à jour du status (off donc 0)
	}
}

void Voyants::SetBlinkCharge()
{
	/*!
	*\brief SetBlinkCharge
	*En utilisant un timer, la led charge clignote en vert pendant 8s (vert 1s puis off 1s quatre foirs)
	*/
	Tim_1.raz(); ///remise à 0 du timer
	while((Tim_1.GetValue()<8)////Si la valeur du timer est inférieure à8
	 {
	 	io->led_charge=VERT; ///Allumage en VERT
	 	sleep(1);				///Attente d'une seconde
	 	io->led_charge=OFF;///Allumage en OFF
	 	sleep(1); ///Attente d'une seconde
	 
	 }
	


}
