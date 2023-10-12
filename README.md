# HezEngine

## Getting Started
Visual Studio 2022 is recommended, but you can use any IDE that supports C++17.
Focus build on  Windows.

<ins>**1. Clone the repository:**</ins>

Start by cloning the repo with `git clone --recursive https://github.com/Hezaerd/HezEngine.git`

<ins>**2. Configuring dependencies:**</ins>
1. Run the [Setup.bat](https://github.com/Hezaerd/HezEngine/blob/main/scripts/Setub.bat) file found in `scripts` folder. This will download the requiered prerequisites if they are not already present.
2. One prerequisite is the Vulkan SDK. If it is not installed, the script will execute the `VulkanSDK.exe` file, and will prompt the user to install the SDK.
3. After installation, run the [Setup.bat](https://github.com/Hezaerd/HezEngine/blob/main/scripts/Setub.bat) file again. If the Vulkan SDK is installed properly, it will then download the Vulkan SDK Debug libraries. (This may take a longer amount of time)
4. After downloading and installing everything, the [GenerateProject.bat](https://github.com/Hezaerd/HezEngine/blob/main/scripts/GenerateProjects.bat) will be executed automatically. This will generate the Visual Studio solution and project files.

*Tips : No need to rerun the entire `setup.bat` after! Just build the `Premake` project in Visual Studio to regenerate the solution and project files.*

