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
	eSave = 0b00000001,
	eLoad = 0b00000010
};

class SavableTypeContainer : public SavableType
{
public:
	uint8_t GetFlags();
	void SetFlags(uint8_t flags);
	void DisableFlags(uint8_t flags);
	void EnableFlags(uint8_t flags);
	virtual void DisplayAll() const = 0;
	virtual void EditValuesAll() = 0;
	virtual void CleanUp() = 0;
	virtual void CleanUpObjects() = 0;
protected:
	uint8_t m_flags = (uint8_t)SavableTypeContainerFlags::eDefault;
};