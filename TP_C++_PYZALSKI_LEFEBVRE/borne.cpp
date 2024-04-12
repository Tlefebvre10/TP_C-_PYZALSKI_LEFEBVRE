//Déclaration des fonction de la Base client

/*! 
* \brief Programme principal de la borne
* Réalise tous les appels et le comportement de la borne
* \author Thomas LEFEBVRE & Luca PYZALSKI
*/

/*! 
*Ensemble des bibliothèques des autres classe et des fonctions nécessaire au fonctionnement de la borne
*/
#include <iostream>
#include <unistd.h>
#include "memoire_borne.h"
#include "donnees_borne.h"
#include "voyants.h"
#include "lecteurcarte.h"
#include "BaseClient.h"
#include "bouton.h"
#include"Prise.h"
#include "Generateur_Save.h"

/*!
*\brief Programme principale de la borne
*/
int main()
{
	int CarteLue,user=0,choix=0,user2=0; /// Varaiables de fonctionnement
	/*!
	*\brief Création d'un objet de chaque classe 
	*/
    LecteurCarte lecteurcarte;
	BaseClient ListeClient;
	Voyants Lumiere;
	Bouton BTP;
	Prise Trappe;
	Generateur_Save Gen;

	/*!
	* \brief Boucle en while(1) afin d'éxecuter le programme continuellement
	*/
    while (1)
    {
        cout<<"Inserez votre carte"<<endl; /// demande de l'insertion de la carte
        lecteurcarte.initialiser(); ///initialisation du lecteur de carte
        lecteurcarte.lire_carte(); //Lecture de la carte 
        CarteLue=lecteurcarte.GetNumCarte(); ///récupération de la carte précedemment lue
        user=ListeClient.identifier(CarteLue); /// identification du client et stockage dans la variable user
        if(user != -1) /// si le numéro est diffrent de -1 (absent de la liste) 
        {
        	cout<<"user: "<<ListeClient.GetNom(user)<<" "<<ListeClient.GetPrenom(user)<<" identifié avec succès"<<endl; ///Message d'authentification réussier
        	if(ListeClient.GetSU(user)==1) ///Vérification de la capacité super User
        	{
        		cout<<"Pour ajouter taper 1 |  Pour effacer taper 2 |0 pour retour :"<<endl; ///Accès à la console SU si la capacité est validée
        		cin>>choix; ///Prise en compte du choix d'action
        		switch(choix) ///réalisation du choix
        		{
        			case(1):///cas 1: Ajout d'un user
        				ListeClient.ajouter(); ///appel de la fonction ajouter de la base de client
        				choix=0;				///RAZ de la variable du choix
        				break;
        			case(2):					///cas 2: retrait d'un user
        			cout<<"Quel client retirer ?"<<endl; ///demande du numéro de carte à retirer
        			cin>>choix;
        				ListeClient.retirer(choix); //Appel de la fonction retrait de la base
        				choix=0;///RAZ de la variable du choix
        				break;
        			
        		}
        	
        	}
        	else /// Si le client n'est pas un SU
        	{
        		Lumiere.SetBlinkCharge();  /// Charge clignote en Vert pendant 8s
        		cout<<"Appuyez sur Charge pour lancer !"<<endl; ///Demande d'appui sur charge
        		while((BTP.GetCharge())!=1) ///attente d'un appui sur le bouton charge
        		{
        			BTP.SetCharge(); ///Verification de l'appui via la fonction de la classe Bouton SetCharge
        		}
        		Lumiere.SetDispo();/// On eteinds dispo
        		Lumiere.SetCharge();/// On allume charge en rouge
        		Trappe.DeverrouillerTrappe(); ///Deverrouillage de la trappe
        		cout<<"Fermez la prise !"<<endl; //Demande de fermeture de la prise
        		Gen.Charger(); ///Generation du DC12V
        		Lumiere.SetPrise(); /// Allumage dU voyant Prise (signification de la fermeture de la prise)
        		Trappe.VerrouillerTrappe(); ///Verrouillage de la trappe
        		sleep(1);
        		Gen.Generer_PWM(1);///Generation du PWM AC_1K 9V
        		sleep(1);
        		Gen.FermerAC();//Fermeture du contacteur AC
        		sleep(1);
        		Gen.Generer_PWM(2);///Generation de l'AC_CL
        		sleep(20); ///attente de fin de charge
        		Gen.OuvrirAC(); ///Ouverture de AC
        		cout<<"Fini"<<endl;///Signification de la fin de la charge
        		cout<<"Inserez votre carte"<<endl;/// Demande de nouvelle identification
        		while(user2=!user) ///Tant que l'utilisateur original n'est pas authentifié (user different de user2)
        		{
        		lecteurcarte.initialiser();///Initialisation du lecteur de carte
        		lecteurcarte.lire_carte();/// Lecture de la carte
        		CarteLue=lecteurcarte.GetNumCarte();///Recupération du numéro de la carte lue
        		user2=ListeClient.identifier(CarteLue);///Authentification et stockage dans la variable user2
        		if(user2==user)  ///Si les 2 variables user et user2  sont égale, alors le client est le meme:
        		{
        			Trappe.DeverrouillerTrappe(); ///Déverrouillage de la trappe
        			Lumiere.SetDispo(); ///Allumage du voyant dispo en vert
        			cout<<"voiture récupérée"<<endl; //Siginification de la récupération de la voiture
        			break;
        		}
        		else ///Si les variables ne sont pas les memes, il ne s'agit pas du propriétaire:
        		{
        			cout<<"vous n'etes pas le proprio"<<endl;///Signification de l'incapacité à récupérer le véhicule
        		
        		}
        		}
        		Trappe.VerrouillerTrappe();/// Après récupération du véhicule, verrouillage de la trappe et retour à l'identification
        		
        	}
        	
        }
        else ///Si le client n'est pas dans la base:
        	{
        		cout<<"Vous n'étes pas enregistré, contacter un Administrateur."<<endl; ///Signification de l'absence de la base 
        	}
    }

}
