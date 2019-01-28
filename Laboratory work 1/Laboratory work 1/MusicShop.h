#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MusicShop
{
	string artist;
	string albums;

public:
	MusicShop();
	~MusicShop();

	void SetArtist(string artist);
	string GetArtist(string artist);

	void SetAlbums(string albums);
	string GetAlbums(string albums);
};

