#pragma once
#include "Renderer.h"

class ServiceLocator
{
public:
	static void Init();
	static Renderer& GetRenderer();
	static void CleanUp();
private:
	static Renderer* renderer;
};

