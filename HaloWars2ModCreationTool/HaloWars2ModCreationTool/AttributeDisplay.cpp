#include "AttributeDisplay.h"
#include "ServiceLocator.h"

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
