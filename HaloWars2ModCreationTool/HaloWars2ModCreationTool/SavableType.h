#pragma once

class SavableType
{
public:
	virtual void Save() = 0;
	virtual void Load() = 0;
};

