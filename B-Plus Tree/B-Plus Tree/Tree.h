#pragma once
#include <iostream>
#include <vector>
#include "MusicShop.h"

using namespace std;

class Tree
{
	static const int B = 31;
	struct Node
	{
		bool isLeaf;
		int keyNumber;
		vector<int > keys;
		Node * left, *right, *parent;
		vector<Node * > children;
		vector <information *> info;
		Node(int size);
	};
	int size;
	Node * root;
	

public:

	void insert(information * info);
	void printTree();
	Tree();
private:
	Node * findLeaf(int key);
	void split(Node * node);
	void print(Node * node, int depth);
};

