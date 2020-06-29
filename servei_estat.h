#pragma once
#include <iostream>
#include <windows.h>
#include <Lmcons.h>
#include <vector>
int servei_estat(LPCWSTR Nom_servei)
{

    LPCWSTR serviceName = Nom_servei;

    SC_HANDLE sch = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (sch == NULL) {
        //El OpenSCManager ha fallat
        return 1;
    }

    SC_HANDLE svc = OpenService(sch, serviceName, SC_MANAGER_ALL_ACCESS);
    if (svc == NULL) {
        //OpenService ha fallat
        return 1;
    }

    SERVICE_STATUS_PROCESS stat;
    DWORD needed = 0;
    BOOL ret = QueryServiceStatusEx(svc, SC_STATUS_PROCESS_INFO,
        (BYTE*)&stat, sizeof stat, &needed);
    if (ret == 0) {
        //QueryServiceStatusEx ha fallat
        return 1;
    }

    if (stat.dwCurrentState == SERVICE_RUNNING) {

        wprintf(TEXT("El servei '%s' està corrent\n"), serviceName);
    }
    else {
        wprintf(TEXT("El servei '%s' està innactiu\n"), serviceName);
    }

    CloseServiceHandle(svc);
    CloseServiceHandle(sch);

    return 0;
}