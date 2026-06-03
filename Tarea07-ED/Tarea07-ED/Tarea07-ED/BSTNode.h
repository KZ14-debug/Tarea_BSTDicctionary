#pragma once

template<typename E>
class BSTNode
{

public:
	BSTNode<E>* left;
	BSTNode<E>* right;
	E element;

	BSTNode(E element)
	{
		this->element = element;
		right = left = nullptr;
	}

	int childrenCount()
	{
		return (left != nullptr ? 1 : 0) + (right == nullptr ? 0 : 1);
	}

	BSTNode<E>* onlyChild()
	{
		return left == nullptr ? right : left;
	}
};

