#pragma once
#include <windows.h>
using namespace std;
DWORD processador_nuclis() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    return sysInfo.dwNumberOfProcessors;
}