import sys
import os
from pathlib import Path

import DownloadFromUrl
import UnzipFile

class PremakeConfiguration:
    premakeVersion = "5.0.0-beta1"
    premakeZipUrls = f"https://github.com/premake/premake-core/releases/download/v{premakeVersion}/premake-{premakeVersion}-windows.zip"
    premakeLicenseUrl = "https://raw.githubusercontent.com/premake/premake-core/master/LICENSE.txt"
    premakeDirectory = "./vendor/premake/bin"

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
            reply = str(input("Premake is not installed. Install it now? [Y/N]")).lower().strip()[:1]
            if reply == 'n':
                return False
            permission = (reply == 'y')

        premakePath = f"{self.premakeDirectory}/premake-{self.premakeVersion}-windows.zip"