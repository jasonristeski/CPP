#pragma once
#include "DoublyLinkedNodeIterator.h"
#include "DoubleLinkedNode.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template<class T>
class ListPS6
{
private:
	typedef DoubleLinkedNode<T> Node;

	Node* fTop;
	Node* fLast;
	int fCount;

public:
	typedef DoublyLinkedNodeIterator<T> Iterator;
	
	ListPS6() // constructor - default (empty)
	{
		fTop = &Node::NIL;
		fLast = &Node::NIL;
		fCount = 0;
	}
	
	~ListPS6() // Destructor
	{
		while(fTop != &Node::NIL)
		{
			Node* temp = (Node*)&fTop->getNext();
			fTop->remove();
			fCount--;
			delete fTop;
			fTop = temp;
		}
	}

	// copy constructor 
	ListPS6( const ListPS6& aOtherList)
	{
		
		fLast = &Node::NIL;
		fTop = &Node::NIL;
		fCount = 0;

		Node* temp = aOtherList.fTop;
		while(temp != &Node::NIL)
		{
			
			this->push_back(temp->getValue());
			temp = (Node*)&temp->getNext();
		}
	}

	// Assignment
	ListPS6& operator=(const ListPS6& aOtherList)
	{
		if(&aOtherList != this)
		{
			// Delete 
			this->~ListPS6();
			
			// create new
			fLast = &Node::NIL;
			fTop = &Node::NIL;
			fCount = 0;

			Node* temp = aOtherList.fTop;
			while(temp != &Node::NIL)
			{
			
				this->push_back(temp->getValue());
				temp = (Node*)&temp->getNext();
			}
		}
		return *this;
	}

	void push_front(const T& aElement)
	{
		Node* lNewElement=new Node(aElement);
		if(fTop == &Node::NIL)
		{
			fTop = lNewElement;
			fLast = lNewElement;
		}
		else
		{
			fTop->prepend(*lNewElement); // make new element previous top
			fTop = lNewElement;
		}
		fCount++;
	}

	void push_back(const T& aElement)
	{
		Node* lNewElement = new Node(aElement);
		
		if(fLast == &Node::NIL)
		{
			fLast = lNewElement;
			fTop = lNewElement;
		}
		else
		{
			fLast->append(*lNewElement); // push new element to the end
			fLast = lNewElement; //update last pointer
		}
		fCount++;
	}

	void remove (const T& aElement)
	{
		// fTop-> getNext             fLast->getPrevious
		// [n1] <-> [n2] <-> [n3] <-> [n4]
		Node* temp = fTop; 
		Node* lElement = (Node*)&aElement;
		while(temp != &Node::NIL)
		{
			if(temp->getValue() == lElement->getValue())
			{
				fCount--;
				if(temp->getValue() == fTop->getValue())
				{
					fTop = (Node*)&fTop->getNext();
				}
				if(temp->getValue() == fLast->getValue())
				{
					fLast = (Node*)&fLast->getPrevious();
				}
				temp->remove();
				break;
			}
			else
				temp = (Node*)&temp->getNext();
		}
		delete temp;
	}

	const T& operator[] (unsigned int aIndex) const
	{
		//Shift lResult into correct list index and return its value
		Node* lResult = fTop;
		for(unsigned int i = 0; i < aIndex;i++)
		{
			lResult = (Node*)&lResult->getNext(); 
		}
		if(lResult != &Node::NIL)
		{
			return lResult->getValue();
		}
		else
			throw std::range_error("Index out of bonds");
	}

	Iterator getIterator() const
	{
		Iterator lResult(*fTop);
		return lResult;
	}

	bool isEmpty() const
	{
		return fTop == &Node::NIL;
	}

	int size() const
	{
		return fCount;
	}
};

