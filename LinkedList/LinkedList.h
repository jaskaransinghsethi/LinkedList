#pragma once
#include "../Node/Node.h"
#include <unordered_set>
#include <iostream>

template <typename T>
class LinkedList
{
public:
	Node<T>* head;
	int numTerms;
	LinkedList<T>() : head(nullptr), numTerms(0) {}
	LinkedList<T>(const LinkedList<T>& L);
	LinkedList<T>(const LinkedList<T>&& L);

	LinkedList& operator=(const LinkedList<T>& L);
	LinkedList& operator=(LinkedList<T>&& L);

	~LinkedList<T>();

	static void displayLL(const LinkedList<T>& L);

	/*static void sort(LinkedList<T>& L);*/

	static void reverse(LinkedList<T>& L);

	void push_back(T value);
	void push_front(T value);

	void pop_back();
	void pop_front();

	bool operator==(const LinkedList<T>& L);

	static void removeDuplicates(LinkedList<T>& L);

	static Node<T> KthToLast(const LinkedList<T>& L, int k);

	static bool deleteNode(Node<T>* node);

	static void partition(LinkedList<T>& L, int partition);

	static LinkedList<T> add(const LinkedList<T>& L1, const LinkedList<T>& L2);
};

template<typename T>
inline void LinkedList<T>::removeDuplicates(LinkedList<T>& L)
{
	std::unordered_set<int> set;
	Node<T>* prev = nullptr, * current = L.head;
	while (current != nullptr) {
		if (set.find(current->data) != set.end()) {
			prev->next = current->next;
			current->next = nullptr;
			delete current;
			current = prev->next;
		}
		else {
			set.insert(current->data);
			prev = current;
			current = current->next;
		}
	}
}

template<typename T>
inline Node<T> LinkedList<T>::KthToLast(const LinkedList<T>& L, int k)
{
	Node<T>* p1 = L.head, * p2 = L.head;

	for (int i = 0; i < k; i++) {
		if (p1 == nullptr)
			return Node<T>();
		p1 = p1->next;
	}

	while (p1 != nullptr) {
		p1 = p1->next;
		p2 = p2->next;
	}

	return *p2;
}

template<typename T>
inline bool LinkedList<T>::deleteNode(Node<T> * node)
{
	if (node->data != nullptr) {
		node->data = node->next->data;
		node->next = node->next->next;
		delete node->next;
		return true;
	}
	return false;
}

template<typename T>
inline void LinkedList<T>::partition(LinkedList<T> & L, int partition)
{
	Node<T>* head = L.head, * tail = L.head, * current = L.head, *Next=nullptr;
	while (current != nullptr) {
		Next = current->next;
		if (current->data < partition) {
			current->next = head;
			head = current;
		}
		else {
			tail->next = current;
			tail = current;
		}
		current = Next;
	}
	tail->next = nullptr;
	L.head = head;
}

template<typename T>
inline LinkedList<T> LinkedList<T>::add(const LinkedList<T>& L1, const LinkedList<T>& L2)
{
	LinkedList<T> L3;
	int carry = 0;
	Node<T>* p1 = L1.head, * p2 = L2.head, *head = L3.head, *tail = nullptr;
	while (p1 != nullptr || p2 != nullptr) {
		int val1 = (p1->next) ? p1->data : 0;
		int val2 = (p2->next) ? p2->data : 0;
		int sum = val1 + val2 + carry;
		carry = sum / 10;
		Node<T>* node = new Node<T>(sum % 10);
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
		if (carry > 0) {
			tail->next = new Node<T>(carry);
		}
		if (p1 != nullptr) p1 = p1->next;
		if (p2 != nullptr) p2 = p2->next;
	}
	return L3;
}

template<typename T>
inline LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& L)
{
	numTerms = L.numTerms;
	Node<T>* p1 = L.head;
	Node<T>* p2 = head;
	while (p1 != nullptr) {
		Node<T>* node = new Node<T>(p1->data);
		if (head == nullptr) {
			p2 = node;
			head = node;
		}
		else {
			while (p2->next != nullptr)
				p2 = p2->next;
			p2->next = node;
		}
		p1 = p1->next;
	}
	return *this;
}

template<typename T>
inline LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& L)
{
	// TODO: insert return statement here
}

template<typename T>
inline void LinkedList<T>::displayLL(const LinkedList<T>& L)
{
	Node<T>* node = L.head;
	while (node != nullptr) {
		std::cout << "\n" << node->data;
		node = node->next;
	}
}

template<typename T>
inline void LinkedList<T>::reverse(LinkedList<T>& L)
{
	if (L.head == nullptr)
		return;
	if (L.head->next == nullptr)
		return;
	Node<T> * prev = L.head, *current = L.head->next, *next = nullptr;
	while (current != nullptr) {
		next = current->next;
		if (prev == L.head)
			prev->next = nullptr;
		current->next = prev;
		prev = current;
		current = next;
	}
	L.head = prev;
	return;
}

template<typename T>
inline void LinkedList<T>::push_back(T value)
{
	Node<T>* node = new Node<T>(value);

	Node<T>* current = this->head;

	if (current == nullptr) {
		current = node;
		head = current;
		numTerms++;
		return;
	}

	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = node;
	numTerms++;
}

template<typename T>
inline void LinkedList<T>::push_front(T value)
{
	Node<T>* node = new Node<T>(value);
	Node<T>* current = this->head;
	if (current == nullptr) {
		head = node;
		numTerms++;
		return;
	}
	node->next = head;
	head = node;
	numTerms++;
}

template<typename T>
inline void LinkedList<T>::pop_back()
{
	Node<T>* current = this->head;
	while (current->next->next != nullptr) {
		current = current->next;
	}
	current->next = nullptr;
	delete current->next;
	numTerms--;
}

template<typename T>
inline void LinkedList<T>::pop_front()
{
	if (this->head == nullptr)
		return;
	Node<T>* current = this->head;
	this->head = this->head->next;
	delete current;
	numTerms--;
}

template<typename T>
inline bool LinkedList<T>::operator==(const LinkedList<T>& L)
{
	Node<T>* p1 = this->head;
	Node<T>* p2 = L.head;
	while (p1 != nullptr && p2 != nullptr) {
		if (p1->data != p2->data)
			return false;
		p1 = p1->next;
		p2 = p2->next;
	}

	return true;
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T>& L)
{
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T>&& L)
{
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	Node<T>* current = this->head, * next = nullptr;
	while (current != nullptr) {
		next = current->next;
		delete current;
		current = next;
	}
}
