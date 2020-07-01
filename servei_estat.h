#pragma once
#include <iostream>
#include <windows.h>
#include <Lmcons.h>
#include <vector>
void SetConsoleColour(WORD* Attributes, DWORD Colour)
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}
void ResetConsoleColour(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}

int servei_estat(LPCWSTR Nom_servei)
{
    WORD Attributes = 0;
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
        SetConsoleColour(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_GREEN);
        wprintf(TEXT("'%s' [CORRENT]"), serviceName);
        SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        printf("\n");
        
    }
    else {
        SetConsoleColour(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
        wprintf(TEXT("'%s' [APAGAT]"), serviceName);
        SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        printf("\n");
        
        
    }

    CloseServiceHandle(svc);
    CloseServiceHandle(sch);
    SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    return 0;
}