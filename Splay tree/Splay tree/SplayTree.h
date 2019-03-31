#pragma once
#include "MusicShop.h"

class SplayTree
{
	struct Node
	{
		information *data;
		Node *leftChild, *rightChild, *parent;

		Node();

		Node(information *data);
		
	};
	Node *root;

	void insert(Node*parent,Node  *node);

	Node * GetGrandparent(Node *node)
	{
		if (node->parent && node->parent->parent)
			return node->parent->parent;
	}

	Node *GetUncle(Node *node)
	{
		if (node->parent && node->parent->parent)
		{
			if (node->parent->parent->leftChild && node->parent->parent->leftChild == node->parent)
				return node->parent->parent->rightChild;
			else
				return node->parent->parent->leftChild;
		}
		else return nullptr;

	}
	void RotateLeft(Node *node);
	void RotateRight(Node *node);

	void Splay(Node *node);
	void zig(Node *node);
	void zigzig(Node *node);
	void zigzag(Node *node);
	void print(Node *node);

public:
	SplayTree();
	void print();
	void Add(information *data);
	
};

