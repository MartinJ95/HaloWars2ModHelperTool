#include "ServiceLocator.h"

Renderer* ServiceLocator::renderer{ new NullRenderer() };

void ServiceLocator::Init()
{
	delete renderer;
	renderer = new OpenGLRenderer(glm::vec2(1280, 720));
}

Renderer& ServiceLocator::GetRenderer()
{
	return *renderer;
}

void ServiceLocator::CleanUp()
{
	delete renderer;
}
