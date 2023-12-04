#pragma once
#include <iostream>

class AttributeDisplay
{
public:
	virtual void Display() const = 0;
	virtual void EditValues() = 0;
private:
	unsigned int ID;
	std::string name;

};

