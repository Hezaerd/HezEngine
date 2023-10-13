import sys
import os
from pathlib import Path

import Utils

class PremakeConfiguration:
    premakeVersion = "5.0.0-beta1"
    premakeZipUrls = f"https://github.com/premake/premake-core/releases/download/v{premakeVersion}/premake-{premakeVersion}-windows.zip"
    premakeLicenseUrl = "https://raw.githubusercontent.com/premake/premake-core/master/LICENSE.txt"
    premakeDirectory = "./vendor/premake/bin"

    @classmethod
    def Validate(self):
        print("\n\nChecking if premake is installed...")
        if (not self.CheckPremake()):
            print("  Premake is not installed.")
            return
        
        print(f"\n  Correct premake version {self.premakeVersion} located at {os.path.abspath(self.premakeDirectory)}")
        return

    @classmethod
    def CheckPremake(self):
        premakeExecutable = Path(f"{self.premakeDirectory}/premake5.exe")
        if (not premakeExecutable.exists()):
            self.DownloadPremake()

        return True
    
    @classmethod
    def DownloadPremake(self):
        permission = False
        while not permission :
            reply = str(input("\n  Premake is not installed. Install it now? [Y/N]")).lower().strip()[:1]
            if reply == 'n':
                return False
            permission = (reply == 'y')

        # premake executable
        premakePath = f"{self.premakeDirectory}/premake-{self.premakeVersion}-windows.zip"
        print(f"  Downloading premake from {self.premakeZipUrls} to {premakePath}")
        Utils.DownloadFile(self.premakeZipUrls, premakePath)
        print(f"  Unzipping {premakePath}")
        Utils.UnzipFile(premakePath, self.premakeDirectory)
        print(f"  Premake {self.premakeVersion} has been installed to {self.premakeDirectory}")

        # premake license
        premakeLicensePath = f"{self.premakeDirectory}/LICENSE.txt"
        print(f"  Downloading premake license from {self.premakeLicenseUrl} to {premakeLicensePath}")
        Utils.DownloadFile(self.premakeLicenseUrl, premakeLicensePath)
        print(f"  Premake license has been installed to {self.premakeDirectory}")

        return True