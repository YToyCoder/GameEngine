workspace "GameEngine"
  architecture "x64"
  
  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GameEngine"
  location "GameEngine"
  kind "SharedLib"
  language "C++"
  
  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir("bin-int/" .. outputdir .. "/%{prj.name}")
  
  files 
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }
  includedirs 
  {
    "%{prj.name}/vendor/spdlog/include"
  }
  
  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "10.0"
    defines
    {
      "HZ_PLATFORM_WINDOWS",
      "HZ_BUILD_DLL"
    }
    postbuildcommands
    {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

  filter "configurations:Debug"
    defines "HZ_DEBUG"
    optimize "On"

  filter "configurations:Release"
    defines "HZ_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "HZ_DIST"
    optimize "On"

project "Sandbox" 
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"
  
  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir("bin-int/" .. outputdir .. "/%{prj.name}")
  
  files 
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }
  includedirs
  {
    "GameEngine/vendor/spdlog/include",
    "GameEngine/src"
  }
  links 
  {
    "GameEngine"
  }
  
  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "10.0"
    defines
    {
      "HZ_PLATFORM_WINDOWS"
    }

  filter "configurations:Debug"
    defines "HZ_DEBUG"
    optimize "On"

  filter "configurations:Release"
    defines "HZ_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "HZ_DIST"
    optimize "On"


