#pragma once
#include "AttributeDisplay.h"
#include <unordered_map>
#include "SavableType.h"

class Tactic
{

};

class Vis
{

};

class Soundbank
{

};

class UGX
{

};

class Object : public AttributeDisplay, public SavableType
{
public:
	virtual void Save(std::ofstream& stream) override;
	virtual void Load(std::ifstream &stream) override;
	virtual void Display() const;
	virtual void EditValues();
private:
};

class All_Objects : public SavableTypeContainer
{
public:
	virtual void Save(std::ofstream& stream) override;
	virtual void Load(std::ifstream& stream) override;
	virtual void DisplayAll() const;
	virtual void EditValuesAll();
	virtual void CleanUp() override;
	virtual void CleanUpObjects() override;
	static All_Objects* GetInstance();
	static void Instantiate();
	static void CleanUpInstance();
private:
	static All_Objects* instance;
	std::unordered_map<unsigned int, Object> m_objects;
	std::unordered_map<std::string, Vis> m_visFiles;
	std::unordered_map<std::string, Soundbank> m_soundbankFiles;
	std::unordered_map<std::string, UGX> m_ugxFiles;
	std::unordered_map<std::string, Tactic> m_tacticFiles;
};

