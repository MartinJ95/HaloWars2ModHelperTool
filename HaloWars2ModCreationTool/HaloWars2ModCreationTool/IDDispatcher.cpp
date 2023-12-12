#include "IDDispatcher.h"

IDDispatcher::IDDispatcher() : m_current(0), m_size(10), m_data(new unsigned int[10])
{
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = i;
	}
}

unsigned int IDDispatcher::ClaimID()
{
	m_current++;
	if (m_size == m_current)
	{
		Resize(m_size + 1);
	}
	return m_data[m_current-1];
}

unsigned int IDDispatcher::ClaimID(unsigned int specificID)
{
	for (int i = m_current; i < m_size; i++)
	{
		if (m_data[i] == specificID)
		{
			if (m_size == m_current)
			{
				Resize(m_size + 1);
			}
			Swap(m_current, i);
			m_current++;
			return m_data[m_current - 1];
		}
	}
}

void IDDispatcher::ReleaseID(const unsigned int id)
{
	for (int i = 0; i < m_current; i++)
	{
		if (m_data[i] == id)
		{
			m_current--;
			if (m_current > 0)
			{
				Swap(i, m_current);
			}
		}
	}
}


void IDDispatcher::Resize(const unsigned int newSize)
{
	unsigned int oldSize = m_size;
	unsigned int* oldData = m_data;

	m_data = new unsigned int[newSize];
	for (unsigned int i = 0; i < oldSize && i < newSize; i++)
	{
		m_data[i] = oldData[i];
	}
	for (unsigned int i = oldSize; i < newSize; i++)
	{
		m_data[i] = i;
	}

	delete[] oldData;
}

void IDDispatcher::Swap(const unsigned int first, const unsigned int second)
{
	unsigned int temp = m_data[first];
	m_data[first] = m_data[second];
	m_data[second] = temp;
}

IDDispatcher::~IDDispatcher()
{
	delete[] m_data;
}