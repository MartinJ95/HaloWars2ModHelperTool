#pragma once
#include "AttributeDisplay.h"
#include "vector"
#include "All_Objects.h"

class Squad : public AttributeDisplay
{
public:
	virtual void Display() const;
	virtual void EditValues();
private:
	std::string m_description;
	std::vector<std::pair<unsigned int, Object>> m_squadMembers;
	Tactic* m_tacticRef;
};

class AllSquads : public AttributeDisplay
{
public:
	virtual void Display() const;
	virtual void EditValues();
private:
	std::vector<Squad> m_squads;
};

