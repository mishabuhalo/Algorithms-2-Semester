
#include "pch.h"
#include <vector>
#include <fstream>
#include "MusicShop.h"
#include "Tree.h"

int main()
{
	ifstream albums("Albums");
	auto vect = readInformation(albums);

	Tree tree;
	for (int i = 0; i < vect.size(); i++)
		tree.insert(&vect[i]);
	tree.printTree();
	cin.get();
	cin.get();
}
