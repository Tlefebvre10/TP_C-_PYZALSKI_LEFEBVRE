//Déclaration des fonction de la classe generateur_save

/*! 
* \brief Fonction du generateur_save
* \author Thomas LEFEBVRE & Luca PYZALSKI
*/

#include"Generateur_Save.h"
#include <unistd.h>

Generateur_Save::Generateur_Save()
{
	/*!
	*\brief Constructeur, Réalise l'accès à la mémoire partagé
	*/
	io=acces_memoire(&shmid);
	if(io==NULL)
	printf("erreur pas de mem sh\n");


}

void Generateur_Save::Generer_PWM(int valeur)
{
	/*!
	*\brief Réalise a génération du siganl PWM en fonction de la valeur en entrée
	*\param valeur : 1 pour generer le AC_1k ou 2 pour le AC_CL
	*/
	if(valeur==1) ///si valeur vaut 1:
	{
		(io->gene_pwm)=AC_1K; ///on génère le AC_1K
	}
	else
	{
		if(valeur==2) ///et si valeur vaut 2:
		{
			while((io->gene_u)!=6); ///On attends que la tension soit égale à 6V
			(io->gene_pwm)=AC_CL; ///Puis ongénère le AC_CL

		}		
	}
}

void Generateur_Save::Charger()
{
	/*!
	*\brief Réalise a génération du siganl DC12V
	*/
	io->gene_pwm=DC;///Génération du DC 12V
	sleep(1);
	while((io->gene_u)!=9)cout<<"waiting for connection..."<<endl; ///On attends ensuite que le DC passe à 9V (connection de la prise)
}
void Generateur_Save::OuvrirAC()
{
	
		(io->contacteur_AC)=0;///ouvre le contacteur AC
	
}
void Generateur_Save::FermerAC()
{
	/*!
	*\brief Réalise la fermeture du contateur AC dès le signal est AC_1k à 6V
	*/
	while(!((io->gene_u==6)&&(io->gene_pwm==AC_1K))); /// tant que le signal est different de AC_1K 6V, on attends
	io->contacteur_AC=1; ///Puis on ferme AC
}
void Generateur_Save::Deconnecter()
{
	/*!
	*\brief Réalise la préparation à la déconnection de la prise
	*/
	while((io->gene_pwm)!=DC); ///tant que le signal n'est pas DC 12V, on attends
	OuvrirAC(); // On ouvre ensuite AC
	io->led_trappe=OFF;// On éteinds le voyant de la trappe
}

