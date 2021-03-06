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
		SR_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SR_CORE_ASSERT(status, "Failed to initialize Glad!");
		
		SR_CORE_INFO("OpenGL Info:");
		SR_CORE_INFO("Vendor: {0}", glGetString(GL_VENDOR));
		SR_CORE_INFO("Renderer: {0}", glGetString(GL_RENDERER));
		SR_CORE_INFO("Version: {0}", glGetString(GL_VERSION));

		#ifdef SR_ENABLE_ASSERTS
			int versionMajor;
			int versionMinor;
			glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
			glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

			SR_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Hazel requires at least OpenGL version 4.5!");
		#endif
	}
	void OpenGLContext::SwapBuffers()
	{
		SR_PROFILE_FUNCTION();
		glfwSwapBuffers(m_WindowHandle);
	}
}