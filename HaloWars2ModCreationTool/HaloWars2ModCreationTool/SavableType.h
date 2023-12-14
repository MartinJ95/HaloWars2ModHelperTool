#pragma once
#include <fstream>

class SavableType
{
public:
	virtual void Save(std::ofstream &stream) = 0;
	virtual void Load(std::ifstream &stream) = 0;
};

