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

void Bottle::NewTake(int quantity, int hour, int date, bool taken)
{
	Take newTake;
	newTake.id = int(takes.size());
	newTake.quantity = quantity;
	newTake.hour = hour;
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
	string data = "";
	for (int i = 0; i < takes.size(); i++)
	{
		data += to_string(takes[i].id) + "|" + to_string(takes[i].quantity) + "|" + to_string(takes[i].hour) + "|" + to_string(takes[i].date) + "|" + to_string(takes[i].taken) + "|" + to_string(takes[i].regurgitated) + "\n";
	}
	return data;
}

void Bottle::translateFromTxt(string data)
{
	string line;
	int i = 0;
	while (data.find("\n") != string::npos)
	{
		line = data.substr(0, data.find("\n"));
		data = data.substr(data.find("\n") + 1);
		takes[i].id = stoi(line.substr(0, line.find("|")));
		line = line.substr(line.find("|") + 1);
		takes[i].quantity = stoi(line.substr(0, line.find("|")));
		line = line.substr(line.find("|") + 1);
		takes[i].hour = stoi(line.substr(0, line.find("|")));
		line = line.substr(line.find("|") + 1);
		takes[i].date = stoi(line.substr(0, line.find("|")));
		line = line.substr(line.find("|") + 1);
		takes[i].taken = stoi(line.substr(0, line.find("|")));
		line = line.substr(line.find("|") + 1);
		takes[i].regurgitated = stoi(line.substr(0, line.find("|")));
		line = line.substr(line.find("|") + 1);
		i++;
	}
}