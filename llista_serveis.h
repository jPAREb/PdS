#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
void ErrorDescription(DWORD p_dwError);
using namespace std;

vector<string> llista_servei()
{
    vector<string> serveis_nom;
    SC_HANDLE hHandle = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (NULL == hHandle) {
        ErrorDescription(GetLastError());
        return serveis_nom;
    }
    
    ENUM_SERVICE_STATUS service;

    DWORD dwBytesNeeded = 0;
    DWORD dwServicesReturned = 0;
    DWORD dwResumedHandle = 0;
    DWORD dwServiceType = SERVICE_WIN32;
    // Query services
    BOOL retVal = EnumServicesStatus(hHandle, dwServiceType, SERVICE_STATE_ALL,
        &service, sizeof(ENUM_SERVICE_STATUS), &dwBytesNeeded, &dwServicesReturned,
        &dwResumedHandle);
    if (!retVal) {
        // Need big buffer
        if (ERROR_MORE_DATA == GetLastError()) {
            // Set the buffer
            DWORD dwBytes = sizeof(ENUM_SERVICE_STATUS) + dwBytesNeeded;
            ENUM_SERVICE_STATUS* pServices = NULL;
            pServices = new ENUM_SERVICE_STATUS[dwBytes];
            // Now query again for services
            EnumServicesStatus(hHandle, SERVICE_WIN32, SERVICE_STATE_ALL,
                pServices, dwBytes, &dwBytesNeeded, &dwServicesReturned, &dwResumedHandle);
            // now traverse each service to get information
            for (unsigned iIndex = 0; iIndex < dwServicesReturned; iIndex++) {
                wchar_t* servei = (pServices + iIndex)->lpServiceName;
                wstring ws(servei);
                string str(ws.begin(), ws.end());
                serveis_nom.push_back(str);
                //cout << str;
                //Sleep(1000);
                //cout << TEXT("Display Name") << (pServices + iIndex)->lpDisplayName << TEXT('\t');
                // << TEXT("Service Name") << (pServices + iIndex)->lpServiceName << endl;
                //serveis_nom.push_back((pServices + iIndex)->lpServiceName);
                //wprintf(serveis_nom.at(0));
                //cout << "\n";
                // << typeid((pServices + iIndex)->lpServiceName).name();
                //cout << "\n";
                //Sleep(100);
            }
            delete[] pServices;
            pServices = NULL;
        }
        // there is any other reason
        else {
            ErrorDescription(GetLastError());
        }
    }
    if (!CloseServiceHandle(hHandle)) {
        ErrorDescription(GetLastError());
    }
    
    return serveis_nom;
}
// get the description of error
void ErrorDescription(DWORD p_dwError) {

    HLOCAL hLocal = NULL;

    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER,
        NULL, p_dwError, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), (LPTSTR)&hLocal,
        0, NULL);

    MessageBox(NULL, (LPCTSTR)LocalLock(hLocal), TEXT("Error"), MB_OK | MB_ICONERROR);
    LocalFree(hLocal);
}