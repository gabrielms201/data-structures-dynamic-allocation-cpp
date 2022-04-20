#include "List.h"
#include <iostream>

int main()
{
	List list = List();
	list.insertTail(1); // 1
	list.insertTail(2); // 1, 2
	list.insertTail(3); // 1, 2, 3
	list.insertTail(4); // 1, 2, 3, 4
	list.insertHead(6); // 6, 1, 2, 3, 4
	list.insertHead(7); // 7, 6, 1, 2, 3, 4
	list.remove(1);     // 7, 6, 2, 3, 4
	list.insertTail(2); // 7, 6, 2, 3, 4, 2
	list.remove(5);     // 7, 6, 2, 3, 4, 2
	 // 7, 6, 2, 3, 4, 2
}