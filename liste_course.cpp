#include <iostream>
#include <vector>
#include <string>
#include "liste_course.h"

using namespace std;


Produit InitProduit(string n, int q)
{
	Produit P;
	P.nProduit = n;
	P.qProduit = q;
	return P;
}


void DisplayProduit(const Produit P)
{
	cout << "nom produit :" << P.nProduit << " ; quantite : " << P.qProduit << endl;
}

void ShowList(const vector<Produit>& L)
{
	for (Produit P : L)
	{
		DisplayProduit(P);
	}
}

void InitListCourses(vector<Produit>& L)
{
	string n; int q;
	char r = 'y';
	do
	{


		cout << "nom produit" << endl;
		cin >> n;
		cout << "quantite " << endl;
		cin >> q;
		L.resize(L.size() + 1);
		L[L.size() - 1] = InitProduit(n, q);
		cout << "" << endl;
		ShowList(L);
		cout << "" << endl;

		cout << "Avez vous d'autre article a rajouter ? (y/n)";
		cin >> r;
	} while (r == 'y');
}





/*
* 
void new_article(produit p)
{
	char article;
	int n;

	cout << "quel article voulez-vous ajoutez ?";
	cin >> article;
	cout << "Combient d'articles voulez-vous ?";
	cin >> n;
	p.nom = article;
	p.quantite = n;

}

// Definition de l'initiateur de =s champs de la structure produit'

void InitProduit(char* p, int qte, produit* pdt) {
	*pdt->nom = *p;
	*(pdt)->quantite = qte;
}

void ajout_article(char* p, int n, vector<produit>& courses, void InitProduit())
{
	if (courses.size() == 0)
	{
		courses.resize(courses.size() +=1);
	}
	for (int i = 0; i < courses.size(); i++)
	{

	}

}

void liste_article(const vector<produit>& liste)
{
	for (const produit& p : liste) {
		cout << p.nom << ' ' << p.quantite << endl;
	}
}

*/