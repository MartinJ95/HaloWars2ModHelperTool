#include "AllSquads.h"
#include "ServiceLocator.h"

void Squad::Display() const
{
	AttributeDisplay::Display();
	ServiceLocator::GetRenderer().GUIText("Squad Description");
	ServiceLocator::GetRenderer().GUIText(m_description);

	for (auto& m : m_squadMembers)
	{
		ServiceLocator::GetRenderer().GUIText("number of member: ");
		ServiceLocator::GetRenderer().GUIText(std::to_string(m.first));
		ServiceLocator::GetRenderer().GUIText("member object ref ID: ");
		ServiceLocator::GetRenderer().GUIText(std::to_string(m.second));
	}
}

void Squad::EditValues()
{
	AttributeDisplay::EditValues();
	ServiceLocator::GetRenderer().GUIInputText(std::string("new description:"), m_description);

	if (ServiceLocator::GetRenderer().GUIButton("Add Member"))
	{
		m_squadMembers.emplace_back();
	}
}

void AllSquads::Display() const
{
	for (auto& s : m_squads)
	{
		s.Display();
	}
}

void AllSquads::EditValues()
{
	for (auto& s : m_squads)
	{
		s.EditValues();
	}
}

void AllSquads::AddSquad()
{
	m_squads.emplace_back();
}
