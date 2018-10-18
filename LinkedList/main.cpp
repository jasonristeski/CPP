#include <iostream>
#include <string>
#include "ListPS6.h"
#include "DynamicStack.h"
#include "DynamicStackIterator.h"
#include "DynamicQueue.h"
#include "DynamicQIterator.h"
using namespace std;

void q2()
{
	DynamicQueue<int> lq;
	lq.enqueue(1);
	lq.enqueue(2);
	lq.enqueue(3);
	lq.enqueue(4);
	lq.enqueue(5);
	lq.enqueue(6);

	cout << "traverse elements" << endl;

	for(DynamicQIterator<int> iter = DynamicQIterator<int>(lq); iter!= iter.end();iter++)
	{
		cout << "value " << *iter++ << endl;
	}
}
void q1()
{
	DynamicQueue<int> lq;
	lq.enqueue(1);
	lq.enqueue(2);
	lq.enqueue(3);
	lq.enqueue(4);
	lq.enqueue(5);
	lq.enqueue(6);

	cout << "Queue Elments: " << endl;
	for(;!lq.isEmpty();lq.dequeue())
	{
		cout << "value : " << lq.top() << endl;
	}
}

void problem3()
{
	DynamicStack<string> lStack;
	
	string s1("One");
	string s2("Two");
	string s3("Three");
	string s4("Four");
	string s5("Five");
	string s6("Six");

	lStack.push(s1);
	lStack.push(s2);
	lStack.push(s3);
	lStack.push(s4);
	lStack.push(s5);
	lStack.push(s6);

	cout << "Traverse elements" << endl;
	for(DynamicStackIterator<string> iter = DynamicStackIterator<string>(lStack); iter != iter.end();iter++)
	{
		cout << "value " << *iter << endl; 
	}
}

void problem2()
{
	DynamicStack<string> lStack;

	lStack.push("AAA");
	lStack.push("BBB");
	lStack.push("CCC");
	lStack.push("DDD");
	
	cout << "top: " << lStack.top() << endl;
	lStack.pop();
	cout << "top: " << lStack.top() << endl;
	lStack.pop();
	cout << "top: " << lStack.top() << endl;
	cout << "size: " << lStack.size() << endl;
	cout << "is empty?: " << (lStack.isEmpty() ? "T":"F") << endl;
	lStack.pop();
	cout << "top: " << lStack.top() << endl;
	lStack.pop();
	cout << "is empty?: " << (lStack.isEmpty() ? "T":"F") << endl;
}

void problem1()
{
	string s1 ("AAA");
	string s2 ("BBB");
	string s3 ("CCC");
	string s4 ("DDD");
	string s5 ("EEE");
	
	ListPS6<string> lList;
	lList.push_front(s4);
	lList.push_front(s3);
	lList.push_front(s2);
	
	ListPS6<string> copy(lList);

	cout << "1 - Top to bottom : " << copy.size() << " elements" << endl;
	
	for(ListPS6<string>::Iterator iter = copy.getIterator(); iter != iter.rightEnd(); iter++)
	{
		cout << "A list element: " << *iter << endl;
	}

	lList = copy;
	lList.push_front(s1);
	lList.push_back(s5);
	cout << "2 - Bottom to top: " << lList.size() << " elements" << endl;
	for(ListPS6<string>::Iterator iter = lList.getIterator().last(); iter != iter.leftEnd(); iter--)
	{
		cout << "B list element " << *iter << endl;
	}
}

int main()
{
	//problem1();
	//problem2();
	problem3();
	//q1();
	//q2();
	return 0;
}