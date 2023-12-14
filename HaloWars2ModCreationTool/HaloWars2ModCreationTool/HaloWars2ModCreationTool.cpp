// HaloWars2ModCreationTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ServiceLocator.h"
#include "AllSquads.h"

inline void ContainerSaveLoadSet(const std::string &&containerName, SavableTypeContainer* container)
{
    if (ServiceLocator::GetRenderer().GUIButton(containerName + " save: "))
    {
        container->EnableFlags((uint8_t)SavableTypeContainerFlags::eSave);
    }
    if (ServiceLocator::GetRenderer().GUIButton(containerName + " load: "))
    {
        container->EnableFlags((uint8_t)SavableTypeContainerFlags::eLoad);
    }
}

inline void ContainerSaveLoadExecute(const std::string &&filePath, const std::string &&containerName, SavableTypeContainer* container)
{
    if (container->GetFlags() & (uint8_t)SavableTypeContainerFlags::eSave)
    {
        container->DisableFlags((uint8_t)SavableTypeContainerFlags::eSave);
        
        std::ofstream stream(filePath);
        
        if (stream.is_open())
        {
            container->Save(stream);
        }
    }
    if (container->GetFlags() & (uint8_t)SavableTypeContainerFlags::eLoad)
    {
        container->DisableFlags((uint8_t)SavableTypeContainerFlags::eLoad);

        std::ifstream stream(filePath);

        if (stream.is_open())
        {
            container->Load(stream);
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";

    All_Objects::Instantiate();

    AllSquads squads;

    ServiceLocator::Init();
    if (!ServiceLocator::GetRenderer().Init())
    {
        ServiceLocator::CleanUp();
        return -1;
    }
    while (!ServiceLocator::GetRenderer().ShouldWindowClose())
    {
        ServiceLocator::GetRenderer().Clear();

        ServiceLocator::GetRenderer().BeginGUI("all_squads");

        squads.Display();
        squads.EditValues();

        if (ServiceLocator::GetRenderer().GUIButton("Add Squad"))
        {
            squads.AddSquad();
        }

        ServiceLocator::GetRenderer().EndGUI();

        ServiceLocator::GetRenderer().BeginGUI("all_objects");

        if (ServiceLocator::GetRenderer().GUIButton("all_objects save: "))
        {
            All_Objects::GetInstance()->EnableFlags((uint8_t)SavableTypeContainerFlags::eSave);
        }
        if (ServiceLocator::GetRenderer().GUIButton("all_objects load: "))
        {
            All_Objects::GetInstance()->EnableFlags((uint8_t)SavableTypeContainerFlags::eLoad);
        }

        All_Objects::GetInstance()->Display();
        All_Objects::GetInstance()->EditValues();
        
        if (All_Objects::GetInstance()->GetFlags() & (uint8_t)SavableTypeContainerFlags::eSave)
        {
            All_Objects::GetInstance()->DisableFlags((uint8_t)SavableTypeContainerFlags::eSave);
        }
        if (All_Objects::GetInstance()->GetFlags() & (uint8_t)SavableTypeContainerFlags::eLoad)
        {
            All_Objects::GetInstance()->DisableFlags((uint8_t)SavableTypeContainerFlags::eLoad);
        }

        ServiceLocator::GetRenderer().EndGUI();

        ServiceLocator::GetRenderer().Display();

        All_Objects::GetInstance()->CleanUpObjects();
        squads.CleanUpObjects();
    }
    ServiceLocator::CleanUp();
    All_Objects::CleanUp();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
