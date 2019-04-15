#include "pch.h"
#include "Tree.h"
Tree::Node::Node(int size)
{
	isLeaf = false;
	keyNumber = 0;
	keys.resize(2*size);
	info.resize(2*size);
	children.resize(100000);
}

void Tree::insert(information * info)
{
	if (!root)
	{
		root = new Node(size);
		root->isLeaf = true;
	}
	int key = info->getYear();

	Node *leaf = findLeaf(key);

	int pos = 0;

	while (pos < leaf->keyNumber && leaf->keys[pos] < key)
		pos++;
	for (int i = leaf->keyNumber; i > pos; i--)
	{
		leaf->keys[i] = leaf->keys[i - 1];
		leaf->info[i] = leaf->info[i-1];
	}

	leaf->keys[pos] = key;
	leaf->info[pos] = info;
	leaf->keyNumber++;
	if (leaf->keyNumber == 2 * size)
		split(leaf);

}

void Tree::printTree()
{
	print(root, 0);
}

Tree::Tree()
{
	size = 5;
}

Tree::Node * Tree::findLeaf(int key)
{
	Node * node = root;
	while (!node->isLeaf)
	{
		for (int i = 0; i <= node->keyNumber; i++)
		{
			if (i == node->keyNumber || key < node->keys[i])
			{
				node = node->children[i];
				break;
			}
		}
	}
	return node;
}

void Tree::split(Node * node)
{
	Node * tmp = new Node(size);
	if (node->right)
	{
		tmp->right = node->right;
	}

	node->right = tmp;
	tmp->left = node;

	int mid = node->keys[size];
	tmp->keyNumber = size - 1;
	node->keyNumber = size;

	for (int i = 0; i <= tmp->keyNumber - 1; i++)
	{
		tmp->keys[i] = node->keys[i + size + 1];
		tmp->info[i] = node->info[i + size + 1];
		tmp->children[i] = node->children[i + size + 1];
		if (tmp->children[i])
			tmp->children[i]->parent = tmp;
	}

	tmp->children[tmp->keyNumber] = node->children[2*size];
	if (tmp->children[tmp->keyNumber])
		tmp->children[tmp->keyNumber]->parent = tmp;
	if (node->isLeaf)
	{
		tmp->keyNumber++;
		tmp->isLeaf = true;
		for (int i = tmp->keyNumber - 1; i > 0; i--)
		{
			tmp->keys[i] = tmp->keys[i - 1];
			tmp->info[i] = tmp->info[i-1];
		}
		tmp->keys[0] = node->keys[size];
		tmp->info[0] = node->info[size];
	}

	if (node == root)
	{
		root = new Node(size);
		root->keys[0] = mid;
		root->children[0] = node;
		root->children[1] = tmp;
		root->keyNumber = 1;
		node->parent = root;
		tmp->parent = root;
	}
	else
	{
		tmp->parent = node->parent;
		Node * parent = node->parent;
		int pos = 0;
		while (pos < parent->keyNumber && parent->keys[pos] < mid)
		{
			pos++;
		}

		for (int i = parent->keyNumber; i > pos; i--)
			parent->keys[i] = parent->keys[i - 1];

		for (int i = parent->keyNumber+1; i > pos+1; i--)
			parent->children[i] = parent->children[i - 1];

		parent->keys[pos] = mid;
		parent->children[pos + 1] = tmp;
		parent->keyNumber++;
		if (parent->keyNumber == 2 * size)
			split(parent);
	}
}

void Tree::print(Node * node, int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "\t";
	}
	for (int i = 0; i < node->keyNumber; i++)
		cout << node->keys[i] << ' ';
	cout << endl;

	bool flag = false;
	for (int i = 0; i < node->keyNumber; i++)
	{
		if (node->children[i])
		{
			print(node->children[i], depth + 1);
			flag = true;
		}
	}
	if (flag)
		cout << endl;

}
