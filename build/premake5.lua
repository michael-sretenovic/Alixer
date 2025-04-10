arch = "x64"
cppversion = "C++latest"

if _ACTION:match("vs.*") then
	isVs = true
	solutionDir = "$(SolutionDir)"
	config = "windows-$(Platform)-$(Configuration)"
else
	isVs = false
	solutionDir = "../"
	config = ("%{cfg.system}-" .. arch .. "-%{cfg.buildcfg}")
end



srcDirName = "src"
libDirName = "lib"
testDirName = "test"
outDirBaseName = "output"

srcDir = solutionDir .. srcDirName .. "/"
libDir = solutionDir .. libDirName .. "/"
testDir = solutionDir .. testDirName .."/"
outDirBase = solutionDir .. outDirBaseName .. "/"

outDir = outDirBase .. config .. "/"
intDir = outDirBase .. "obj/" .. config .. "/"

relSolutionDir = "../"
relSrcDir = relSolutionDir .. srcDirName .. "/"
relTestDir = relSolutionDir .. testDirName .. "/"

incDirs = { srcDir, (srcDir .. "Alixer"), libDir }

workspace "Alixer"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	location ("..")

group "src"
	include "premake5_src_Alixer.lua"
group ""

group "test"
	include "premake5_test_AlixerTests.lua"
group ""
