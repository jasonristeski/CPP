#pragma once
class FibonacciIterator
{
private: 
	long fMaxN; // max n
	long fCurrentN; // current n
	long fPrevious; // previous fib number
	long fCurrent; // current fib number

public:
	FibonacciIterator(long aMaxN);
	~FibonacciIterator();

	// Iterator Methods 
	const long& operator*() const;
	FibonacciIterator& operator++(); // prefix
	FibonacciIterator operator++(int); // postfix
	bool operator==(const FibonacciIterator& aOther) const;
	bool operator!=(const FibonacciIterator& aOther) const;

	//aux method 
	FibonacciIterator begin() const; // return new iterator @ n=1
	FibonacciIterator end() const; // return new iterator @ maxn+1

};

