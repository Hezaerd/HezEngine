import subprocess

import colorama
from colorama import Fore, Style

def GenerateProject():
    colorama.init(autoreset=True, convert=True)

    print(f"{Style.BRIGHT}{Fore.GREEN}Generating Visual Studio 2022 solution.")
    subprocess.call(["vendor/premake/bin/premake5.exe", "vs2022"])