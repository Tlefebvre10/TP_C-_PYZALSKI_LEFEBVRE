//Déclaration des fonction de la classe lecteurcarte

/*! 
* \brief Fonctions du lecteur de carte usb
* \author Thomas LEFEBVRE & Luca PYZALSKI
*/

#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H

#include <lcarte.h>
#include<iostream>
/*! \namespace std *  
* espace de nommage regroupant les outils généraux du programme c++
*/
using namespace std;
 /*! \class LecteurCarte   
 * \brief classe réalisant la gestion des actions du lecteur de carte usb
 */
class LecteurCarte
{
  private:
  int _NumCarte; /// numéro de la carte lue
  
  public: 
  /*!
  *\brief initialiser
  * initialise les ports du lecteur
  */ 
	void initialiser();
  /*!
  *\brief lire_carte
  * lecture du numéro de la carte et stockage dans l'attribut
  */ 
	void lire_carte();
  /*!
  *\brief GetNumCarte
  * Remvoie la valeur de l'attribut _NumCarte
  * \return le numéro de la carte lue
  */ 
	int GetNumCarte();
};

#endif // LECTEURCARTE_H
