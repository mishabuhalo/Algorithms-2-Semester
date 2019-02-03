#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MusicShop
{
	string artist;
	string albums;

	vector<shared_ptr<MusicShop>> ourObjects;
	int seed;
	vector<int> mainHash;

public:
	MusicShop();
	~MusicShop();

	void SetArtist(string artist);
	string GetArtist();

	void SetAlbums(string albums);
	string GetAlbums();
};