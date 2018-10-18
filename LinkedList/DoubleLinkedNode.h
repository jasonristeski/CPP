#pragma once
#include <iostream>
using namespace std;
template<class DataType>
class DoubleLinkedNode
{
public:
	typedef DoubleLinkedNode<DataType> Node;
private:
	DataType fValue;
	Node* fNext;
	Node* fPrevious;

	DoubleLinkedNode()
	{
		fValue = DataType();
		fNext = &NIL;
		fPrevious = &NIL;
	}

public:

	static Node NIL;

	DoubleLinkedNode(const DataType& aValue)
	{
		fValue = aValue;
		fPrevious = &NIL;
		fNext = &NIL;
	}

	// Arg aNode = new fPrevious node of this
	void prepend(Node& aNode)
	{
		aNode.fNext = this;
		if(fPrevious != &NIL )
		{
			aNode.fPrevious = fPrevious;
			fPrevious->fNext = &aNode;
		}
		fPrevious = &aNode;
	}

	//aNode = new fNext of this
	void append(Node& aNode)
	{
		aNode.fPrevious = this;
		if ( fNext != &NIL )
		{
			aNode.fNext = fNext;
			fNext->fPrevious = &aNode;
		}
		fNext = &aNode;
	}

	// Removes node and relinks
	void remove()
	{
		if(fPrevious != &NIL)
		{
			fPrevious->fNext = fNext;
		}
		if(fNext != &NIL)
		{

			fNext->fPrevious = fPrevious;
		}
	}

	const DataType& getValue() const
	{
		return fValue;	
	}

	const Node& getNext() const
	{
		return *fNext;
	}

	const Node& getPrevious() const 
	{
		return *fPrevious;
	}
};

template<class DataType>
DoubleLinkedNode<DataType> DoubleLinkedNode<DataType>::NIL;