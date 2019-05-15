#pragma once
#include "../Node/Node.h"
#include <unordered_set>
#include <iostream>

template <typename T>
class LinkedList
{
public:
	Node<T> *head;
	int numTerms;
	LinkedList<T>() : head(nullptr), numTerms(0) {}
	/*LinkedList<T>(const LinkedList<T>& L);
	LinkedList<T>(const LinkedList<T>&& L);

	LinkedList& operator=(const LinkedList<T>& L);
	LinkedList& operator=(LinkedList<T>&& L);*/

	~LinkedList<T>();

	static void displayLL(const LinkedList<T>& L);

	/*static void sort(LinkedList<T>& L);

	static void reverse(LinkedList<T>& L);*/

	void push_back(T value);
	void push_front(T value);

	void pop_back();
	void pop_front();

	bool operator==(const LinkedList<T>& L);

	static void removeDuplicates(LinkedList<T>& L);

	static Node<T> KthToLast(const LinkedList<T>& L, int k);
};

template<typename T>
inline void LinkedList<T>::removeDuplicates(LinkedList<T>& L)
{
	std::unordered_set<int> set;
	Node<T>* prev = nullptr, *current = L.head;
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
inline void LinkedList<T>::displayLL(const LinkedList<T>& L)
{
	Node<T>* node = L.head;
	while (node != nullptr) {
		std::cout << "\n" << node->data;
		node = node->next;
	}
}

template<typename T>
inline void LinkedList<T>::push_back(T value)
{
	Node<T>* node = new Node<T>(value);

	Node<T>* current = this->head;

	if (current == nullptr) {
		current = node;
		head = current;
		return;
	}

	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = node;

}

template<typename T>
inline void LinkedList<T>::push_front(T value)
{
	Node<T>* node = new Node<T>(value);
	Node<T>* current = this->head;
	if (current == nullptr) {
		head = node;
		return;
	}
	node->next = head;
	head = node;
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
}

template<typename T>
inline void LinkedList<T>::pop_front()
{
	if (this->head == nullptr)
		return;
	Node<T>* current = this->head;
	this->head = this->head->next;
	delete current;
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
inline LinkedList<T>::~LinkedList()
{
	Node<T>* current = this->head, * next = nullptr;
	while (current != nullptr) {
		next = current->next;
		delete current;
		current = next;
	}
}
