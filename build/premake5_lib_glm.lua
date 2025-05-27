project "glm"

	projName = (isVs and "$(ProjectName)" or "%{prj.name}")
	projDir = (isVs and "$(ProjectDir)" or "../src/%{prj.name}/")
	
	glmDir = (projDir)
	relGlmDir = (relLibDir .. "%{prj.name}/")
	
	location (relGlmDir)
	kind "StaticLib"
	language "C++"
	staticruntime "On"

	targetname (projName)
	targetdir (outDir .. projName)
	objdir ("!" .. intDir .. projName)
	implibname (outDir .. projName .. "/" .. projName)

	vpaths
	{
		["Headers"] = { (relGlmDir .. "**.h"), (relGlmDir .. "**.hpp") },
		["Sources"] = { (relGlmDir .. "**.c"), (relGlmDir .. "**.inl") }
	}

	files
	{
		(relGlmDir .. "**.c"),
		(relGlmDir .. "**.h"),
		(relGlmDir .. "**.hpp"),
		(relGlmDir .. "**.inl")
	}

	filter "system:windows"
		systemversion "latest"
