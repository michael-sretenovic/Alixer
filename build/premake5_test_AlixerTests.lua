alixerTestsDir = (testDir .. "AlixerTests/")
relAlixerTestsDir = (relTestDir .. "AlixerTests/")

project "AlixerTests"
	location (relAlixerTestsDir)
	kind "SharedLib"
	language "C++"
	cppdialect (cppversion)
	staticruntime "Off"

	targetname (isVs and "$(ProjectName)" or "Alixer")
	targetdir (outDir .. "%{prj.name}")	
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

	filter "system:windows"
		systemversion "latest"
		defines
		{
			"AL_PLATFORM_WINDOWS"
		}
		postbuildcommands
		{
			("{COPY} ../" .. outDir .. "Alixer/*.dll ../" .. outDir .. "AlixerTests/"),
			("{COPY} ../" .. outDir .. "Alixer/*.pdb ../" .. outDir .. "AlixerTests/")
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
