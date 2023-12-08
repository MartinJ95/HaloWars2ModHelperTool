#include "ServiceLocator.h"

Renderer* ServiceLocator::renderer{ new NullRenderer() };
IDDispatcher ServiceLocator::IDDispatch{};

void ServiceLocator::Init()
{
	delete renderer;
	renderer = new OpenGLRenderer(glm::vec2(1280, 720));
}

Renderer& ServiceLocator::GetRenderer()
{
	return *renderer;
}

IDDispatcher& ServiceLocator::GetIDDispatcher()
{
	return IDDispatch;
	// TODO: insert return statement here
}

void ServiceLocator::CleanUp()
{
	delete renderer;
}
