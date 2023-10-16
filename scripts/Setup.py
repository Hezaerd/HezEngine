import os
import CheckPython

# Check if we have everything we need for the setup
CheckPython.ValidatePackages(['requests', 'fake-useragent', 'colorama'])

print("") # New line

import colorama
from colorama import Fore, Style, Back

# Move to the root directory
os.chdir('../') 

# Init colorama lib
colorama.init(autoreset=True, convert=True)

import CheckVulkan

if not CheckVulkan.CheckVulkanSDK():
    print(f"{Style.BRIGHT}{Back.RED}Vulkan SDK not installed.")
    exit()

if CheckVulkan.CheckVulkanSDKDebugLibs():
    print(f"{Style.BRIGHT}{Fore.GREEN}Vulkan SDK debug libs found.")

print("") # New line

# Check git submodules
import CheckSubmodules
CheckSubmodules.UpdateSubmodules()


print("") # New line

# Generate project
import GenerateProject
GenerateProject.GenerateProject()

print("") # New line