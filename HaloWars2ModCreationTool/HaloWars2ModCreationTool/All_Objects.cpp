#include "All_Objects.h"
#include "ServiceLocator.h"

All_Objects* All_Objects::instance{ nullptr };

void Object::Display() const
{
    AttributeDisplay::Display();
}

void Object::EditValues()
{
    AttributeDisplay::EditValues();
}

void All_Objects::Display() const
{
    for (auto& o : m_objects)
    {
        o.second.Display();
    }
}

void All_Objects::EditValues()
{
    for (auto& o : m_objects)
    {
        o.second.EditValues();
    }

    if (ServiceLocator::GetRenderer().GUIButton("Add Object"))
    {
        Object newObject;
        m_objects.emplace(std::pair<unsigned int, Object>(newObject.GetID(), std::move(newObject)));
    }
}

void All_Objects::CleanUpObjects()
{
    for (auto it = m_objects.begin(); it != m_objects.end();)
    {
        if (it->second.GetDeletionMark())
        {
            it = m_objects.erase(it);
        }
        else
            it++;
    }
}

All_Objects* All_Objects::GetInstance()
{
    return instance;
}

void All_Objects::Instantiate()
{
    instance = new All_Objects();
}

void All_Objects::CleanUp()
{
    delete instance;
}

