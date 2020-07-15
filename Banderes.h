#pragma once
#include <windows.h>
#include <stdio.h>

#define COLOR_VERMELL BACKGROUND_RED
#define COLOR_GROC (COLOR_VERMELL | BACKGROUND_GREEN)

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
    
    for(int i = 0; i < 5; i++) // es pinten les línies grogues i vermelles de cop, excepte en l'últim cas
    {
        color_lletres(&Attributes, BACKGROUND_INTENSITY | COLOR_GROC);
        cout << "                                          \n";
        
        if( i != 4) // en l'últim cas no es pinta el vermell
        {
            color_lletres(&Attributes, BACKGROUND_INTENSITY | COLOR_VERMELL);
            cout << "                                          \n";
        }
    }

    Sleep(2000);
    color_lletres(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void bandera_estanquera()
{
    WORD Attributes = 0;
    
    for(int i = 0; i < 2; i++) // primera línia vermella
    {
        color_lletres(&Attributes, BACKGROUND_INTENSITY | COLOR_VERMELL);
        cout << "                                          \n";
    }
    
    for(int i = 0; i < 4; i++) // primera (i única) línia groca
    {
        color_lletres(&Attributes, BACKGROUND_INTENSITY | COLOR_GROC);
        cout << "                                          \n";
    }

    for(int i = 0; i < 3; i++) // segona ( i última ) vermella
    {
        color_lletres(&Attributes, BACKGROUND_INTENSITY | COLOR_VERMELL);
        cout << "                                          \n";
    }
        
    Sleep(2000);
    color_lletres(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}
