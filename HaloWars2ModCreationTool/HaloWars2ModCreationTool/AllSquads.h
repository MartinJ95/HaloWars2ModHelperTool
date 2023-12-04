#pragma once
#include "AttributeDisplay.h"
#include "vector"

class Tactic
{

};

class Squad : public AttributeDisplay
{
public:
	virtual void Display() const;
	virtual void EditValues();
private:
	std::string m_description;
	Tactic* m_tacticRef;
};

class AllSquads
{
	std::vector<Squad> m_squads;
};

