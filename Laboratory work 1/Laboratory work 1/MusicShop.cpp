#include "MusicShop.h"



MusicShop::MusicShop()
{
}


MusicShop::~MusicShop()
{
}

void MusicShop::SetArtist(string artist)
{
	this->artist = artist;
}

string MusicShop::GetArtist()
{
	return artist;
}

void MusicShop::SetAlbums(string albums)
{
	this->albums = albums;
}

string MusicShop::GetAlbums()
{
	return albums;
}