#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

vector<ULARGE_INTEGER> _memoria_() {
    ULARGE_INTEGER bits_lliures_cridar, bits_total, bits_lliure;
    GetDiskFreeSpaceEx(L".", &bits_lliures_cridar, &bits_total, &bits_lliure);
    vector <ULARGE_INTEGER> memoria;
    memoria.push_back(bits_total);
    memoria.push_back(bits_lliure);

    //ALTRE OPCIÓ PER VEURE LA MEMORIA
    //MEMORYSTATUSEX statex;
    //statex.dwLength = sizeof(statex);
    //GlobalMemoryStatusEx(&statex);
    //cout << "Total System Memory: " << (statex.ullTotalPhys / 1024) / 1024 << "MB" << endl;

    return memoria;
}