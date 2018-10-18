#include "IFStream12Bits.h" 
#include <fstream>
#include <iostream>

//Private 
void IFStream12Bits::init()
{
	for(int i = 0; i < 32; i++)
	{
		fBuffer[i] = 0;
	}

	fByteCount = 0;
	fByteIndex = 0;
	fBitIndex = 8;
}

void IFStream12Bits::reload()
{
	if(!fIStream.good())
	{
	for(int i = 0; i < 32; i++)
		{
			if(fIStream.good())
			{
				fIStream >> fBuffer[i];
				fByteCount++;
			}
		}
	}
	else
	{
		std::cerr << "Unrecoverable error occured" << std::endl;
		close();
		exit(4);
	}
}

int IFStream12Bits::readBit()
{
	if(fByteCount == 0)
	{
		reload();
	}
	int lResult = fBuffer[fByteIndex] & (1 <<(fBitIndex -1)) ? 1:0; 
	fBitIndex--;
	if(fBitIndex == 0)
	{
		fByteCount--;
		if(fByteIndex == 31)
		{
			fByteIndex++;
			close();
		}
		else
		{
			fByteIndex++;
			fBitIndex = 8;
		}
	}
	return lResult;
}

// Public Interface
IFStream12Bits::IFStream12Bits()
{
	init();
}

IFStream12Bits::IFStream12Bits(const char* aFileName)
{
	init();
	open(aFileName);
}

IFStream12Bits::~IFStream12Bits()
{
	close();
}

void IFStream12Bits::open(const char* aFileName)
{
	fIStream.open(aFileName,std::ifstream::binary);
}

void IFStream12Bits::close()
{
	fIStream.close();
}

bool IFStream12Bits::fail()
{
	return fIStream.fail();
}

bool IFStream12Bits::eof()
{
	bool lResult = false;
	if(fByteCount == 0)
	{
		lResult = true;
	}
	return lResult;
}

IFStream12Bits& IFStream12Bits::operator>>(int& a12BitValue)
{
	IFStream12Bits lResult;
	for(int i = 0; i < 12; i++)
	{
		int lBit = readBit();
		if(lBit == 1)
		{
			fBuffer[fBitIndex] += (1 <<(i-1)) + fBuffer[fByteIndex];
		}
	}
	return lResult;
}