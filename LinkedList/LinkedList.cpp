#include "LinkedList.h"

int main() {
	LinkedList<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_front(0);
	L.push_front(-1);
	L.push_back(5);
	L.push_back(1);
	L.push_front(1);

	LinkedList<int>::displayLL(L);

	L.pop_front();
	L.pop_back();

	LinkedList<int>::displayLL(L);

	std::cout << "\n Demonstrating removeDuplicate Function:";
	LinkedList<int>::removeDuplicates(L);
	LinkedList<int>::displayLL(L);

	std::cout << "\n Demonstrating KthToLast Function:";
	Node<int> node = LinkedList<int>::KthToLast(L, 4);
	Node<int>* p = &node;
	while (p != nullptr) {
		std::cout << "\n" << p->data;
		p = p->next;
	}



	return 0;
}
