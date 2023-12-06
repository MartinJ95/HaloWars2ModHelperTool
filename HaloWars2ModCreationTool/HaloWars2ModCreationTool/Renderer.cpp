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
	return glfwWindowShouldClose(m_window);
}

void OpenGLRenderer::Display() const
{
	glfwSwapBuffers(m_window);
}

void OpenGLRenderer::Render() const
{
}

void OpenGLRenderer::Clear()
{
	glClearColor(0, 0, 0, 0);
}

void OpenGLRenderer::BeginGUI(const std::string& guiName) const
{
	ImGui::Begin(guiName.c_str());
}

bool OpenGLRenderer::GUIButton(const std::string& buttonName)
{
	return ImGui::Button(buttonName.c_str());
}

void OpenGLRenderer::GUIText(const std::string& text)
{
	ImGui::Text(text.c_str());
}

void OpenGLRenderer::EndGUI() const
{
	ImGui::End();
}

OpenGLRenderer::~OpenGLRenderer()
{
}
