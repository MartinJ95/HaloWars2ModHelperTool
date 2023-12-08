#include "AttributeDisplay.h"
#include "ServiceLocator.h"

AttributeDisplay::AttributeDisplay() : ID(ServiceLocator::GetIDDispatcher().ClaimID()), name()
{
}

AttributeDisplay::AttributeDisplay(AttributeDisplay& other) : ID(other.ID), name(other.name)
{
}

AttributeDisplay::AttributeDisplay(AttributeDisplay&& other) : ID(other.ID), name(other.name)
{
	other.ID = UINT64_MAX;
}

void AttributeDisplay::Display() const
{
	ServiceLocator::GetRenderer().GUIText("ID: ");
	ServiceLocator::GetRenderer().GUIText(std::to_string(ID));
	ServiceLocator::GetRenderer().GUIText("name");
	ServiceLocator::GetRenderer().GUIText(name);
}

void AttributeDisplay::EditValues()
{
	ServiceLocator::GetRenderer().GUIInputText(std::to_string(ID) + ": New Name: ", name);
}

AttributeDisplay::~AttributeDisplay()
{
	ServiceLocator::GetIDDispatcher().ReleaseID(ID);
}
