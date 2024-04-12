#ifndef BASECLIENT_H
#define BASECLIENT_H


#include<iostream>
#include<vector>
/*! \namespace std *  
* espace de nommage regroupant les outils généraux du programme c++
*/
using namespace std;
 /*! \class BaseClient   
 * \brief classe representant la base de donnée regroupant les données des differents clients
 */
class BaseClient
{
  private:
  	vector<int> Numero; /*! vecteur des numéro clients*/
  	vector<int> MDP;/*! vecteur des mots de passe clients*/
  	vector<int> SU;/*! vecteur des de la capacité super user des clients*/
  	vector<string> Nom;/*! vecteur des noms des clients*/
  	vector<string> Prenom;/*! vecteur des prénom clients*/
  	
  	int NombreClient; /*! nombre de client dans la base*/
  
  public : 
  /*!
  *\brief Constructeur, initialise les 2 premiers clients de la base
  */ 
  	BaseClient();
/*!
  *\brief identifier
  * Parcours la baseclients et vérifie la présence de la carte et demande puis vérifie le mot de passe saisie
  * \param	Cartelue : la carte insérée
  * \return le numéro de client si identifié -1 sinon
  */ 
	int identifier(int Cartelue);
	/*!
  *\brief Ajouter
  *ajouteun client en demande toutes ses infos
  */ 
	void ajouter();
	/*!
  *\brief retirer
  * retire un client a partir de son numéor de client
  * \param numCarte : le numéro de la carte du client à supprimer
  */ 
	void retirer(int numCarte);
	/*!
  *\brief GetNom
  *Renvoie le nom du client pour l'affichage
  *\param i : le numero du client dont on veut le nom
  *\return  le nom du client
  */ 
	string GetNom(int i);
	  /*! \brief GetPreom
  *Renvoie le prenom du client pour l'affichage
  *\param i : le numero du client dont on veut le nom
  *\return  le prénom du client
  */ 
	string GetPrenom(int i);
	/*! \brief GetSU
  *Renvoie la capacité SU du client pour acceder à la fenetre
  *\param i : le numero du client dont on veut le nom
  *\return  le SU du client
  */ 
	int GetSU(int i);
};

#endif // BASECLIENT_H
