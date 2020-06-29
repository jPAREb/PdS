#pragma once
#include <windows.h>
using namespace std;
float _RAM_() {
    MEMORYSTATUSEX valor_memoria;
    valor_memoria.dwLength = sizeof(valor_memoria);
    GlobalMemoryStatusEx(&valor_memoria);
    return (float)valor_memoria.ullTotalPhys / (1024 * 1024 * 1024);
}