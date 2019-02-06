#pragma once
#include "List.h"

template <typename T>
class LinkedList :
	public List<T>
{
public:
	LinkedList();
	~LinkedList();
	void headInsert(const T& value);
	void headRemove();
	void insert(const T& value, unsigned int index);
	void remove(unsigned int index);
	unsigned int length();
	void clear();
	T at(unsigned int index);
	void print();
private:
	class Node
	{
	public:
		Node(const T& v = T(), Node* n = nullptr) : value(v), next(n) {}
		T value;
		Node* next;
	};
	Node* _head;
	unsigned int _length;
};

