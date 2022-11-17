#include "bottle.h"
using namespace std;	

Bottle::Bottle()
{
	takes = std::vector<Take>();
}

Bottle::~Bottle()
{
}

void Bottle::NewTake(int quantity, bool taken)
{
	Take newTake;
	newTake.id = int(takes.size());
	newTake.quantity = quantity;
	newTake.taken = taken;
	newTake.regurgitated = false;
	takes.push_back(newTake);
}

vector<Take> Bottle::getTakes() {
	return takes;
}

void Bottle::TakeTaken(int id)
{
	takes[id].taken = true;
}

void Bottle::TakeRegurgitated(int id)
{
	takes[id].regurgitated = true;
}




// LOAD AND EXPORT DATA (LOW PRIORITY)
////Write the list of takes into a file
//void Bottle::writeTakes(const char* file)
//{
//	ofstream takesFile;
//	takesFile.open(file, ios::out | ios::trunc);
//	takesFile << "Writing this to a file.\n";
//	takesFile.close();
//}
//
////Read the list of takes from a file and load it into the vector
//void Bottle::readTakes(const char* file)
//{
//	ifstream takesFile;
//	string line;
//	if (takesFile.is_open())
//	{
//		while (getline(takesFile, line))
//		{
//			cout << line << '\n';
//		}
//		takesFile.close();
//	}
//	else cout << "Unable to open file";
//}