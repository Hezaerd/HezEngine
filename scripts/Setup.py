import os
import subprocess
import platform
import time

from SetupPython import PythonConfiguration as PythonConfig

# Check if we have everything we need for the setup
PythonConfig.Validate()

from SetupPremake import PremakeConfiguration as PremakeConfig
from SetupVulkan import VulkanConfiguration as VulkanConfig
os.chdir('./../') # Move to the root directory

PremakeConfig.Validate()
VulkanConfig.Validate()

elapsed = time.time()
print("\n\nUpdating submodules...")
subprocess.run(["git", "submodule", "update", "--init", "--recursive"])
print(f"\n  Submodules updated in {round(time.time() - elapsed, 2)} seconds")

if platform.system() == "Windows":
    print("\n\nGenerating Visual Studio 2022 project files using premake5...")
    subprocess.call([os.path.abspath("./scripts/GenerateProjects.bat"), "nopause"])

    print("\n\nSetup completed!\n")