#include "All_Objects.h"

All_Objects* All_Objects::instance{ nullptr };

void Object::Display() const
{
}

void Object::EditValues()
{
}

void All_Objects::Display() const
{
}

void All_Objects::EditValues()
{
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

