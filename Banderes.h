#pragma once
#include <windows.h>
#include <stdio.h>
void color_lletres(WORD* Attributes, DWORD Colour)
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

void bandera_senyera()
{
    WORD Attributes = 0;
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
    cout << "                                          \n";
    Sleep(2000);
    color_lletres(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void bandera_estanquera()
{
    WORD Attributes = 0;
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
    cout << "                                          \n";
    color_lletres(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
    Sleep(2000);
    color_lletres(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}