#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Artist;

vector<Artist> readArtists(ifstream& is);

void readInformation(ifstream & is, vector<Artist>& vect);
class Artist;
class information
{

	

public:
	friend Artist;
	Artist *artist;
	string album;
	int releaseYear;
	information();

	bool operator > (const information &operand);

	bool operator < (const information &operand);

	string getAlbum()
	{
		return album;
	}
	information(string album, int releaseYear, Artist& artist);
	friend ostream& operator << (std::ostream &obj, information &operand);

};
class Artist
{
	friend information;

public:

	
	string artist;
	vector<information> info;

	void add(information i)
	{
		info.push_back(i);
	}

	string getName()
	{
		return artist;
	}

	void show()
	{
		for_each(begin(info), end(info), []( information i)
		{
			cout << i.album << '/t' << i.releaseYear << endl;
		});
	}

	Artist(string artist): info(0), artist(artist){}
};



