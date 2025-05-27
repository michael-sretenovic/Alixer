project ("AlixerTests")

	projName = (isVs and "$(ProjectName)" or "%{prj.name}")
	projDir = (isVs and "$(ProjectDir)" or "../src/%{prj.name}/")
	
	alixerTestsDir = (projDir)
	relAlixerTestsDir = (relTestDir .. "%{prj.name}/")
	
	location (relAlixerTestsDir)
	kind ("SharedLib")
	language ("C++")
	cppdialect (cppversion)
	staticruntime ("Off")

	targetname (projName)
	targetdir (testOutDir .. projName)
	objdir ("!" .. intDir .. projName)
	implibname (outDir .. projName .. "/" .. projName)

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
		alixerTestsDir,
		(alixerTestsDir .. "TestFixtures")
	}

	links { "Alixer" }
	
	disablewarnings ("4251")

	filter ("system:windows")
		systemversion ("latest")
		defines
		{
			"AL_PLATFORM_WINDOWS"
		}
		postbuildcommands
		{
			("{COPY} " .. relCopyDir .. "Alixer/*.dll " .. testOutDir .. (isVs and "$(ProjectName)" or "AlixerTests/")),
			("{COPY} " .. relCopyDir .. "Alixer/*.pdb " .. testOutDir .. (isVs and "$(ProjectName)" or "AlixerTests/"))
		}

	filter ("configurations:Debug")
		defines ("AL_DEBUG")
		optimize ("Off")
		symbols ("On")

	filter ("configurations:Release")
		defines ("AL_RELEASE")
		optimize ("On")
		symbols ("On")

	filter ("configurations:Dist")
		defines ("AL_DIST")
		optimize ("On")
		symbols ("On")
