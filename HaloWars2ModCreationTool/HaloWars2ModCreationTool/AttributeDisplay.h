#pragma once
#include <iostream>

class AttributeDisplay
{
public:
	virtual void Display() const = 0;
	virtual void EditValues() = 0;
	unsigned int GetID() const
	{
		return ID;
	}
	const std::string& GetName() const
	{
		return name;
	}
protected:
	unsigned int ID;
	std::string name;

};

