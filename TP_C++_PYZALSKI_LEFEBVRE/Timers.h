
#ifndef TIMERS_H
#define TIMERS_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include<donnees.h>
#include<mem_sh.h>
#include<iostream>
/*! \namespace std *  
* espace de nommage regroupant les outils généraux du programme c++
*/
using namespace std;

 /*! \class Timers   
 * \brief classe realisant la géestion du timer pour son utilisation dans le clignotement des voyants
 */
class Timers
{
  private:
    entrees * io;/// Variable d'accès mémoire
	int shmid;/// Variable d'accès mémoire

  int _value; ///Variable de la valeur du conmpteur
  int depart_timer; ///Variable de départ du compteur

  public: 
/*!
  *\brief Constructeur Timers
  * Réalise l'accès à la mémoire, la mise à 0 des attributs valuer et depart_timer et le lancement du timer
  */ 
	Timers();
  /*!
  *\brief raz
  * Remise à zéro du timer
  */ 
	void raz();
  /*!
  *\brief GetValue
  * Retourne la valeur du compteur
  * \return la valeur du compteur
  */ 
	int GetValue();
};

#endif // TIMERS_H
