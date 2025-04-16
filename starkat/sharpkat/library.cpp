#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "entry.h"

BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        CreateThread(nullptr, 0, cs::main, hInstance, 0, nullptr);
    }

    return TRUE;
}