#pragma once
#include <string>
#include <sstream>
#include <ostream>
#ifdef __GNUC__
	#define nullptr NULL
#endif

typedef int TYPE;
class Node 
{
public:
	Node(TYPE data, Node* nextNode);
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
	bool isEmpty() const;
	bool isFull() const;
	bool insertHead(const TYPE data);
	bool insertTail(const TYPE data);
	bool find(const TYPE data) const;
	bool remove(const TYPE data);
	unsigned int getSize() const { return _size; }
	std::string toString(const bool formated = false) const;

private:
	unsigned int _size;
	Node* _head;
};
inline std::ostream& operator <<(std::ostream& str, const List& list) 
{
	return str << list.toString(true);
}