#include <iostream>
#include <fstream>
#include <windows.h>
#include <limits> // ← Для задержки Enter

using namespace std;

int main()
{
    // Установка поддержки русского языка в Windows
    SetConsoleOutputCP(CP_UTF8);

    // Открываем файл для чтения
    ifstream fin("12HW_Working wirh files/in1.txt");

    int n;
    fin >> n; // Считываем количество элементов

    // Выделяем память под массив
    int *arr = new (nothrow) int[n];
    if (!arr)
    {
        cerr << "Ошибка: не удалось выделить память!" << endl;
        fin.close();

        cout << "Нажмите Enter для выхода...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return 2;
    }

    // Считываем элементы массива
    for (int i = 0; i < n; ++i)
    {
        if (!(fin >> arr[i]))
        {
            cerr << "Ошибка: некорректные данные в файле!" << endl;
            delete[] arr;
            fin.close();

            cout << "Нажмите Enter для выхода...";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            return 3;
        }
    }

    // Выводим массив в обратном порядке
    cout << "Массив в обратном порядке:" << endl;
    for (int i = n - 1; i >= 0; --i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Освобождаем память и закрываем файл
    delete[] arr;
    fin.close();

    // Задержка перед закрытием окна
    cout << "Нажмите Enter для выхода...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}