#pragma once
template<class DataType> 
class ListNode
{
public:
		DataType fData;
		ListNode* fNext;
public:
	ListNode(const DataType& aData,ListNode* aNext = (ListNode*)0)
	{
		fData = aData;
		fNext = aNext;
	}
};

