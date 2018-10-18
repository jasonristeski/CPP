#include "FibonacciIterator.h"


FibonacciIterator::FibonacciIterator(long aMaxN)
{
	fMaxN = aMaxN;
	fCurrentN = 0;
	fPrevious = 0;
	fCurrent = 1;
}


FibonacciIterator::~FibonacciIterator()
{
}

const long& FibonacciIterator::operator*() const
{
	return fCurrent;
}

FibonacciIterator& FibonacciIterator::operator++()
{
	long lNext = fCurrent + fPrevious;
	fPrevious = fCurrent;
	fCurrent = lNext;
	fCurrentN++; // increment fCurrentN each iteration
	return *this;
}

FibonacciIterator FibonacciIterator::operator++(int)
{
	FibonacciIterator temp = *this;
	++(*this);
	return temp;
}

bool FibonacciIterator::operator==(const FibonacciIterator& aOther) const 
{
	return fCurrentN == aOther.fMaxN;

}

bool FibonacciIterator::operator!=(const FibonacciIterator& aOther) const
{
	// Use operator == as base of !=
	return !(*this == aOther);
}

FibonacciIterator FibonacciIterator::begin() const
{ 
	FibonacciIterator temp = *this;
	// set default enviroment, keeping fMaxN from "this" instance
	temp.fCurrentN = 0;
	temp.fPrevious = 0;
	temp.fCurrent = 1;
	return temp;
}

FibonacciIterator FibonacciIterator::end() const
{
	FibonacciIterator temp = *this;
	//end state reached fCurrentN has iterated fMaxN times. 
	temp.fCurrentN = fMaxN;
	return temp;
}