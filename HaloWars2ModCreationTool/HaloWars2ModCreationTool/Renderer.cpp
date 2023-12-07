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
		return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwMakeContextCurrent(m_window);

	glViewport(0, 0, 1280, 720);
	glEnable(GL_DEPTH_TEST);

	
	ImGui::CreateContext();
	if (ImGui_ImplGlfw_InitForOpenGL(m_window, true) == false)
		return false;

	if (ImGui_ImplOpenGL3_Init("#version 330 core") == false)
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
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(m_window);
}

void OpenGLRenderer::Render() const
{
}

void OpenGLRenderer::Clear()
{
	glClearColor(0.f, 0.25f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	glfwPollEvents();
}

void OpenGLRenderer::BeginGUI(const std::string& guiName) const
{
	ImGui::Begin(guiName.c_str());
}

bool OpenGLRenderer::GUIButton(const std::string& buttonName)
{
	return ImGui::Button(buttonName.c_str());
}

void OpenGLRenderer::GUIText(const std::string& text) const
{
	ImGui::Text(text.c_str());
}

void OpenGLRenderer::GUIInputText(const std::string& label,std::string& text)
{
	ImGui::InputText(label.c_str(), &text);
}

void OpenGLRenderer::EndGUI() const
{
	ImGui::End();
}

OpenGLRenderer::~OpenGLRenderer()
{
}
