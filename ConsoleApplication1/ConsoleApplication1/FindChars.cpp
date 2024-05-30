#include <windows.h>
#include <cstring>

// Определение функции, которая будет экспортирована из DLL
extern "C" __declspec(dllexport) bool FindCharsInString(const char* str, const char* chars) {
    while (*chars) {
        if (!strchr(str, *chars)) {
            return false;
        }
        chars++;
    }
    return true;
}

// Функция DllMain, которая вызывается при подключении/отключении DLL
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
