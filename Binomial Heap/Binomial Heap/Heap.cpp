#include "pch.h"
#include "Heap.h"


Node * Heap::merge(Node * current, Node * newnode)
{
	Node * newHeap = nullptr;
	Node *movingNode = nullptr;
	if (current == nullptr)
		return newnode;
	else if (newnode == nullptr)
		return current;

	if (current->degree > newnode->degree)
	{
		movingNode = newHeap = newnode;
		newnode = newnode->rightBrother;
	}
	else
	{
		movingNode = newHeap = current;
		current = current->rightBrother;
	}
	
	while (current != nullptr && newnode!= nullptr)
	{
		if (current->degree < newnode->degree)
		{
			movingNode->rightBrother = current;
			movingNode = current;
			current = current->rightBrother;
		}
		else
		{
			movingNode->rightBrother = newnode;
			movingNode = newnode;
			newnode = newnode->rightBrother;
		}
	}
	while (current !=nullptr)
	{
		movingNode->rightBrother = current;
		movingNode = current;
		current = current->rightBrother;
	}
	while (newnode != nullptr)
	{
		movingNode->rightBrother = newnode;
		movingNode = newnode;
		newnode = newnode->rightBrother;
	}
	newHeap = makeUnion(newHeap, nullptr);
	return newHeap;

}

pair<Node *, Node *> Heap::returnMin()
{
	if (root == nullptr)
		return make_pair(nullptr, nullptr);
	Node * tmp = root;
	Node * prev = nullptr;
	Node * prevMin = nullptr;
	Node *minNode = root;
	while (tmp)
	{
		if (tmp->info < minNode->info)
		{
			prevMin = prev;
			minNode = tmp;
		}
		prev = tmp;
		tmp = tmp->rightBrother;

	}
	return make_pair(prevMin, minNode);
}

void Heap::insert(information  info)
{
	Node * node = new Node(info);
	root = merge(root, node);
}

information * Heap::ReturnMin()
{
	Node * tmp = returnMin().second;
	if (tmp == nullptr)
		return nullptr;
	else
		return &tmp->info;
}

void Heap::DeleteMin()
{
	if (root == nullptr)
		return;
	else
	{
		pair<Node *, Node *> tmpNodes = returnMin();
		if (root == tmpNodes.second)
			root = root->rightBrother;
		else
		{
			tmpNodes.first->rightBrother = tmpNodes.second->rightBrother;
		}
		Node * newNode = nullptr;
		Node *tmpFirst = nullptr;
		Node * tmpSecond = tmpNodes.second->Child;
		while (tmpSecond)
		{
			tmpSecond->Parent = nullptr;
			tmpFirst = tmpSecond->rightBrother;
			if (newNode != nullptr)
				tmpSecond->rightBrother = newNode;
			else
				tmpSecond->rightBrother = nullptr;
			newNode = tmpSecond;
			tmpSecond = tmpFirst;
		}
		root = merge(root, newNode);
	}
}

void Heap::print()
{
	Node * tmp = root;
	while (tmp)
	{
		printHeap(tmp, 0);
		tmp = tmp->rightBrother;
	}
}



void Heap::printHeap(Node * node, int depth)
{
	if (node->Child != nullptr)
	{
		Node * tmp = node->Child;
		while (tmp)
		{
			printHeap(tmp, depth + 1);
			tmp = tmp->rightBrother;
		}
	}
	for (int i = 0; i < depth; i++)
		cout << '\t';
	cout << node->info.album << '\n';
}

Node * Heap::makeUnion(Node * first, Node * second)
{
	if (first == nullptr || first->rightBrother == nullptr)
		return first;
	Node * tmp = first->rightBrother;
	while (tmp != nullptr && first->degree == tmp->degree)
	{
		if (first->info < tmp->info)
		{
			first->rightBrother = tmp->rightBrother;
			tmp->rightBrother = first->Child;
			first->Child = tmp;
			tmp->Parent = first;
			first->degree++;
		}
		else
		{
			first->rightBrother = tmp->Child;
			tmp->Child = first;
			first->Parent = tmp;
			tmp->degree++;
			if (second != nullptr)
			{
				second->rightBrother = tmp;

			}
			first = tmp;
		}
		if (first->rightBrother != nullptr)
		{
			Node * movingNode = first;
			Node *leftBrother = second;
			Node *rightBrother = first->rightBrother;
			bool flag = false;
			while (rightBrother != nullptr && movingNode->degree > rightBrother->degree)
			{
				if (leftBrother)
					leftBrother->rightBrother = rightBrother;
				if (!flag)
				{
					first = first->rightBrother;
					flag = true;
				}
				movingNode->rightBrother = rightBrother->rightBrother;
				rightBrother->rightBrother = movingNode;
				leftBrother = movingNode;
				movingNode = rightBrother;
				rightBrother = rightBrother->rightBrother;

			}
		}
		tmp = first->rightBrother;
	}
	makeUnion(first->rightBrother, first);
	return first;
}

Heap::Heap()
{
}


Heap::~Heap()
{
}
