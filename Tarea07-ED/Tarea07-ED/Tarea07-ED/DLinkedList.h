#pragma once
#include <stdexcept>
#include <iostream>
#include "List.h"
#include "DNode.h"

using std::runtime_error;
using std::cout;
using std::cin;
using std::endl;

template <typename E>
class DLinkedList : public List<E>
{

	DNode<E>* head;
	DNode<E>* tail;
	DNode<E>* current;
	int size;

public:

	DLinkedList()
	{

		head = new DNode<E>(nullptr, nullptr); //El primer valor describe al next en null y el previous en null
		current = new DNode<E>(nullptr, nullptr); //El primer valor describe al next en null y el previous en null
		tail = DNode<E>(nullptr, head); //El primer valor describe al next en null y el previous con el valor que tenga head en ese momento
		size = 0;

	}

	~DLinkedList()
	{

		clear();
		delete head;
		delete tail;

	}

	void insert(E element)
	{

		current->next = current->next->next->previous = new DNode<E>(element, current->next, current);

		size++;

	}


	void append(E element)
	{
		tail->previous = tail->previous->next = new DNode<E>(element, tail, tail->previous);
		size++;

	}

	E remove()
	{

		if (size == 0)
		{
			throw runtime_error("List is empty");
		}

		if (current->next == tail)
		{
			throw runtime_error("No current element");
		}

		E result = current->next->element;
		current->next = current->next->next;


		delete current->next->previous;
		current->next->previous = current;

		size--;
		return result;

	}

	void setElement(E element)
	{

	}

	E getElement()
	{

	}


	virtual void clear() = 0;
	virtual void goToStart() = 0;
	virtual void goToEnd() = 0;
	virtual void goToPos(int pos) = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool atStart() = 0;
	virtual bool atEnd() = 0;
	virtual int getPos() = 0;

	int getSize()
	{
		return size;
	}
	virtual void print() = 0;

};
