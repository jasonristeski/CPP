#include "DynamicQueue.h"
#pragma once

template<class T>
class DynamicQIterator
{
private:
	DynamicQueue<T> fQueue;
public:
	DynamicQIterator(const DynamicQueue<T>& aQueue)
	{
		fQueue = aQueue;
	}

	DynamicQIterator& operator++()
	{
		fQueue.dequeue();
		return *this;
	}

	DynamicQIterator operator++(int)
	{
		DynamicQIterator temp = *this;
		++(*this);
		return temp;
	}
	const T& operator*()
	{
		return fQueue.top();
	}

	bool operator==(const DynamicQIterator& aOtherIter) const
	{
		return (fQueue.isEmpty() == aOtherIter.fQueue.isEmpty()) && (fQueue.size() == aOtherIter.fQueue.size());
	}

	bool operator!=(const DynamicQIterator& aOtherIter) const
	{
		return !(*this == aOtherIter);
	}

	DynamicQIterator end() const
	{
		// new iter at end
		DynamicQIterator temp = *this;
		while(!temp.fQueue.isEmpty())
		{
			++temp;
		}
		return temp;
	}
};

