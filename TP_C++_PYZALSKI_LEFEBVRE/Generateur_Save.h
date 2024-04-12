#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAVE_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include<donnees.h>
#include<mem_sh.h>
#include<iostream>

using namespace std;


class Generateur_Save
{
  private:
    entrees * io;
	int shmid;
  
  public: 
	Generateur_Save();
	void Generer_PWM(int valeur);
	void Charger();
	void OuvrirAC();
	void FermerAC();
	void Deconnecter();
	void PriseDeco();
	
};

#endif // GENERATEUR_SAVE_H
