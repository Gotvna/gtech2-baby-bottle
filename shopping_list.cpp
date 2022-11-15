#include <iostream>
#include <vector>
#include <string>
#include "shopping_list.h"

using namespace std;


Item InitProduit(string n, int q)
{
	Item i;
	i.name = n;
	i.quantity = q;
	return i;
}

//Console mode functions (DO NOT USE ANYMORE)
/*void DisplayItem(const Item i)
{
	cout << "name :" << i.name << " ; quantity : " << i.quantity << endl;
}

void ShowList(const vector<Item>& L)
{
	for (Item i : L)
	{
		DisplayItem(i);
	}
}

void InitListCourses(vector<Item>& L)
{
	string n; int q;
	char r = 'y';
	do
	{
		cout << "item name" << endl;
		cin >> n;
		cout << "quantity " << endl;
		cin >> q;
		L.resize(L.size() + 1);
		L[L.size() - 1] = InitProduit(n, q);
		cout << "" << endl;
		ShowList(L);
		cout << "" << endl;

		cout << "Anything else? (y/n)";
		cin >> r;
	} while (r == 'y');
}*/
