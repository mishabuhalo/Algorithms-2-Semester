#pragma once
#include "MusicShop.h"

struct Node
{
	information  info;
	Node * rightBrother;
	Node * Child;
	Node * Parent;
	int degree;

	Node(information inf)
	{
		info = inf;
		degree = 0;
		Parent  = Child = rightBrother = nullptr;
	}
};

class Heap
{
	Node * root = nullptr;
	Node * merge(Node * current, Node * newnode);
	pair<Node *, Node *> returnMin();
	void printHeap(Node * node, int depth);
	Node * makeUnion(Node * first, Node* second);
public:
	void insert(information  info);
	information *ReturnMin();
	void DeleteMin();
	void print();
	Heap();
	~Heap();
};

