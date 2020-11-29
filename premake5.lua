workspace "Sirius"
	startproject "Sandbox"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder.
includeDir = {}
includeDir["GLFW"] = "Sirius/vendor/GLFW/include"
includeDir["Glad"] = "Sirius/vendor/Glad/include"
includeDir["ImGui"] = "Sirius/vendor/imgui/"
includeDir["glm"] = "Sirius/vendor/glm/"

include "Sirius/vendor/GLFW"
include "Sirius/vendor/Glad"
include "Sirius/vendor/imgui"

project "Sirius"
	location "Sirius"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "srpch.h"
	pchsource "Sirius/src/srpch.cpp"

	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
		"%{prj.location}/vendor/glm/glm/**.hpp",
		"%{prj.location}/vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"%{prj.location}/src",
		"%{prj.location}/vendor/spdlog/include",
		"%{includeDir.GLFW}",
		"%{includeDir.Glad}",
		"%{includeDir.ImGui}",
		"%{includeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"SR_PLATFORM_WINDOWS",
			"SR_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"IMGUI_API=__declspec(dllexport)"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "SR_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SR_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp"
	}

	includedirs 
	{
		"Sirius/vendor/spdlog/include",
		"Sirius/src",
		"Sirius/vendor",
		"%{includeDir.glm}",
	}

	links
	{
		"Sirius"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines 
		{
			"SR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SR_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SR_DIST"
		runtime "Release"
		optimize "On"