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
	std::cout << "\n Size of Linked list:" << L.numTerms;

	LinkedList<int>::displayLL(L);

	L.pop_front();
	L.pop_back();
	std::cout << "\n Size of Linked list:" << L.numTerms;
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

	std::cout << "\n Demonstrating Copy assignment operator";
	LinkedList<int> L2;
	L2 = L;
	LinkedList<int>::displayLL(L2);

	LinkedList<int> L3;
	L3.push_back(3);
	L3.push_back(5);
	L3.push_back(8);
	L3.push_back(5);
	L3.push_back(10);
	L3.push_back(2);
	L3.push_back(1);

	std::cout << "\n Demonstrating Partition function:";
	LinkedList<int>::partition(L3, 5);
	LinkedList<int>::displayLL(L3);

	std::cout << "\n Demonstrating Reverse function:";
	LinkedList<int>::reverse(L3);
	LinkedList<int>::displayLL(L3);

	std::cout << "\n Demonstrating Add function:";
	LinkedList<int> L4 = LinkedList<int>::add(L2, L3);
	LinkedList<int>::displayLL(L4);
	



	return 0;
}
