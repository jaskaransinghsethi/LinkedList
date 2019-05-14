#pragma once
template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>() : next(nullptr) { }
	Node<T>(T value) : data(value), next(nullptr) { }

	bool operator==(Node<T> node);

};

template<typename T>
inline bool Node<T>::operator==(Node<T> node)
{
	return this->data == node.data;
}
