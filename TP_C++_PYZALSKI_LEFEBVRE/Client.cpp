#include"Client.h";

Client::Client(int Number,string Name,string prenom,int Code, int Suser)
{
	Numero = Number;
	Nom = Name;
	Prenom=prenom;
	MDP = Code
	SU=Suser;
}

void Client::GetNumero()
{
	return Numero;
}
void Client::GetNom()
{
	return Nom;
}
void Client::GetPrenom()
{
	return Prenom;
}
void Client::GetMDP()
{
	return MDP;
}
void Client::GetSU()
{
	return SU;
}
