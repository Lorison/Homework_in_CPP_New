#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> // Для SetConsoleOutputCP
#include <direct.h>  // Для _getcwd
#include <limits>    // Для cin.ignore

using namespace std;

int main()
{
    // Установка UTF-8 для поддержки русского языка в Windows
    SetConsoleOutputCP(CP_UTF8);

    // Открываем файл
    ifstream fin("12HW_Working wirh files/in.txt");

    // Проверяем, открылся ли файл
    if (!fin)
    {
        cerr << "Ошибка: не удалось открыть файл 'in.txt'!" << endl;
        cout << "Убедитесь, что файл находится в той же папке, что и исполняемый файл." << endl;

        // Задержка перед выходом
        cout << "Нажмите Enter для выхода...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return 1;
    }

    string word;

    // Считываем по одному слову и выводим на экран
    while (fin >> word)
    {
        cout << word << endl;
    }

    // Закрываем файл
    fin.close();

    // Задержка перед закрытием консоли
    cout << "Файл успешно выведен. Нажмите Enter для выхода...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
