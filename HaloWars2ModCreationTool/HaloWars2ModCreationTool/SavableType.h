#pragma once
#include <fstream>

class SavableType
{
public:
	virtual void Save(std::ofstream &stream) = 0;
	virtual void Load(std::ifstream &stream) = 0;
};

enum class SavableTypeContainerFlags
{
	eDefault = 0b00000000,
	eSave = 0b00000000,
	eLoad = 0b00000000
};

class SavableTypeContainer : public SavableType
{
public:
	uint8_t GetFlags();
	void SetFlags(uint8_t flags);
	void DisableFlags(uint8_t flags);
	void EnableFlags(uint8_t flags);
protected:
	uint8_t m_flags = (uint8_t)SavableTypeContainerFlags::eDefault;
};