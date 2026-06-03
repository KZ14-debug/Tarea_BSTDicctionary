#pragma once

template<typename E> //esto es para decir que es generico
class DNode
{
public:
	E element;
	DNode<E>* next;
	DNode<E>* previous;

	DNode(E element, DNode<E>* next, DNode<E>* previous) // Indica que esto puede ser invocado con tres, dos o un parametro
	{
		this->element = element;
		this->next = next;
		this->previous = previous;
	}

	DNode(DNode<E>* next, DNode<E>* previous) // Indica que esto puede ser invocado con uno o dos parametros
	{
		this->next = next;
		this->previous = previous;
	}

};

