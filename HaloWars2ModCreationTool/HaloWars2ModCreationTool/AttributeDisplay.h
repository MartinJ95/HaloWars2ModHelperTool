#pragma once
#include <iostream>

class AttributeDisplay
{
public:
	AttributeDisplay();
	AttributeDisplay(AttributeDisplay& other);
	AttributeDisplay(AttributeDisplay&& other);
	AttributeDisplay(unsigned int id);
	virtual void Display() const;
	virtual void EditValues();
	unsigned int GetID() const
	{
		return ID;
	}
	const std::string& GetName() const
	{
		return name;
	}
	bool GetDeletionMark() const;
	void operator=(AttributeDisplay& other)
	{
		ID = other.ID;
		name = other.name;
		MarkedForDeletion = false;
	}
	void operator=(AttributeDisplay&& other)
	{
		ID = other.ID;
		name = other.name;
		MarkedForDeletion = false;
		other.ID = UINT64_MAX;
	}
	~AttributeDisplay();
protected:
	unsigned int ID;
	std::string name;
	bool MarkedForDeletion;

};

