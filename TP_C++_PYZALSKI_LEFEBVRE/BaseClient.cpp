//Déclaration des fonction de la Base client

/*! 
* \brief Fonction de la base client
* \author Thomas LEFEBVRE & Luca PYZALSKI
*/

#include"BaseClient.h"


BaseClient::BaseClient()
{
	/*! 	
	\brief	Réalise l'initialsation des 2 premiers clients
	* le premier Luca PYZALSKI avec la carte 18 son code est 3945 et il est un super user
	* le second Thomas LEFEBVRE avec la carte 15 son code est 1418 et il n'est pas un super user
	 */
	NombreClient=2;  /// Initialisation du nombre de client initial
	Numero.push_back(18); ///ajout dans le vecteurs numéro des numéros de carte
	Numero.push_back(15);
	MDP.push_back(3945);///ajout dans le vecteurs MDP des codes
	MDP.push_back(1418);
	SU.push_back(1);/// Définition dans le vecteur SU de la capacité de super user
	SU.push_back(0);
	Nom.push_back("PYZALSKI"); /// Ajout des donnés des clients
	Nom.push_back("LEFEBVRE");
	Prenom.push_back("Luca");
	Prenom.push_back("Thomas");
	
}

int BaseClient::identifier(int Cartelue)
{
	/*! 	
	\brief	Réalise l'identification du client  en fonction du numéro de la carte et du code saisi
	 */

	int CodeSaisi=0; ///création de l'entier récupérant le code


	for(int i=0;i<NombreClient;i++) ///boucle pour parcourir l'ensemble de la base de client
	{
		if(Cartelue==Numero[i]) /// si on trouve le numéro de la carte dans la base
		{
			cout<<"Entrez le code: "<<endl;  ///demande du code
			cin>>CodeSaisi;						/// recupération du code
			
			if(CodeSaisi==MDP[i])		///verification de la corespondance du code
			{
				return i; /// le client est identifié, On envoie le numéro du client
			}
				
		}
		
	}
	return -1; ///si le client n'est pas authentifié, on envoie le code erreur -1
}

void BaseClient::ajouter()
{
	/*! 	
	\brief	Réalise l'ajout d'un client  via l'interface du Super User
	 */

	int num,code,su; ///création des variables pour la saisie des informations
	string nom,prenom;
	
	cout<<"Num de carte: "<<endl; /// demande du numéro de carte à ajouter
	cin>>num;						///recuperation du numéro
	Numero.push_back(num);			//ajout à la base client
	
	cout<<"Nom client: "<<endl; /// demande du nom
	cin>>nom;					///recuperation
	Nom.push_back(nom);			//ajout à la base
	
	cout<<"Prenom client: "<<endl;
	cin>>prenom;
	Prenom.push_back(prenom);
	
	cout<<"Code client: "<<endl;
	cin>>code;
	MDP.push_back(code);
	
	cout<<"SU ? "<<endl;
	cin>>su;
	SU.push_back(su);
	
	NombreClient++;   /// Incrémentation du nombre de client
	cout<<"Client ajouter avefc succès !"<<endl; ///confirmation de l'ajout
	
}
void BaseClient::retirer(int numCarte)
{
	/*! 	
	\brief	Réalise l'retrait d'un client  via l'interface du Super User en insérant un numéro de carte
	 */

	for(int i=0;i<NombreClient;i++)  ///Boucle pour parcourir la base
	{
		if(numCarte==Numero[i]) /// Si on trouve le numéro de carte
		{
			/*!
			*mise à  ou vide de tout les champs dans la base de donnée
			*/
			Nom[i]=" "; 
			Prenom[i]=" ";
			MDP[i]=0;
			SU[i]=0;
			Numero[i]=0;
				
		}
		
	}
	cout<<"Client retire avec succès !"<<endl; /// confirmation du retrait
}

string BaseClient::GetNom(int i)
{
	return Nom[i]; /// recupération du nom du client i
}

string BaseClient::GetPrenom(int i)
{
	return Prenom[i];/// recupération du Prénom du client i
}
int BaseClient::GetSU(int i)
{
	return SU[i]; /// recupération de la capacité Super User du client i
}


