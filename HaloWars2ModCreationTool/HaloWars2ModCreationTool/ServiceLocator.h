#pragma once
#include "Renderer.h"
#include "IDDispatcher.h"

class ServiceLocator
{
public:
	static void Init();
	static Renderer& GetRenderer();
	static IDDispatcher& GetIDDispatcher();
	static void CleanUp();
private:
	static Renderer* renderer;
	static IDDispatcher IDDispatch;
};

