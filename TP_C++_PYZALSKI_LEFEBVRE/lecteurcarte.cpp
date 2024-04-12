
#include "lecteurcarte.h"

void LecteurCarte::initialiser()
{
	initialisations_ports(); //initialisation des potrs du lecteur de carte
}

void LecteurCarte::lire_carte()
{
	_NumCarte=0;
	attente_insertion_carte(); //attente de l'insertion d'une carte
	if(carte_inseree()) // si la carte est inseree
	{
		_NumCarte=lecture_numero_carte(); // recuperation du numéro de la carte
	}
	cout<<"numéro lu:"<<_NumCarte<<endl; // affichage du numero de la carte
	attente_retrait_carte();
	liberation_ports();
}
int LecteurCarte::GetNumCarte()
{
	return _NumCarte;

}
