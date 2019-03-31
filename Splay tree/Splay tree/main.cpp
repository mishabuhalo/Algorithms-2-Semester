#include <iostream>
#include <vector>
#include <fstream>
#include "MusicShop.h"
#include "SplayTree.h"

using namespace std;

int main()
{
	ifstream albums("Albums");
	auto vect = readInformation(albums);
	SplayTree tree;

	for (int i = 0; i < vect.size(); i++)
	{
		tree.Add(&vect[i]);
	}

	tree.print();
	cin.get();
	cin.get();
}