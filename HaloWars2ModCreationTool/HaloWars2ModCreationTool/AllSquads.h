#pragma once
#include "AttributeDisplay.h"
#include "vector"
#include "All_Objects.h"

class Squad : public AttributeDisplay, public SavableType
{
public:
	virtual void Display() const;
	virtual void EditValues();
	virtual void Save(std::ofstream &stream) override;
	virtual void Load(std::ifstream& stream) override;
private:
	std::string m_description = "new squad";
	std::vector<std::pair<unsigned int, unsigned int>> m_squadMembers;
	Tactic* m_tacticRef;
};

class AllSquads : public SavableTypeContainer
{
public:
	virtual void DisplayAll() const override;
	virtual void EditValuesAll();
	virtual void Save(std::ofstream& stream) override;
	virtual void Load(std::ifstream& stream) override;
	virtual void CleanUp() override;
	virtual void CleanUpObjects() override;
private:
	std::vector<Squad> m_squads;
};

