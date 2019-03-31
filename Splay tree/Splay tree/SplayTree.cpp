#include "SplayTree.h"



void SplayTree::insert(Node * parent, Node *node)
{
	while (parent)
	{
		if (node->data > parent->data)
		{
			if (parent->rightChild)
				parent = parent->rightChild;
			else
			{
				node->parent = parent;
				parent->rightChild = node;
				return;
			}
		}
		else
		{
			if (parent->leftChild)
			{
				parent = parent->leftChild;
			}
			else
			{
				node->parent = parent;
				parent->leftChild = node;
				return;
			}
		}
	}
}

void SplayTree::RotateLeft(Node * node)
{
	Node *current = node->rightChild;
	current->parent = node->parent;

	if (node->parent)
	{
		if (node->parent->leftChild == node)
			node->parent->leftChild = current;
		else
			node->parent->rightChild = current;
	}
	else
		root = current;
	node->rightChild = current->leftChild;
	if (current->leftChild)
		current->leftChild->parent = node;
	node->parent = current;
	current->leftChild = node;
}

void SplayTree::RotateRight(Node * node)
{
	Node * current = node->leftChild;
	current->parent = node->parent;
	if (node->parent)
	{
		if (node->parent->leftChild == node)
			node->parent->leftChild = current;
		else
			node->parent->rightChild = current;
	}
	else
	{
		root = current;
	}
	node->leftChild = current->rightChild;
	if (current->rightChild)
		current->rightChild->parent = node;
	node->parent = current;
	current->rightChild = node;
}

void SplayTree::Splay(Node * node)
{
	if (!node->parent)
		root = node;
	else
	{
		while (true)
		{
			if (node == root)
				return;
			Node* parent = node->parent;
			if (parent == root)
			{
				zig(node);
				return;
			}
			zigzig(node);
			zigzag(node);
		}
	}
}

void SplayTree::zig(Node * node)
{
	if (node == node->parent->leftChild)
		RotateRight(node->parent);
	else
		RotateLeft(node->parent);
	root = node;
}

void SplayTree::zigzig(Node * node)
{
	Node *grandparent = GetGrandparent(node);
	if (node->parent && grandparent)
	{
		if (node == node->parent->leftChild && node->parent == grandparent->leftChild)
		{
			RotateRight(grandparent);
			RotateRight(node->parent);

			if (grandparent == root)
				root = node;
		}
		else if (node == node->parent->rightChild && node->parent == grandparent->rightChild)
		{
			RotateLeft(grandparent);
			RotateLeft(node->parent);
			if (grandparent == root)
				root = node;
		}
	}
}


void SplayTree::zigzag(Node * node)
{
	Node *grandparent = GetGrandparent(node);
	if (node->parent && grandparent)
	{
		if (node == node->parent->leftChild && node->parent == grandparent->leftChild)
		{
			RotateRight(node->parent);
			RotateRight(grandparent);

			if (grandparent == root)
				root = node;
		}
		else if (node == node->parent->rightChild && node->parent == grandparent->rightChild)
		{
			RotateLeft(node->parent);
			RotateLeft(grandparent);
			if (grandparent == root)
				root = node;
		}
	}
}

void SplayTree::print(Node * node)
{
	if (node != NULL)
	{
		print(node->leftChild);
		cout << node->data->album << ' ';
		print(node->rightChild);
	}
}

SplayTree::SplayTree()
{
}

void SplayTree::print()
{
	print(root);
}

void SplayTree::Add(information * data)
{
	Node *node = new Node(data);
	insert(root, node);
	Splay(node);
}

SplayTree::Node::Node()
{
	data = nullptr;
	leftChild = rightChild = parent = nullptr;
}

SplayTree::Node::Node(information * data) : data(data) , leftChild(nullptr), rightChild(nullptr), parent(nullptr)
{
}

