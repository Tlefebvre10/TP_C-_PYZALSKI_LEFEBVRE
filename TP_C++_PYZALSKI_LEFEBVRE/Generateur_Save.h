#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAVE_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include<donnees.h>
#include<mem_sh.h>
#include<iostream>

/*! \namespace std *  
* espace de nommage regroupant les outils généraux du programme c++
*/
using namespace std;

 /*! \class Generateur_Save   
 * \brief classe representant le generateur de tension de la borne et s'occupe de la gestion de sa tension de sortie
 */
class Generateur_Save
{
  private:
    entrees * io; ///Variables d'accès à la mémoire partégées
	int shmid; ///Variables d'accès à la mémoire partégées
  
  public: 
  /*!
  *\brief Constructeur
  * initialise l'accès à la mémoire partagée
  */ 
	Generateur_Save();
	/*!
  *\brief Generer_PWM
  * Génère une tension PWM differente en fonctino de la valeur spécifiée
  * \param	valeur : l'indice de la tension à générer
  */ 
	void Generer_PWM(int valeur);
		/*!
  *\brief Charger
  * Génère la tension DC et l'attente de la commutation du contacteru s2
  */ 
	void Charger();
	  /*! 
	*\brief OuvrirAC
  * Ouvre le contacteur AC
  */ 
	void OuvrirAC();
		  /*! 
	*\brief FermerAC
  * Ferme le contacteur AC si le signal est AC_1K et 6V
  */ 
	void FermerAC();
	/*!
	*\brief Réalise la préparation à la déconnection de la prise
	*/
	void Deconnecter();

	
};

#endif // GENERATEUR_SAVE_H
