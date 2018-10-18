#include <fstream>
#pragma once
class OFStream12Bits
{
private:
	std::ofstream fOStream; 
	unsigned char fBuffer[32]; 
	int fByteIndex;
	int fBitIndex; 

	void init(); 
	void finishWriteBit();
	void writeBit0();
	void writeBit1();
public:
	OFStream12Bits();
	OFStream12Bits(const char* aFileName);
	~OFStream12Bits();

	void open ( const char* aFileName);
	void close();
	bool fail();
	void flush();
	OFStream12Bits& operator<<(int a12BitValue);
};

