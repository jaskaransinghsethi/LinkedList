#pragma once
//////////////////////////////////////////////////////////////////////////////////
// Node.h	      : Defines all the functionalitis of a node		            //
// ver 1.0																		//
// Application    : LinkedList Demonstration     		                        //
// Platform       : Visual Studio 2019 Community Edition                        //
//                  Windows 10 Professional 64-bit,						        //
// Author         : Jaskaran Singh, EECS Department, Syracuse University        //
//                  315-925-9941, jsingh09@syr.edu							    //
//////////////////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* This package defines a template type node class which has two data members.
* 1. T data				- To store data
* 2. Node<T> *next		- To store the address of next node
* It also defines constructors, == operator
* Required File:
* --------------
* Node.h, Node.cpp
*
* Maintenance History:
* --------------------
* -May 14, 2019
* First Release
*
* Planned Changes:
* ----------------
* Add Copy constructor and assignment & move constructor and assignment operator
*
*/

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
