#ifndef BASECLIENT_H
#define BASECLIENT_H


#include<iostream>
#include<vector>

using namespace std;

class BaseClient
{
  private:
  	vector<int> Numero;
  	vector<int> MDP;
  	vector<int> SU;
  	vector<string> Nom;
  	vector<string> Prenom;
  	
  	int NombreClient;
  
  public : 
  	BaseClient();
	int identifier(int Cartelue);
	void ajouter();
	void retirer(int numCarte);
	string GetNom(int i);
	string GetPrenom(int i);
	int GetSU(int i);
};

#endif // BASECLIENT_H
