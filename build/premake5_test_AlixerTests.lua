alixerTestsDir = (testDir .. "AlixerTests/")
relAlixerTestsDir = (relTestDir .. "AlixerTests/")

project "AlixerTests"
	location (relAlixerTestsDir)
	kind "SharedLib"
	language "C++"
	cppdialect (cppversion)
	staticruntime "Off"

	targetname (isVs and "$(ProjectName)" or "AlixerTests")
	targetdir (testOutDir .. "%{prj.name}")	
	objdir ("!" .. intDir .. "%{prj.name}")

	vpaths
	{
		["Headers"] = (relAlixerTestsDir .. "**.h"),
		["Sources"] = (relAlixerTestsDir .. "**.cpp")
	}

	files
	{
		(relAlixerTestsDir .. "**.h"),
		(relAlixerTestsDir .. "**.cpp")
	}

	includedirs
	{
		incDirs,
		alixerTestsDir
	}

	links { "Alixer" }
	
	disablewarnings "4251"

	filter "system:windows"
		systemversion "latest"
		defines
		{
			"AL_PLATFORM_WINDOWS"
		}
		postbuildcommands
		{
			("{COPY} " .. relCopyDir .. "Alixer/*.dll " .. testOutDir .. (isVs and "$(ProjectName)" or "AlixerTests/")),
			("{COPY} " .. relCopyDir .. "Alixer/*.pdb " .. testOutDir .. (isVs and "$(ProjectName)" or "AlixerTests/"))
		}

	filter "configurations:Debug"
		defines "AL_DEBUG"
		optimize "Off"
		symbols "On"

	filter "configurations:Release"
		defines "AL_RELEASE"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines "AL_DIST"
		optimize "On"
		symbols "On"
