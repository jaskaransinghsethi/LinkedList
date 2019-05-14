#include "Node.h"
#include <iostream>

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
}