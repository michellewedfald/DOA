#include "pch.h"
#include "LinkedList.h"
#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList()
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	clear();
	delete(_head);
}

//Time complexity of O(1) as head is always at first position
template <typename T>
void LinkedList<T>::headInsert(const T& value)
{
	Node* newNode = new Node(value, _head);
	_head = newNode;
	_length++;
}

//Time complexity of O(1) as head is always at first position
template <typename T>
void LinkedList<T>::headRemove()
{
	Node* currentNode = _head;
	if (currentNode != NULL)
	{
		_head = currentNode->next;
		delete(currentNode);
	}
}

//Time complexity of O(N), as it scales linearly with the size of the index, because we have to traverse the list 
//up to the point we want to insert at
template <typename T>
void LinkedList<T>::insert(const T& value, unsigned int index)
{
	if (index >= _length || index < 0)
	{
		throw std::out_of_range("Index was out of range");
	}
	if (index == 0)
	{
		headInsert(value);
	}
	else
	{
		Node* currentNode = _head;
		int counter = 1;
		while (counter != index)
		{
			currentNode = currentNode->next;
		}
		Node* nodeToInsert = new Node(value, currentNode->next);
		currentNode->next = nodeToInsert;
	}
	_length++;
}

//Time complexity of O(N), as it scales linearly with the size of the index, because we have to traverse the list 
//up to the point we want to delete
template <typename T>
void LinkedList<T>::remove(unsigned int index)
{
	if (index >= _length || index < 0)
	{
		throw std::out_of_range("Index was out of range");
	}
	if (index == 0)
	{
		headRemove();
	}
	else
	{
		Node* currentNode = _head;
		int counter = 0;
		while (counter < index - 1 && currentNode != NULL)
		{
			currentNode = currentNode->next;
			counter++;
		}
		Node* next = currentNode->next->next;
		delete currentNode->next;
		currentNode->next = next;
	}
}

//Time complexity of O(1) as we maintain the count property along the way. Otherwise it would be O(N) if we had to traverse the list
//and count each element
template <typename T>
unsigned int LinkedList<T>::length()
{
	return _length;
}

//Time complexity of O(N) as it scales linearly with the size of the list
template <typename T>
void LinkedList<T>::clear()
{
	while (_head != NULL)
	{
		headRemove();
	}
}

//Time complexity of O(N) as it scales linearly with the size of the index
template <typename T>
T LinkedList<T>::at(unsigned int index)
{
	if (index >= _length || index < 0)
	{
		throw std::out_of_range("Index was out of range");
	}
	Node* currentNode = _head;
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->next;
	}
	std::cout << currentNode->value;
	return currentNode->value;
}

