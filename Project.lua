project "S-Bin"
	kind "StaticLib"
	--kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "")
	objdir ("bin-int/" .. outputdir .. "")

	pchheader "pch.h"
	pchsource "Source/pch.cpp"

	defines{
		--"SBIN_DLL",
		--"SBIN_EXPORT"
	}

	files
	{
		"Source/**.h",
		"Source/**.cpp",
		"Include/**.h",
		"Include/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
	}

	includedirs
	{
		"Source",
		"Include"
	}
	
	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "ST_DEBUG"
		runtime "Debug"
		optimize "off"
		symbols "on"

	filter "configurations:Release"
		defines "ST_RELEASE"
		runtime "Release"
		optimize "on"
		symbols "on"

	filter "configurations:Dist"
		defines "ST_DIST"
		runtime "Release"
		optimize "on"
		symbols "off"