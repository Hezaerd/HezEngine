import subprocess
import time

import colorama
from colorama import Fore, Style

def UpdateSubmodules():
    colorama.init(autoreset=True, convert=True)

    print(f"{Style.BRIGHT}{Fore.CYAN}Updating submodules..")
    
    elapsed = time.time()
    subprocess.call(['git', 'submodule', 'update', '--init', '--recursive'])
    
    print(f"{Style.BRIGHT}{Fore.CYAN}Submodules updated in {round(time.time() - elapsed, 2)} secondes")