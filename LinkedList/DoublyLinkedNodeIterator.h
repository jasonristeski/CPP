#pragma once
#include <iostream>
using namespace std;
#include "DoubleLinkedNode.h"
template<class DataType>
class DoublyLinkedNodeIterator
{
private:
	enum IteratorStates {BEFORE,DATA,AFTER};
	IteratorStates fState;

	typedef DoubleLinkedNode<DataType> Node;

	const Node* fLeftmost;
	const Node* fRightmost;
	const Node* fCurrent;

public:

	typedef DoublyLinkedNodeIterator<DataType> Iterator;

	DoublyLinkedNodeIterator(const Node& aList)
	{
		// <BEFORE> <           DATA               > <AFTER>
		//  NIL <-> n1 <-> n2 <-> n3 <-> .... nx <-> NIL ( x= last node)
		// fLeftmost,fCurrent = n1 
		// fRightmost = nx  

		fLeftmost = &aList;
		while(&fLeftmost->getPrevious() != &Node::NIL)
		{
			fLeftmost = &fLeftmost->getPrevious();
		}

		fCurrent = fLeftmost; // first element in list 

		fRightmost = &aList;

		while(&fRightmost->getNext() != &Node::NIL)
		{
			fRightmost = &fRightmost->getNext();
		}

		// fState  
		// if Current != NIL fstate = data else AFTER
		fState = fCurrent != &Node::NIL ? DATA : AFTER;
	}
	
	const DataType& operator*() const
	{
		return fCurrent->getValue();
	}

	Iterator& operator++() // prefix inc
	{
		switch(fState)
		{
		case BEFORE:
			{
				// fCurrent = start of list on foward iter. 
				fCurrent = fLeftmost;
				if(fCurrent == &Node::NIL)
				{
					fState = AFTER;
				}
				else
				{
					fState = DATA;
				}
				break;
				
			}
		case DATA: 
			{
				fCurrent = &fCurrent->getNext();
				if(fCurrent == &Node::NIL)
				{
					fState = AFTER;
				}
				break;
			}
		}
		return *this;
		
	}

	Iterator operator++(int) // postfix inc
	{
		Iterator temp = *this;
		++(*this);
		return temp;
	}
	
	Iterator& operator--() //prefix dec
	{
		switch(fState)
		{
		case DATA: 
			{
				fCurrent = &fCurrent->getPrevious();
				if(fCurrent == &Node::NIL)
				{
					fState = BEFORE;
				}
				break;
			}
		case AFTER:
			{
				fCurrent = fRightmost; // fcurrent = end of list on backwards iter. 
				if(fCurrent == &Node::NIL)
				{
					fState = BEFORE;
				}
				else
				{
					fState = DATA;
				}
				break;
			}
		}
		return *this;
	}

	Iterator operator--(int) // postfix dec
	{
		Iterator temp = *this;
		--(*this);
		return temp;
	}

	bool operator == (const Iterator& aOtherIter) const
	{
		return ((fCurrent == aOtherIter.fCurrent) && (fLeftmost == aOtherIter.fLeftmost) && (fRightmost == aOtherIter.fRightmost) && (fState == aOtherIter.fState));
	}

	bool operator != (const Iterator& aOtherIter) const
	{
		return !(*this == aOtherIter);
	}

	// end conditions for bi-directional iterator
	// <BEFORE> <           DATA               > <AFTER>
	//  NIL <-> n1 <-> n2 <-> n3 <-> .... nx <-> NIL ( x= last node)
	Iterator leftEnd() const
	{

		Iterator lResult = *this;
		lResult.fCurrent = &fLeftmost->getPrevious(); 
		lResult.fState = lResult.fCurrent != &Node::NIL ? DATA : BEFORE; 
		return lResult;
	}

	Iterator first() const // foward iter  fstate = after 
	{
		Iterator lResult = *this;
		lResult.fCurrent = fLeftmost;
		lResult.fState = lResult.fCurrent != &Node::NIL ? DATA : AFTER;
		return lResult;
	}

	Iterator last() const // Backward iter fstate = before
	{
		Iterator lResult = *this;
		lResult.fCurrent = fRightmost;
		lResult.fState = lResult.fCurrent != &Node::NIL ? DATA : BEFORE;
		return lResult;
	}

	Iterator rightEnd() const
	{
		Iterator lResult = *this;
		lResult.fCurrent = &fRightmost->getNext();
		lResult.fState = fCurrent != &Node::NIL ? DATA : AFTER;
		return lResult;
	}
};

