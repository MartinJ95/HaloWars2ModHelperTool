#include "Renderer.h"

Renderer::Renderer(glm::vec2 resolution) : m_screenSize(resolution)
{
}

NullRenderer::NullRenderer() : Renderer(glm::vec2())
{
}

OpenGLRenderer::OpenGLRenderer(glm::vec2 resolution) : Renderer(resolution), m_window(nullptr)
{
}

bool OpenGLRenderer::Init()
{
	if (glfwInit() == GLFW_FALSE)
		return false;

	m_window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
	if (m_window == nullptr)
		return 1;
	
	ImGui::CreateContext();
	if (ImGui_ImplGlfw_InitForOpenGL(m_window, true) == false)
		return false;

	if (ImGui_ImplOpenGL3_Init("#version 130") == false)
		return false;

	ImGui::StyleColorsDark();
	
	return true;
}

bool OpenGLRenderer::ShouldWindowClose() const
{
	return false;
}

void OpenGLRenderer::Display() const
{
}

void OpenGLRenderer::Render() const
{
}

void OpenGLRenderer::Clear()
{
}

void OpenGLRenderer::BeginGUI() const
{
}

bool OpenGLRenderer::GUIButton()
{
	return false;
}

void OpenGLRenderer::GUIText(const std::string& text)
{
}

void OpenGLRenderer::EndGUI() const
{
}

OpenGLRenderer::~OpenGLRenderer()
{
}
