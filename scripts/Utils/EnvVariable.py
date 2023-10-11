import winreg

def GetSystemEnvVariable(name):
    key = winreg.CreateKey(winreg.HKEY_LOCAL_MACHINE, r"SYSTEM\CurrentControlSet\Control\Session Manager\Environment")
    try:
        return winreg.QueryValueEx(key, name)[0]
    except WindowsError:
        return None
    
def GetUserEnvVariable(name):
    key = winreg.CreateKey(winreg.HKEY_CURRENT_USER, r"Environment")
    try:
        return winreg.QueryValueEx(key, name)[0]
    except WindowsError:
        return None
    
    