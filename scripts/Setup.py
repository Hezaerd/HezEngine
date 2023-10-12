import os
import subprocess
import platform
import time

from SetupPython import PythonConfiguration as PythonConfig

# Check if we have everything we need for the setup
PythonConfig.Validate()

from SetupPremake import PremakeConfiguration as PremakeConfig
os.chdir('./../') # Move to the root directory

premakeInstalled = PremakeConfig.Validate()

elapsed = time.time()
print("\nUpdating submodules...")
subprocess.run(["git", "submodule", "update", "--init", "--recursive"])
print(f"Submodules updated in {time.time() - elapsed} seconds")

if (premakeInstalled):
    if platform.system() == "Windows":
        print("\nGenerating Visual Studio 2022 project files...")
        subprocess.call([os.path.abspath("./scripts/GenerateProjects.bat"), "nopause"])

        print("\nSetup completed!")
    else:
        print("\nHezEngine requires Premake5 to generate project files.")