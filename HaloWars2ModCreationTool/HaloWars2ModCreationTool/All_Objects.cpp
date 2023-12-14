#include "All_Objects.h"
#include "ServiceLocator.h"

All_Objects* All_Objects::instance{ nullptr };

void Object::Save(std::ofstream &stream)
{
    stream << std::to_string(AttributeDisplay::ID) + "\n";
    stream << AttributeDisplay::name + "\n";
}

void Object::Load(std::ifstream& stream)
{
    ServiceLocator::GetIDDispatcher().ReleaseID(AttributeDisplay::ID);
    AttributeDisplay::ID = 0;
    stream >> AttributeDisplay::ID;
    stream >> AttributeDisplay::name;
}

void Object::Display() const
{
    AttributeDisplay::Display();
}

void Object::EditValues()
{
    AttributeDisplay::EditValues();
}

void All_Objects::Save(std::ofstream& stream)
{
    for (auto& o : m_objects)
    {
        stream << std::string("object") + "\n";
        o.second.Save(stream);
    }
}

void All_Objects::Load(std::ifstream& stream)
{
    std::streampos p = stream.tellg();
    char* c = nullptr;
    stream.getline(c, std::streamsize());
    while (c == "object")
    {
        Object newObject;
        newObject.Load(stream);
        m_objects.emplace(std::pair<unsigned int, Object>(newObject.GetID(), std::move(newObject)));

        p = stream.tellg();
        stream.getline(c, std::streamsize());
    }
    stream.seekg(p);
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
    if (m_objects.empty())
        return;

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

