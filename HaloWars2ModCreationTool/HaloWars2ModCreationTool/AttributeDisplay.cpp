#include "AttributeDisplay.h"
#include "ServiceLocator.h"

AttributeDisplay::AttributeDisplay() : ID(ServiceLocator::GetIDDispatcher().ClaimID()), name(), MarkedForDeletion(false)
{
}

AttributeDisplay::AttributeDisplay(AttributeDisplay& other) : ID(other.ID), name(other.name), MarkedForDeletion(false)
{
}

AttributeDisplay::AttributeDisplay(AttributeDisplay&& other) : ID(other.ID), name(other.name), MarkedForDeletion(false)
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
	if (ServiceLocator::GetRenderer().GUIButton(std::to_string(ID) + "delete object"))
	{
		MarkedForDeletion = true;
	}
}

bool AttributeDisplay::GetDeletionMark() const
{
	return MarkedForDeletion;
}

AttributeDisplay::~AttributeDisplay()
{
	ServiceLocator::GetIDDispatcher().ReleaseID(ID);
}
