#include "pch.h"
#include "Heap.h"


Node * Heap::merge(Node * current, Node * newnode)
{
	if (current == nullptr)
		return newnode;
	else if (newnode == nullptr)
		return current;
	if (current->info > newnode->info)
	{
		Node * tmp = newnode;
		newnode = current;
		current = tmp;
	}
	Node *tmpRight = current->rightBrother;
	Node * tmpLeft = newnode->leftBrother;
	current->rightBrother = newnode;
	newnode->leftBrother = current;
	tmpRight->leftBrother = tmpLeft;
	tmpLeft->rightBrother = tmpRight;

	return current;
		
}

void Heap::insert(information  info)
{
	Node * node = new Node(info);
	node->leftBrother = node->rightBrother = node;
	root = merge(root, node);
	++size;
}

information * Heap::ReturnMin()
{
	if(root!= nullptr)
		return &root->info;
	else 
		return nullptr;
}

void Heap::DeleteMin()
{
	if (root == nullptr)
		return;
	else
	{
		size--;
		Node * tmp = root;
		if (root == root->rightBrother)
			root = nullptr;
		else
			root = root->rightBrother;

		Node *tmpRight = tmp->rightBrother;
		Node * tmpLeft = tmp->leftBrother;
		tmpRight->leftBrother = tmpLeft;
		tmpLeft->rightBrother = tmpRight;

		Node *tmpChild = tmp->Child;
		delete tmp;

		if (tmpChild != nullptr)
		{
			Node * start = tmpChild;
			Node * minnode = tmpChild;
			while (start->rightBrother != tmpChild)
			{
				start->Parent = nullptr;
				if (start->info < minnode->info)
					minnode = start;
				start = start->rightBrother;
			}

			start->Parent = nullptr;
			if (start->info < minnode->info)
				minnode = start;
			tmpChild = minnode;
		}
		root = merge(root, tmpChild);
		consolidate();

	}
}

void Heap::print()
{
	Node * tmp = root;
	do
	{
		printHeap(tmp, 0);
		tmp = tmp->rightBrother;
	} while (tmp != root);
}

void Heap::consolidate()
{
	if (root == nullptr || root == root->rightBrother)
		return;
	else
	{
		vector<Node*> currRoots(int(log(size)/log(2))+2, nullptr);
		Node *tmp = root;
		while (currRoots[tmp->degree]!=tmp)
		{
			while (currRoots[tmp->degree] != nullptr)
			{
				Node* secondTemp = currRoots[tmp->degree];
				currRoots[tmp->degree] = nullptr;
				Node *tmpRight = secondTemp->rightBrother;
				Node * tmpLeft = secondTemp->leftBrother;
				tmpRight->leftBrother = tmpLeft;
				tmpLeft->rightBrother = tmpRight;
				
				if (tmp->info < secondTemp->info)
				{
					secondTemp->leftBrother = secondTemp->rightBrother = secondTemp;
					Node* tmpChild = tmp->Child;
					secondTemp->Parent = tmp;
					tmp->Child = merge(tmpChild, secondTemp);
				}
				else
				{
					tmp->Parent = secondTemp;
					secondTemp->rightBrother = tmp->rightBrother;
					secondTemp->rightBrother->leftBrother = secondTemp;
					secondTemp->leftBrother = tmp->leftBrother;
					secondTemp->leftBrother->rightBrother = secondTemp;
					tmp->leftBrother = tmp->rightBrother = tmp;
					Node* tmpChild = secondTemp->Child;
					tmp->Parent = secondTemp;
					secondTemp->Child = merge(tmpChild, tmp);
					tmp = secondTemp;
				}
				tmp->degree++;
			}
			currRoots[tmp->degree] = tmp;
			tmp = tmp->rightBrother;
		}
		root = tmp;
		Node * last = root;
		do
		{
			if (tmp->info < root->info)
			{
				root = tmp;
			}
			tmp = tmp->rightBrother;
		} while (tmp != last);
	}
}

void Heap::printHeap(Node * node, int depth)
{
	if (node->Child != nullptr)
	{
		Node * tmp = node->Child;
		Node * prev = node->Child;
		do
		{
			printHeap(tmp, depth + 1);
			tmp = tmp->rightBrother;
		} while (tmp != prev);
	}
	for (int i = 0; i < depth; i++)
		cout << '\t';
	cout << node->info.album << '\n';
}

Heap::Heap()
{
}


Heap::~Heap()
{
}
