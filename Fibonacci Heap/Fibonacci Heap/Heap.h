#pragma once
#include "MusicShop.h"

struct Node
{
	information  info;
	Node * rightBrother;
	Node * Child;
	Node * Parent;
	Node * leftBrother;
	int degree;
	bool mark;

	Node(information inf)
	{
		info = inf;
		degree = 0;
		mark = false;
		Parent = leftBrother = Child = rightBrother = nullptr;
	}
};

class Heap
{
	Node * root = nullptr;
	int size = 0;
	Node * merge(Node * current, Node * newnode);
	void consolidate();
	void printHeap(Node * node, int depth);
public:
	void insert(information  info);
	information *ReturnMin();
	void DeleteMin();
	void print();
	Heap();
	~Heap();
};

