import os
import subprocess
import platform

from SetupPython import PythonConfiguration as PythonConfig

# Check if we have everything we need for the setup
PythonConfig.Validate()