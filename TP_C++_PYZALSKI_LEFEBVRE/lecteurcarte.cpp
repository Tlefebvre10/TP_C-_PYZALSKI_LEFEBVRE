
#include "lecteurcarte.h"

void LecteurCarte::initialiser()
{
	/*!
	*\brief Réalise l'initialisation du lecteur de carte
	*/
	initialisations_ports(); ///initialisation des ports du lecteur de carte
}

void LecteurCarte::lire_carte()
{
	/*!
	*\brief Réalise la lecture du numéro de la carte et le stocke dans l'attribut _NumCarte
	*/
	_NumCarte=0; ///RAZ de l'attribut
	attente_insertion_carte(); ///attente de l'insertion d'une carte
	if(carte_inseree()) /// si la carte est inseree
	{
		_NumCarte=lecture_numero_carte(); /// recuperation du numéro de la carte
	}
	cout<<"numéro lu:"<<_NumCarte<<endl; /// affichage du numero de la carte
	attente_retrait_carte(); ///attente du retrait de la carte
	liberation_ports();///libération des ports du lecteur
}
int LecteurCarte::GetNumCarte()
{
	return _NumCarte;///renvoie la valeur de l'attribut _NumCarte

}
