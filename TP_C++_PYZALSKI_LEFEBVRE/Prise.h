#ifndef PRISE_H
#define PRISE_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include<donnees.h>
#include<mem_sh.h>
#include<iostream>

/*! \namespace std *  
* espace de nommage regroupant les outils généraux du programme c++
*/
using namespace std;

 /*! \class Prise   
 * \brief classe réalisant la gestion du verrouillage/déverrouillage de la prise
 */
class Prise
{
  private:
    entrees * io; ///Variables  d'accès mémoire
	int shmid;
  int status;/// variable representant l'état du verrouillage
  
  public: 
    /*!
  *\brief Prise
  * Réalisation de l'accès à la mémoire et mise à 0 du status
  */ 
	Prise();
	  /*!
  *\brief VerrouillerTrappe
  * Effectue le verrouillage de la trappe
  */ 
	void VerrouillerTrappe();
	  /*!
  *\brief DeverrouillerTrappe
  * Effectue le deverrouillage de la trappe
  */ 
	void DeverrouillerTrappe();
};

#endif // PRISE_H
