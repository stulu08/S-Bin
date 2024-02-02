workspace "S-Bin"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	flags
	{
		"MultiProcessorCompile"
	}

	architecture "x86_64"

	filter "configurations:Debug"
		defines     "_DEBUG"

	filter "configurations:Release or Dist"
		defines     "NDEBUG"

	filter { "system:windows", "configurations:Dist", "toolset:not mingw" }
		flags		{ "LinkTimeOptimization" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Project.lua"
include "Test/premake5.lua"