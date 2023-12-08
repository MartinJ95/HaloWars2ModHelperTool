#pragma once
#include <iostream>

class AttributeDisplay
{
public:
	AttributeDisplay();
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
	~AttributeDisplay();
protected:
	unsigned int ID;
	std::string name;

};

