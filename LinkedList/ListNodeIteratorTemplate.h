#include "ListNodeTemplate.h"
#include <iostream>

using namespace std;

template<class T>
class ListNodeIterator
{
private:
	ListNode<T>* fNode;
public:

	typedef ListNodeIterator<T> Iterator;

	ListNodeIterator(ListNode<T>* aNode)
	{
		fNode = aNode;
	}
	
	const T& operator*() const
	{
		return fNode->fData;
	}

	Iterator& operator++() // prefix
	{
		fNode = fNode->fNext;
		return *this;
	}

	Iterator& operator++(int) // postfix
	{
		Iterator temp = *this;
		fNode = fNode->fNext;
		return temp;
	}

	bool operator==(const Iterator& aOther) const
	{
		return (fNode == aOther.fNode);
	}

	bool operator!=(const Iterator& aOther) const
	{
		return !(*this == aOther);
	}

	Iterator end()
	{
		if(fNode == nullptr) 
			return fNode;
		else
			return fNode->fNext;
	}	
};

