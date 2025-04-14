alixerDir = (srcDir .. "Alixer/")
relAlixerDir = (relSrcDir .. "Alixer/")

project "Alixer"
	location (relAlixerDir)
	kind "SharedLib"
	language "C++"
	cppdialect (cppversion)
	staticruntime "Off"

	targetname (isVs and "$(ProjectName)" or "Alixer")
	targetdir (outDir .. "%{prj.name}")	
	objdir ("!" .. intDir .. "%{prj.name}")
	
	pchheader "pch.h"
	pchsource "../src/Alixer/pch.cpp"

	vpaths
	{
		["Headers"] = (relAlixerDir .. "**.h"),
		["Sources"] = (relAlixerDir .. "**.cpp")
	}

	files
	{
		(relAlixerDir .. "**.h"),
		(relAlixerDir .. "**.cpp")
	}
	
	includedirs
	{
		incDirs
	}
	
	disablewarnings "4251"
	
	filter "system:windows"
		systemversion "latest"
		defines
		{
			"AL_BUILD_DLL",
			"AL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines
		{
			"AL_ASSERTS_ENABLED",
			"AL_DEBUG"
		}
		optimize "Off"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines
		{
			"AL_ASSERTS_ENABLED",
			"AL_RELEASE"
		}
		optimize "On"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "AL_DIST"
		optimize "On"
		runtime "Release"
		symbols "On"
