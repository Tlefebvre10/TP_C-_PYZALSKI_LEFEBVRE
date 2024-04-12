#ifndef VOYANTS_H
#define LECTEURCARTE_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include<donnees.h>
#include<mem_sh.h>
#include<iostream>
/*! \namespace std *  
* espace de nommage regroupant les outils généraux du programme c++
*/
using namespace std;
 /*! \class Voyants   
 * \brief classe réalisant la gestions des voyants dispo et charge (allumage, extinction et clignotement)
 */
class Voyants
{
  private:
  	entrees * io;///Variables d'accès à la mémoire partégées
	int shmid;///Variables d'accès à la mémoire partégées
	int depart_timer; ///Valeur de départ du timer
	int Dispo, Charge; /// Attribut representant le status des voyants
  
  public: 
  /*!
  *\brief Constructeur
  * initialise l'accès à la mémoire partagée et la mise à 1 de dispo et à 0 de charge
  */ 
  	Voyants();

	/*!
  *\brief SetDispo
  * Selon l'état de dispo, il l'allume en VERT ou l'éteinds
  */ 
	void SetDispo();
	
	/*!
  *\brief GetDispo
  * Renvoie le status actuel de dispo
  */ 
	int GetDispo();
		/*!
  *\brief SetCharge
  * Selon l'état de charge, il l'allume en ROUGE ou l'éteinds
  */ 
	void SetCharge();

		/*!
  *\brief SetBlinkChagre
  * En utilisant un timer, il permet de faire clignoter Charge en vert pendant 8s
  */ 
	void SetBlinkCharge();
};

#endif // VOYANTS_H
