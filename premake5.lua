workspace "Fizzion"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "Fizzion"
    location "Fizzion"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    --pchheader "fzpch.h"
    --pchsource "Fizzion/src/fzpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/lib/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FZ_PLATFORM_VALIDATE",
            "FZ_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "FZ_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "FZ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "FZ_DIST"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "Fizzion/lib/spdlog/include",
        "Fizzion/src"
    }

    links 
    {
        "Fizzion"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
    
        defines
        {
            "FZ_PLATFORM_VALIDATE"
        }
        
    filter "configurations:Debug"
        defines "FZ_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "FZ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "FZ_DIST"
        optimize "On"
