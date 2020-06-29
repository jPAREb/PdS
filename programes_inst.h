#pragma once
#include <iostream>
#include <windows.h>
#include <vector>


using namespace std;
vector<string> programes_inst(void)
{
    vector<string> llistat_programes;
    HKEY hUninstKey = NULL;
    HKEY hAppKey = NULL;
    WCHAR sAppKeyName[1024];
    WCHAR sSubKey[1024];
    WCHAR sDisplayName[1024];
    const wchar_t* sRoot = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall";
    long lResult = ERROR_SUCCESS;
    DWORD dwType = KEY_ALL_ACCESS;
    DWORD dwBufferSize = 0;
    //Open the "Uninstall" key.
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, sRoot, 0, KEY_READ, &hUninstKey) != ERROR_SUCCESS)
    {
        //return false;
    }

    for (DWORD dwIndex = 0; lResult == ERROR_SUCCESS; dwIndex++)
    {
        //Enumerate all sub keys...
        dwBufferSize = sizeof(sAppKeyName);
        if ((lResult = RegEnumKeyEx(hUninstKey, dwIndex, sAppKeyName,
            &dwBufferSize, NULL, NULL, NULL, NULL)) == ERROR_SUCCESS)
        {
            //Open the sub key.
            wsprintf(sSubKey, L"%s\\%s", sRoot, sAppKeyName);
            if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, sSubKey, 0, KEY_READ, &hAppKey) != ERROR_SUCCESS) {
                RegCloseKey(hAppKey);
                RegCloseKey(hUninstKey);
                //return false;
            }
            //Get the display name value from the application's sub key.
            dwBufferSize = sizeof(sDisplayName);
            if (RegQueryValueEx(hAppKey, L"DisplayName", NULL,
                &dwType, (unsigned char*)sDisplayName, &dwBufferSize) == ERROR_SUCCESS)
            {
                //wprintf(L"%s\n", sDisplayName);
                const wchar_t* programa = (L"%s\n", sDisplayName);
                wstring transformacio_programa(programa);
                string programa_regedit(transformacio_programa.begin(), transformacio_programa.end());
                llistat_programes.push_back(programa_regedit);
            }
            else {
                //Display name value doe not exist, this application was probably uninstalled.
            }
            RegCloseKey(hAppKey);
        }
    }
    RegCloseKey(hUninstKey);
    return llistat_programes;
}