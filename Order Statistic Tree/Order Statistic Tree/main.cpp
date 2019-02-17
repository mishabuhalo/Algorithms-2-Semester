#include <iostream>
#include <vector>
#include <fstream>
#include "MusicShop.h"
using namespace std;

int main()
{
	ifstream airlines("Artists.txt");
	auto vect = readArtists(airlines);

	ifstream flights("Albums.txt");
	readInformation(flights, vect);

	cin.get();
	cin.get();
}