#include <iostream>
#include <vector>
#include <fstream>
#include "MusicShop.h"
#include "OrderTree.h"
using namespace std;

int main()
{
	ifstream airlines("Artists");
	auto vect = readArtists(airlines);

	ifstream flights("Albums");
	readInformation(flights, vect);

	for_each(begin(vect), end(vect), [](Artist operand) {

		OrderStatisticTree<information> tree;

		for (auto x : operand.info) {
			tree.insert(x);
		}

		tree.print();
		cout << endl <<"Height: " <<  tree.getHeight();

		cout << endl << "--------------next------------" << endl;

	});

	cin.get();
	cin.get();
}