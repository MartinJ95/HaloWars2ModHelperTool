#pragma once
#include <iostream>

class IDDispatcher
{
public:
	IDDispatcher();
	unsigned int ClaimID();
	unsigned int ClaimID(unsigned int specificID);
	void ReleaseID(const unsigned int id);
	~IDDispatcher();
private:
	void Resize(const unsigned int newSize);
	void Swap(const unsigned int first, const unsigned int second);
	unsigned int m_current;
	unsigned int m_size;
	unsigned int* m_data;
};

