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
	virtual void Save(std::ifstream& stream);
	virtual void Load(std::ofstream &stream);
	virtual void Display() const;
	virtual void EditValues();
private:
};

class All_Objects : public SavableType
{
public:
	virtual void Save(std::ifstream& stream);
	virtual void Load(std::ofstream& stream);
	virtual void Display() const;
	virtual void EditValues();
	virtual void CleanUpObjects();
	static All_Objects* GetInstance();
	static void Instantiate();
	static void CleanUp();
private:
	static All_Objects* instance;
	std::unordered_map<unsigned int, Object> m_objects;
	std::unordered_map<std::string, Vis> m_visFiles;
	std::unordered_map<std::string, Soundbank> m_soundbankFiles;
	std::unordered_map<std::string, UGX> m_ugxFiles;
	std::unordered_map<std::string, Tactic> m_tacticFiles;
};

