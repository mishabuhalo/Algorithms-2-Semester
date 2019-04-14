
#include <vector>
#include <fstream>
#include "MusicShop.h"

int main()
{
	ifstream albums("Albums");
	auto vect = readInformation(albums);

	cin.get();
	cin.get();
}
