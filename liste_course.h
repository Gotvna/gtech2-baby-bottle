#pragma once
#include <vector>
#include <string>

using namespace std;

struct Produit
{
	string nProduit;
	int qProduit;
};


void DisplayProduit(const Produit P);
void ShowList(const vector<Produit>& L);
void InitListCourses(vector<Produit>& L);