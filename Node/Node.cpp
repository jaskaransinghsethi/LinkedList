//////////////////////////////////////////////////////////////////////////////////
// Node.cpp	      : Defines all the functionalitis of a node		            //
// ver 1.0																		//
// Application    : LinkedList Demonstration     		                        //
// Platform       : Visual Studio 2019 Community Edition                        //
//                  Windows 10 Professional 64-bit,						        //
// Author         : Jaskaran Singh, EECS Department, Syracuse University        //
//                  315-925-9941, jsingh09@syr.edu							    //
//////////////////////////////////////////////////////////////////////////////////
#include "Node.h"
#include <iostream>

#ifdef TEST_NODE

int main() {
	Node<int> node1(1), node2(2), node3(3), node4(4);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;

	Node<int> *node = &node1;
	while (node != nullptr) {
		std::cout << "\n" << node->data;
		node = node->next;
	}

	std::cout << "\n" << (node1 == node2);

	return 0;
}
#endif