#include <iostream>
#include <vector>
#include <fstream>
#include "MusicShop.h"

using namespace std;

int main()
{
	ifstream flights("Albums");
	auto vect = readInformation(flights);
	


	cin.get();
	cin.get();
}