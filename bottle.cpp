#pragma warning(disable : 4996)
#include "bottle.h"
#include <ctime>
using namespace std;

Bottle::Bottle()
{
	takes = std::vector<Take>();
}

Bottle::~Bottle()
{
}

void Bottle::NewTake(int quantity, std::string date, bool taken)
{
	Take newTake;
	newTake.id = int(takes.size());
	newTake.quantity = quantity;
	newTake.date = date;
	newTake.taken = taken;
	newTake.regurgitated = false;
	takes.push_back(newTake);
}

void Bottle::TakeTaken(int id)
{
	takes[id].taken = !takes[id].taken;
}

void Bottle::TakeRegurgitated(int id)
{
	takes[id].regurgitated = !takes[id].regurgitated;
}

void Bottle::writeInFile(std::string fileName, std::string data, bool rewrite)
{
	ofstream file;
	if (rewrite)
		file.open(fileName, ios::out | ios::trunc);
	else
		file.open(fileName, ios::out | ios::app);
	file << data;
	file.close();
}

string Bottle::readFromFile(string fileName)
{
	string data;
	string line;
	fstream file;
	file.open(fileName, ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			data += line;
		}
		file.close();
	}
	return data;
}

string Bottle::getNow()
{
	time_t n = time(0);
	string now = ctime(&n);
	now.pop_back();
	return now;
}

string Bottle::translateToTxt()
{
	string data;
	for (int i = 0; i < takes.size(); i++)
	{
		data += to_string(takes[i].id) + "|" + to_string(takes[i].quantity) + "|" + takes[i].date + "|" + to_string(takes[i].taken) + "|" + to_string(takes[i].regurgitated) + "|";
	}
	return data;
}

void Bottle::translateFromTxt(string data)
{
	int i = 0;
	while (i < data.size())
	{
		Take take;
		string id;
		string quantity;
		string date;
		string taken;
		string regurgitated;
		while (data[i] != '|')
		{
			id += data[i];
			i++;
		}
		i++;
		while (data[i] != '|')
		{
			quantity += data[i];
			i++;
		}
		i++;
		while (data[i] != '|')
		{
			date += data[i];
			i++;
		}
		i++;
		while (data[i] != '|')
		{
			taken += data[i];
			i++;
		}
		i++;
		while (data[i] != '|')
		{
			regurgitated += data[i];
			i++;
		}
		i++;
		take.id = stoi(id);
		take.quantity = stoi(quantity);
		take.date = date;
		take.taken = stoi(taken);
		take.regurgitated = stoi(regurgitated);
		takes.push_back(take);
	}
}