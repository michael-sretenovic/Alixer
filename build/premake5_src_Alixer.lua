project ("Alixer")

	projName = (isVs and "$(ProjectName)" or "%{prj.name}")
	projDir = (isVs and "$(ProjectDir)" or "../src/%{prj.name}/")
	
	alixerDir = (projDir)
	relAlixerDir = (relSrcDir .. "%{prj.name}/")

	location (relAlixerDir)
	kind ("SharedLib")
	language ("C++")
	cppdialect (cppversion)
	staticruntime ("Off")

	targetname (projName)
	targetdir (outDir .. projName)
	objdir ("!" .. intDir .. projName)
	implibname (outDir .. projName .. "/" .. projName)
	
	pchheader ("pch.h")
	pchsource (relAlixerDir .. "pch.cpp")

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
	
	links
	{
		
	}
	
	disablewarnings ("4251")
	
	filter ("system:windows")
		systemversion ("latest")
		defines
		{
			"AL_BUILD_DLL",
			"AL_PLATFORM_WINDOWS"
		}

	filter ("configurations:Debug")
		defines
		{
			"AL_ASSERTS_ENABLED",
			"AL_DEBUG"
		}
		optimize ("Off")
		runtime ("Debug")
		symbols ("On")

	filter ("configurations:Release")
		defines
		{
			"AL_ASSERTS_ENABLED",
			"AL_RELEASE"
		}
		optimize ("On")
		runtime ("Release")
		symbols ("On")

	filter ("configurations:Dist")
		defines ("AL_DIST")
		optimize ("On")
		runtime ("Release")
		symbols ("On")
