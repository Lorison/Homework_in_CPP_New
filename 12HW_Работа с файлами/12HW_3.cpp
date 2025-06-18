#include <iostream>
#include <fstream>
#include <windows.h>
#include <limits>    // ← Для задержки Enter

using namespace std;

int main()
{
    // Установка поддержки русского языка
    SetConsoleOutputCP(CP_UTF8);

    const string filename = "D:\\_Cpp_Projects\\12HW_Working wirh files\\in2.txt";

    // Шаг 1: Создание и запись в файл
    ofstream fout(filename);

    if (!fout)
    {
        cerr << "Ошибка: не удалось создать файл!" << endl;
        cout << "Нажмите Enter для выхода...";
        cin.get();
        return 1;
    }

    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    fout << n << endl; // Записываем размер массива

    cout << "Введите " << n << " целых чисел через пробел:" << endl;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        fout << arr[i] << " ";
    }

    fout << endl;
    fout.close();

    // Шаг 2: Чтение из файла
    ifstream fin(filename);
    if (!fin)
    {
        cerr << "Ошибка: не удалось открыть файл для чтения!" << endl;
        delete[] arr;
        cout << "Нажмите Enter для выхода...";
        cin.get();
        cin.get();
        return 2;
    }

    int size;
    fin >> size;

    int *readArr = new int[size];

    for (int i = 0; i < size && fin >> readArr[i]; ++i)
        ;

    // Шаг 3: Вывод массива в обратном порядке
    cout << "\nМассив в обратном порядке:" << endl;
    for (int i = size - 1; i >= 0; --i)
    {
        cout << readArr[i] << " ";
    }
    cout << endl;

    // Очистка памяти
    delete[] arr;
    delete[] readArr;

    // Задержка перед выходом
    cout << "Нажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}