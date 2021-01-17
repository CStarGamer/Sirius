#include "Sandbox2D.h"

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	m_CheckerboardTexture = Sirius::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Sirius::Timestep ts)
{
	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Sirius::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Sirius::RenderCommand::Clear();

	Sirius::Renderer2D::BeginScene(m_CameraController.GetCamera());

	Sirius::Renderer2D::DrawQuad({ 0.5f, 0.5f }, { 1.0f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	Sirius::Renderer2D::DrawQuad({ 0.0f, 0.2f }, { 0.75f, 0.5f }, { 0.65f, 0.96f, 1.0f, 1.0f });
	Sirius::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 2.0f, 2.0f }, m_CheckerboardTexture);

	Sirius::Renderer2D::EndScene();
	
	// TODO: Add Shader::SetMat4, Shader::SetFloat4
	// std::dynamic_pointer_cast<Sirius::OpenGLShader>(m_FlatColorShader)->Bind();
	// std::dynamic_pointer_cast<Sirius::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Sirius::Event& e)
{
	m_CameraController.OnEvent(e);
}
