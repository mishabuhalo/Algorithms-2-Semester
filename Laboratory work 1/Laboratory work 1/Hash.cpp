#include "Hash.h"



int firstHashing(string name, int seed, int length)
{
	unsigned hash = 0;
	for (int i = 0; i <int(name.size()); i++)
	{
		hash = hash ^ (name[i] * seed) + hash >> 3;
	}
	return int(hash%length);
}


int secondHashing(string name, int seed, int length)
{
	unsigned hash = 0;
	for (int i = 0; i <int(name.size()); i++)
	{
		hash = hash ^ (name[i] * seed * (1 + seed)) + 1 + hash >> 3;
	}
	return int(hash%length);
}
	