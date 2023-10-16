import subprocess

def InstallPackage(package):
    print(f"Installing {package} module..")
    subprocess.check_call(['python', '-m', 'pip', 'install', package])

InstallPackage('setuptools')

import pkg_resources

def ValidatePackage(package):
    required = { package }
    print(f"Checking if {package} module is installed..")
    installed = { pkg.key for pkg in pkg_resources.working_set}
    missing = required - installed

    if missing:
        InstallPackage(package)

def ValidatePackages(packages):
    for package in packages:
        ValidatePackage(package)
