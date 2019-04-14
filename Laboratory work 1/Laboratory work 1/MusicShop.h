#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;



class information
{
public:
	string name;
	string album;
	int releaseYear;
	information();

	bool operator > (const information &operand);

	bool operator < (const information &operand);

	string getAlbum()
	{
		return album;
	}
	information(string name, string album, int releaseYear);
	friend ostream& operator << (std::ostream &obj, information &operand);

};

vector<information> readInformation(ifstream & is);




