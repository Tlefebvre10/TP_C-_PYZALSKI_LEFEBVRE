#ifndef VOYANTS_H
#define LECTEURCARTE_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include<donnees.h>
#include<mem_sh.h>
#include<iostream>

using namespace std;

class Voyants
{
  private:
  	entrees * io;
	int shmid;
	int depart_timer;
	int Dispo, Charge;
  
  public: 
  	Voyants();
	void SetDispo();
	int GetDispo();
	void SetCharge();
	void SetBlinkCharge();
};

#endif // VOYANTS_H
