#ifndef BOUTON_H
#define BOUTON_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include<donnees.h>
#include<mem_sh.h>
#include<iostream>

/*! \namespace std *  
* espace de nommage regroupant les outils généraux du programme c++
*/
using namespace std;

 /*! \class Bouton   
 * \brief classe realisant la gestion de l'ensemble des boutons de la borne
 */
class Bouton
{
  private:
  entrees * io; ///Variables d'accès à la mémoire de la borne
	int shmid;  ///Variables d'accès à la mémoire de la borne
  int _charge; ///Etat du bouton charge 
  int _stop;///Etat du bouton stop
  
  public: 
   /*!
  *\brief Constructeur, initialise l'accès à la mémoire et l'état inital des 2 boutons à 0
  */ 
	Bouton();
		/*!
  *\brief SetCharge
  *Met à jour le status du bouton charge
  */ 
	void SetCharge();
		/*!
  *\brief SetDispo
  *Met à jour le status du bouton Dispo
  */ 
	void SetStop();
		/*!
  *\brief GetCharge
  *renvoie l'état du bouton stop
  */ 
	int GetStop();
	 /*! 
	 * \brief GetCharge
  *renvoie l'état du bouton charge
  */ 
	int GetCharge();
};

#endif // BOUTON_H
