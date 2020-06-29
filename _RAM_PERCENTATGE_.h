#pragma once
#include <windows.h>
using namespace std;
DWORD _RAM_PERCENTATGE_() {
    MEMORYSTATUSEX valor_memoria;
    valor_memoria.dwLength = sizeof(valor_memoria);
    GlobalMemoryStatusEx(&valor_memoria);
    return valor_memoria.dwMemoryLoad;
}