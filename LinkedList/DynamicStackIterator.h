#include"DynamicStack.h"
#pragma once

template<class T>
class DynamicStackIterator
{
private:
	DynamicStack<T> fStack;
public:

	DynamicStackIterator(const DynamicStack<T>& aStack)
	{
		fStack = aStack;
	}

	DynamicStackIterator& operator++()
	{
		fStack.pop();
		return *this;
	}

	DynamicStackIterator operator++(int)
	{
		DynamicStackIterator temp = *this;
		++(*this);
		return temp;
	}

	const T& operator*() const
	{
		return fStack.top();
	}

	bool operator==(const DynamicStackIterator& aOtherIter) const
	{
		return (fStack.size() == aOtherIter.fStack.size()) && (fStack.isEmpty() == aOtherIter.fStack.isEmpty());
	}

	bool operator!=(const DynamicStackIterator& aOtherIter) const
	{
		return !(*this == aOtherIter);
	}

	DynamicStackIterator end() const
	{
		// create new iterator at end pos 
		DynamicStackIterator temp = *this;
		while(!temp.fStack.isEmpty())
		{
			++temp;
		}
		return temp;
	}
};

