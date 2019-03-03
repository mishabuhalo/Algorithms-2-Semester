#include <iostream>
#include <vector>
#include <fstream>
#include "MusicShop.h"
#include "OrderTree.h"
using namespace std;

int main()
{
	ifstream flights("Albums");
	auto vect = readInformation(flights);
	OrderStatisticTree<information> tree;

	for (int i = 0; i < vect.size(); i++)
	{
			tree.insert(vect[i]);
	}

	tree.print();
	

	cin.get();
	cin.get();
}