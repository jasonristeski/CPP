#include "ListPS6.h"
#include <stdexcept>
#pragma once

template<class T>
class DynamicQueue
{
private:
	ListPS6<T> fElements;
public:

	void enqueue( const T& aElement)
	{
		fElements.push_back(aElement);
	}

	void dequeue()
	{
		fElements.remove(fElements[0]);
	}

	const T& top() const
	{
		return fElements[0];
	}

	int size() const
	{
		return fElements.size();
	}

	bool isEmpty() const
	{
		return fElements.isEmpty();
	}
};

