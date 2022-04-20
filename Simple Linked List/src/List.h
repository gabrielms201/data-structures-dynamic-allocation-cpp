#pragma once
#include <string>
#include <sstream>


typedef int TYPE;
class Node 
{
public:
	Node(TYPE data, Node* _nextNode);
	~Node();
	TYPE getData() const { return _data; }
	Node* getNextNode() const { return _nextNode; }
	void setData(const TYPE data) { _data = data; }
	void setNextNode(Node* nextNode) { _nextNode = nextNode; }
private:
	TYPE _data;
	Node* _nextNode;
};

class List
{
public:
	List();
	~List();
	bool isEmpty();
	bool isFull();
	bool insertHead(const TYPE data);
	bool insertTail(const TYPE data);
	bool find(const TYPE data);
	bool remove(const TYPE data);
	std::string toString();

private:
	Node* _head;
};