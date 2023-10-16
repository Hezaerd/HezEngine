import subprocess

import colorama
from colorama import Fore, Style

def InstallPackage(package):
    colorama.init(autoreset=True, convert=True)
    print(f"{Style.BRIGHT}{Fore.GREEN}Installing {package} module..")
    subprocess.check_call(['python', '-m', 'pip', 'install', package])

InstallPackage('setuptools')

import pkg_resources

def ValidatePackage(package):
    required = { package }
    print(f"{Style.BRIGHT}{Fore.LIGHTMAGENTA_EX}Checking if {package} module is installed..")
    installed = { pkg.key for pkg in pkg_resources.working_set}
    missing = required - installed

    if missing:
        InstallPackage(package)

def ValidatePackages(packages):
    colorama.init(autoreset=True, convert=True)
    for package in packages:
        ValidatePackage(package)
