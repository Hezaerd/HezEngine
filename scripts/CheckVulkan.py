import os
from pathlib import Path

import Utils

import colorama
from colorama import Fore, Style

VULKAN_SDK = os.environ.get('VULKAN_SDK')
HEZENGINE_REQUIRED_VULKAN_VERSION = '1.3.' # Any 1.3.x version is fine
HEZENGINE_INSTALL_VULKAN_VERSION = '1.3.216.0' # Install this one if no 1.3.x version is found
VULKAN_SDK_INSTALLER_URL = f'https://sdk.lunarg.com/sdk/download/{HEZENGINE_INSTALL_VULKAN_VERSION}/windows/VulkanSDK-{HEZENGINE_INSTALL_VULKAN_VERSION}-Installer.exe'
VULKAN_SDK_LOCAL_PATH = 'HezEngine/vendor/VulkanSDK'
VULKAN_SDK_EXE_PATH = f'{VULKAN_SDK_LOCAL_PATH}/VulkanSDK.exe'

def InstallVulkanSDK():
    Path(VULKAN_SDK_LOCAL_PATH).mkdir(parents=True, exist_ok=True)
    print(f"{Style.BRIGHT}{Fore.GREEN}Downloading {VULKAN_SDK_INSTALLER_URL} to {VULKAN_SDK_LOCAL_PATH}..")
    Utils.DownloadFile(VULKAN_SDK_INSTALLER_URL, VULKAN_SDK_LOCAL_PATH)
    print(f"{Style.BRIGHT}{Fore.GREEN}Running VulkanSDK installer..")
    print(f"{Style.BRIGHT}{Fore.YELLOW}Make sure to install shader debug libs if you want to use build Debug!")
    print(f"{Style.BRIGHT}{Fore.YELLOW}Follow instructions on https://github.com/Hezaerd/HezEngine#how-to-install-the-vulkan-sdk-debug-libraries")
    print(f"{Style.BRIGHT}{Fore.RED}Re-run this script after installation")

def InstallVulkanPrompt():
    print("Vulkan SDK not found")
    print("Would you like to instaall the Vulkan SDK?")
    install = Utils.YesOrNo()
    if install:
        InstallVulkanSDK()
        quit()

def CheckVulkanSDK():
    if VULKAN_SDK is None:
        print(f"{Style.BRIGHT}{Fore.RED}Vulkan SDK not found")
        InstallVulkanPrompt()
        return False
    elif HEZENGINE_REQUIRED_VULKAN_VERSION not in VULKAN_SDK:
        print(f"Located Vulkan SDK at {VULKAN_SDK}")
        print(f"{Style.BRIGHT}{Fore.RED}You don't have the required version of the Vulkan SDK (HezEngine requires {HEZENGINE_REQUIRED_VULKAN_VERSION})")
        InstallVulkanPrompt()
        return False
    
    print(f"{Style.BRIGHT}{Fore.GREEN}Correct Vulkan SDK found at {VULKAN_SDK}")
    return True

def CheckVulkanSDKDebugLibs():
    shadercdLib = Path(f"{VULKAN_SDK}/Lib/shaderc_sharedd.lib")
    if not shadercdLib.exists():
        print(f"{Style.BRIGHT}{Fore.YELLOW}Warning: No Vulkan SDK debug libs found. (Checked {shadercdLib})")
        print(f"{Fore.RED}Debug builds are not possible.")
        print("Please install VulkanSDK debug libs as shown in https://github.com/Hezaerd/HezEngine#how-to-install-the-vulkan-sdk-debug-libraries")
        return False
    
    return True