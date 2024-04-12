#ifndef BOUTON_H
#define BOUTON_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include<donnees.h>
#include<mem_sh.h>
#include<iostream>

using namespace std;


using namespace std;

class Bouton
{
  private:
  entrees * io;
	int shmid;
  int _charge;
  int _stop;
  
  public: 
	Bouton();
	void SetCharge();
	void SetStop();
	int GetStop();
	int GetCharge();
};

#endif // BOUTON_H
