#include "stdafx.h"
#pragma once
//LinkedLists.cpp : Defines the entry point for the console application.


//MWN: Spørgsmål til Troels:
////Hvor skal min main være?
////Hvordan sætter man programmet op i C++; hvordan definerer jeg headeren korrekt, hvordan laver man instanser i main og kører sit program?
////Hvad er der i de autogenerede filer?
////Hvornår skal jeg include og hvad skal includes hvor? Skal der includes i test?
////Hvordan får jeg noden på index-1 til at pege på newnode i insert-metoden
////Hvordan kører jeg testene?


template<typename T>
class LinkedList
{
public:
	// Pre: None
	// Post: The list is initialized
	// Time: O(1) - constant time
	LinkedList()
	{
		headPtr = nullptr;
	}

	// Pre: None
	// Post: The element d is at the head of the list
	// Time: O(1) - constant time
	void headInsert(const T& d)
	{
		Node* newNode = new Node(d, nullptr);
		newNode->data = d;
		newNode->next = headPtr;
		headPtr = newNode;
	}
	// Or simply: headPtr = new Node(data, headPtr);
	

	// Your implementation of other methods go here!

	// Pre: None
	// Post: First element in list is removed
	// Time: O(1) - constant time
	void headRemove()
	{
		Node* temp = headPtr;
		headPtr = headPtr->next;
		delete temp;
	}

	// Pre: index < length
	// Post: list[index] = data
	// Time: O(n) - linear
	void insert(const T& data, unsigned int index)
	{
		if (index < length())
		{
			Node* newnode = new Node(data, index);
			newnode->data = data;
			newnode->next = at(index + 1);
			//få Node på plads index-1 til at pege på newnode -- HJÆLP
		}
	}

	// Pre: index < length
	// Post: Element på plads index slettes fra listen
	// Time: O(n) - linear
	void remove(unsigned int index)
	{
		if (index < length())
		{
			Node* previous = index - 1;
			Node* temp = previous->next;
			previous->next = temp->next;
			delete temp;
		}
	}

	// Pre: index < length
	// Post: Element på plads index returneres
	// Time: O(n^2) - kvadratisk
	T& at(unsigned int index)
	{
		if (index < length())
		{
			Node* current = headPtr;

			// the index of the  
			// node we're currently 
			// looking at 
			int count = 0;
			while (current != NULL)
			{
				if (count == index)
					return(current->data);
				count++;
				current = current->next;
			}
			return current;
		}
	}

	// Pre: 
	// Post: Længden af listen returnedes
	// Time: O(n) - linear
	unsigned int length()
	{
		Node* current = headPtr;
		int count = 0;
		while (current != nullptr)
		{
			current = current->next;
			count++;
		}
		return count;
	}

	// Pre: 
	// Post: listen er tømt
	// Time: O(n^2)/O(2n) - kvadratisk/lineær
	void clear()
	{
		int length = length();

		int count = 0;
		while (count <= length)
		{
			remove(count);
			count++;
		}
	}

private:
	class Node
	{
	public:
		Node(const T& d = T(), Node* n = 0) : data(d), next(n) {}
		T data;
		Node* next;
	};

	Node* headPtr;
};