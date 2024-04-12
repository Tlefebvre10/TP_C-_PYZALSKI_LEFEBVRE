#ifndef TIMERS_H
#define TIMERS_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include<donnees.h>
#include<mem_sh.h>
#include<iostream>

using namespace std;


class Timers
{
  private:
    entrees * io;
	int shmid;
  int _value;
  int depart_timer;
  public: 
	Timers();
	void raz();
	int GetValue();
};

#endif // TIMERS_H
