#ifndef BASECLIENT_H
#define BASECLIENT_H

#include<iostream>
#include<vectors>

using namespace std;

class Client
{
  private:
  	string Nom,Prenom;
  	int Numero,MDP,SU;
  
  public : 
	Client(int Number,string Name,string prenom,int Code, int Suser); 
	void GetNumero();
	void GetNom();
	void GetPrenom();
	void GetMDP();
	void GetSU();
};

#endif // BASECLIENT_H
