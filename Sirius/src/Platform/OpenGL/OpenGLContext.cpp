#include "srpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Sirius {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SR_CORE_ASSERT(windowHandle, "WindowHandle is null!");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SR_CORE_ASSERT(status, "Failed to initialize Glad!");
		
		SR_CORE_INFO("OpenGL Info:");
		SR_CORE_INFO("Vendor: {0}", glGetString(GL_VENDOR));
		SR_CORE_INFO("Renderer: {0}", glGetString(GL_RENDERER));
		SR_CORE_INFO("Version: {0}", glGetString(GL_VERSION));
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}