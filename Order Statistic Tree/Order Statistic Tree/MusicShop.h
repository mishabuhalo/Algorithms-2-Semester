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

class information
{
	

public:
	friend Artist;
	Artist *artist;
	string album;
	string date;
	information();
	information( string album, string date, Artist& artist);

	string getAlbum()
	{
		return album;
	}

	friend ostream& operator << (std::ostream &obj, information &operand);

};
class Artist
{
	friend information;
	string artist;
public:
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
			cout << i.album << '/t' << i.date << endl;
		});
	}

	Artist(string artist): info(0), artist(artist){}
};



