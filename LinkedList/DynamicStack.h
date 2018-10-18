#include"ListPS6.h"
#include <stdexcept>
#pragma once

template<class T>
class DynamicStack
{
private:
	ListPS6<T> fElements;

public:
	// fornt push
	void push(const T& aItem)
	{
		fElements.push_front(aItem);
	}

	void pop()
	{
		fElements.remove(fElements[0]);
	}
	const T& top() const
	{
		return fElements[0];
	}

	bool isEmpty() const
	{
		return fElements.isEmpty();
	}
	int size() const
	{
		return fElements.size();
	}
};

