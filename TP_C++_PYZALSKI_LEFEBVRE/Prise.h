#ifndef PRISE_H
#define PRISE_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include<donnees.h>
#include<mem_sh.h>
#include<iostream>

using namespace std;


class Prise
{
  private:
    entrees * io;
	int shmid;
  int status;
  
  public: 
	Prise();
	void VerrouillerTrappe();
	void DeverrouillerTrappe();
	void SetPrise();
};

#endif // PRISE_H
