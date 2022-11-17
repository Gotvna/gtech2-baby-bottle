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


void Bottle::writeInFile(string fileName, string data)
 {
	 fstream file;
	 file.open(fileName, ios::app);
	 file << data << endl;
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