import os
import webbrowser
from pathlib import Path

import Utils

class VulkanConfiguration:
    requiredVulkanVersion = "1.3."
    installVulkanVersion = "1.3.216.0"
    vulkanDirectory = "./HezEngine/vendor/VulkanSDK"

    @classmethod
    def Validate(self):
        print("\n\nChecking if Vulkan SDK is installed...")
        if (not self.CheckVulkanSDK()):
            print("\n  Vulkan SDK not installed correctly.")
            return
            
        if (not self.CheckVulkanSDKDebugLibs()):
            self.InstallVulkanSDKDebugLibsTuto()
        else:
            print("\n  Vulkan SDK debug libs found.")
            print("  Debug configuration will work.")

    @classmethod
    def CheckVulkanSDK(self):
        vulkanSDK = os.environ.get("VULKAN_SDK")
        if (vulkanSDK is None):
            print("\n  You don't have the Vulkan SDK installed!")
            self.__InstallVulkanSDK()
            return False
        else:
            print(f"\n  Located Vulkan SDK at {vulkanSDK}")

        if (self.requiredVulkanVersion not in vulkanSDK):
            print(f"  You don't have the correct Vulkan SDK version! (HezEngine requires {self.requiredVulkanVersion})")
            self.__InstallVulkanSDK()
            return False
    
        print(f"  Correct Vulkan SDK located at {vulkanSDK}")

        self.InstallVulkanSDKDebugLibsTuto()

        return True

    @classmethod
    def __InstallVulkanSDK(self):
        permission = False
        while not permission:
            reply = str(input("  Would you like to install VulkanSDK {0:s}? [Y/N]: ".format(self.installVulkanVersion))).lower().strip()[:1]
            if reply == 'n':
                return
            permission = (reply == 'y')

        vulkanInstallURL = f"https://sdk.lunarg.com/sdk/download/{self.installVulkanVersion}/windows/VulkanSDK-{self.installVulkanVersion}-Installer.exe"
        vulkanPath = f"{self.vulkanDirectory}/VulkanSDK-{self.installVulkanVersion}-Installer.exe"
        print("  Downloading {0:s} to {1:s}".format(vulkanInstallURL, vulkanPath))
        Utils.DownloadFile(vulkanInstallURL, vulkanPath)
        print("  Running Vulkan SDK installer...")
        os.startfile(os.path.abspath(vulkanPath))
        print("  Re-run this script after installation!")
        quit()

    @classmethod
    def CheckVulkanSDKDebugLibs(self):
        vulkanSDK = os.environ.get("VULKAN_SDK")
        shadercdLib = Path(f"{vulkanSDK}/Lib/shaderc_sharedd.lib")
        
        return shadercdLib.exists()
    
    @classmethod
    def InstallVulkanSDKDebugLibsTuto(self):
        print("\n  No Vulkan SDK debug libs found. Install Vulkan SDK with debug libs.")
        print("  Debug configuration will not work.")
        print("\n    To install Vulkan SDK with debug libs, check `https://github.com/Hezaerd/HezEngine/blob/main/README.md`")

        permission = False
        while not permission:
            reply = str(input("    Would you like to open the link ? [Y/N]: "))
            if reply == 'n':
                return
            permission = (reply == 'y')

        webbrowser.open("https://github.com/Hezaerd/HezEngine/blob/main/README.md", new=2, autoraise=True)


if __name__ == "__main__":
    VulkanConfiguration.Validate()