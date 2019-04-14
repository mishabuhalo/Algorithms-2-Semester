
#include "pch.h"
#include <vector>
#include <fstream>
#include "MusicShop.h"
#include "Heap.h"

int main()
{
	ifstream albums("Albums");
	auto vect = readInformation(albums);

	Heap *heap = new Heap();
	for (int i = 0; i < vect.size(); i++)
	{
		heap->insert(vect[i]);
	}
	heap->print();
	cout << '\n';
	heap->DeleteMin();
	heap->print();
	cin.get();
	cin.get();
}
