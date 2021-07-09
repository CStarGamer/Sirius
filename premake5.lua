workspace "Sirius"
	startproject "Sandbox"
	architecture "x86_64"

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
includeDir["stb_image"] = "Sirius/vendor/stb_image"

include "Sirius/vendor/GLFW"
include "Sirius/vendor/Glad"
include "Sirius/vendor/imgui"

project "Sirius"
	location "Sirius"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "srpch.h"
	pchsource "Sirius/src/srpch.cpp"

	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
		"%{prj.location}/vendor/stb_image/**.h",
		"%{prj.location}/vendor/stb_image/**.cpp",
		"%{prj.location}/vendor/glm/glm/**.hpp",
		"%{prj.location}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.location}/src",
		"%{prj.location}/vendor/spdlog/include",
		"%{includeDir.GLFW}",
		"%{includeDir.Glad}",
		"%{includeDir.ImGui}",
		"%{includeDir.glm}",
		"%{includeDir.stb_image}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines 
		{
			"SR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "SR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SR_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		systemversion "latest"

	filter "configurations:Debug"
		defines "SR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SR_DIST"
		runtime "Release"
		optimize "on"