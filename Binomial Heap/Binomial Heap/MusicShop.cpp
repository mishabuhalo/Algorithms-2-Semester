
#pragma once
#include "pch.h"
#include "MusicShop.h"
using namespace std;




bool information::operator > (const information &operand) {
	return this->album > operand.album;
}

bool information::operator < (const information &operand) {
	return this->album < operand.album;
}

information::information(string name, string album, int releaseYear) :releaseYear(releaseYear), album(album), name(name)
{

}


vector<information> readInformation(ifstream & is)
{
	int n = 0;
	vector<information> res;
	is >> n;
	for (int i = 0; i < n; i++)
	{
		int releaseYear;
		string name;
		string album;
		is >> name;

		is >> album;
		is >> releaseYear;
		res.push_back(information(name, album, releaseYear));
	}
	return res;
}

ostream & operator<<(std::ostream & obj, information & operand)
{
	obj << operand.releaseYear;
	return obj;
}

information::information()
{

}