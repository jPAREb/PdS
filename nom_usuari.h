#pragma once
#include <iostream>
#include <windows.h>
#include <Lmcons.h>
using namespace std;
string nom_usuari() {
    TCHAR name[UNLEN + 1];
    DWORD size = UNLEN + 1;
    if (GetUserName((TCHAR*)name, &size)) {
        wstring ws(name);
        string str_nom(ws.begin(), ws.end());
        return str_nom;
    }
    else {
        string str_nom = "-";
        return str_nom;
    }
}