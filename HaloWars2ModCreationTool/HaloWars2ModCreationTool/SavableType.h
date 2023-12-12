#pragma once
#include <fstream>

class SavableType
{
public:
	virtual void Save(std::ifstream) = 0;
	virtual void Load(std::ofstream &stream) = 0;
};

