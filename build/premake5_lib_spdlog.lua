project "spdlog"

	projName = (isVs and "$(ProjectName)" or "%{prj.name}")
	projDir = (isVs and "$(ProjectDir)" or "../src/%{prj.name}/")
	
	spdlogDir = (projDir)
	relSpdlogDir = (relLibDir .. "%{prj.name}/")
	
	location (relSpdlogDir)
	kind "StaticLib"
	language "C++"
	staticruntime "On"

	targetname (projName)
	targetdir (outDir .. projName)
	objdir ("!" .. intDir .. projName)
	implibname (outDir .. projName .. "/" .. projName)

	vpaths
	{
		["Headers"] = (relSpdlogDir .. "**.h"),
		["Sources"] = (relSpdlogDir .. "**.cpp")
	}

	files
	{
		(relSpdlogDir .. "**.h"),
	}
	
	filter "toolset:msc*"
		buildoptions "/analyze:external-"

	filter "system:windows"
		systemversion "latest"
