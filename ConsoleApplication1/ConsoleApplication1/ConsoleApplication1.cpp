﻿#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

// Определение типа функции из DLL
typedef bool (*FindCharsFunc)(const char*, const char*);

int main() {
    setlocale(LC_ALL, "Russian");
    string word;
    // Имя библиотеки и имя функции
    const char* dllName = "FindChars.dll";
    const char* funcName = "FindCharsInString";

    // Ввод строки и символов от пользователя
    string inputString, inputChars;
    cout << "Введите строку: ";
    getline(cin, inputString);
    cout << "Введите символы для поиска: ";
    getline(cin, inputChars);

    // Загрузка библиотеки
    HMODULE hLib = LoadLibraryA(dllName);
    if (!hLib) {
        cerr << "Не удалось загрузить библиотеку: " << dllName << endl;
        return 1;
    }

    // Получение адреса функции
    FindCharsFunc findChars = (FindCharsFunc)GetProcAddress(hLib, funcName);
    if (!findChars) {
        cerr << "Не удалось найти функцию: " << funcName << endl;
        FreeLibrary(hLib);
        return 1;
    }

    // Вызов функции
    bool result = findChars(inputString.c_str(), inputChars.c_str());

    // Вывод результата
    if (result) {
        cout << "Все символы найдены в строке." << endl;
    }
    else {
        cout << "Не все символы найдены в строке." << endl;
    }

    // Освобождение библиотеки
    FreeLibrary(hLib);

    return 0;
}
