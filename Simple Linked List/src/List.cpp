#include "List.h"

// Node Implementation
Node::Node(TYPE data, Node* nextNode)
	: _data(data), _nextNode(nextNode) {}

Node::~Node() {}


// List Implementation
List::List()
{
	_head = nullptr;
	_size = 0;
}

List::~List()
{
	while (!isEmpty())
	{
		Node* ptr = _head;
		_head = ptr->getNextNode();
		delete ptr;
		_size--;
	}
	delete _head;
}

bool List::isEmpty() const
{
	return _head == nullptr;
}

bool List::isFull() const
{
	return false;
}

bool List::insertHead(const TYPE data)
{
	Node* node = new Node(data, nullptr);
	node->setNextNode(_head);
	_head = node;
	_size++;
	return true;
}

bool List::insertTail(const TYPE data)
{
	Node* node = new Node(data, nullptr);
	if (isEmpty())
	{
		_head = node;
		_size++;
		return true;
	}
	Node* ptr = _head;
	while (ptr->getNextNode() != nullptr)
	{
		ptr = ptr->getNextNode();
	}
	ptr->setNextNode(node);
	_size++;
	return true;
	
}

bool List::find(const TYPE data) const
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
		_size--;
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
	_size--;
	delete ptr;
}

std::string List::toString(const bool formated) const
{
	if (isEmpty()) 
	{
		return "null";
	}
	std::stringstream ss;
	Node* ptr = _head;
	// If there's more than one element:
	while (ptr->getNextNode() != nullptr)
	{
		ss << ptr->getData();
		if (formated) 
		{
			ss << ", ";
		}
		ptr = ptr->getNextNode();
	}
	// For the last node:
	ss << ptr->getData();

	return ss.str();
}
