#include "List.h"

// Node Implementation
Node::Node(TYPE data, Node* _nextNode)
	: _data(data), _nextNode(_nextNode) {}

Node::~Node() {}


// List Implementation
List::List()
{
	_head = nullptr;
}

List::~List()
{
}

bool List::isEmpty()
{
	return _head == nullptr;
}

bool List::isFull()
{
	return false;
}

bool List::insertHead(const TYPE data)
{
	Node* node = new Node(data, nullptr);
	node->setNextNode(_head);
	_head = node;
	return true;
}

bool List::insertTail(const TYPE data)
{
	Node* node = new Node(data, nullptr);
	if (isEmpty())
	{
		_head = node;
		return true;
	}
	Node* ptr = _head;
	while (ptr->getNextNode() != nullptr)
	{
		ptr = ptr->getNextNode();
	}
	ptr->setNextNode(node);
	return true;
	
}

bool List::find(const TYPE data)
{
	if (isEmpty())
	{
		return false;
	}
	Node* ptr = _head;
	if (ptr->getData() == data)
	{
		return true;
	}
	while (ptr->getNextNode() != nullptr && ptr->getData() != data)
	{
		ptr = ptr->getNextNode();
	}
	if (ptr != nullptr && ptr->getData() == data) 
	{
		return true;
	}
	return false;

}

bool List::remove(const TYPE data)
{
	if (isEmpty())
	{
		return false;
	}

	Node* ptr = _head;
	Node* bkpPtr = nullptr;


	// If the head itself holds the one we need, we just remove it
	if (ptr->getNextNode() == nullptr && ptr->getData() == data) 
	{
		_head = ptr->getNextNode();
		delete ptr;
		return true;
	}
	// If it's not the case, we walk till we find (or not) the given data
	while (ptr->getNextNode() != nullptr && ptr->getData() != data)
	{
		bkpPtr = ptr;
		ptr = ptr->getNextNode();
	}

	// If the nextNode is null, and the data is different from the desired, then we couldn't find it
	if (ptr->getNextNode() == nullptr && ptr->getData() != data) 
	{ 
		return false;
	}
	// If we found, we just point the previous node to the next of the one we want to remove
	bkpPtr->setNextNode(ptr->getNextNode());
	delete ptr;
}

std::string List::toString()
{
	return std::string();
}
