#include <iostream>
#include <fstream>
#include <windows.h> // Для SetConsoleOutputCP
#include <limits>    // Для задержки
#include <direct.h>  // Для _getcwd

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8); // Поддержка русского языка

    const string filename = "D:\\_Cpp_Projects\\12HW_Working wirh files\\in3.txt";

    ifstream fin(filename);
    if (!fin)
    {
        cerr << "Ошибка: не удалось открыть файл для чтения!" << endl;
        cout << "Убедитесь, что файл in3.txt существует." << endl;

        cout << "Нажмите Enter для выхода...";
        cin.get();
        return 1;
    }

    int rows, cols;
    fin >> rows >> cols;

    // Создаём динамический двумерный массив
    int **arr = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        arr[i] = new int[cols];
    }

    // Считываем массив из файла
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (!(fin >> arr[i][j]))
            {
                cerr << "Ошибка: некорректные данные в файле!" << endl;
                // Очищаем память перед выходом
                for (int k = 0; k < rows; ++k)
                    delete[] arr[k];
                delete[] arr;
                fin.close();

                cout << "Нажмите Enter для выхода...";
                cin.get();
                return 2;
            }
        }
    }

    fin.close();

    // Выводим массив, каждую строку в обратном порядке
    cout << "\nМассив с развернутыми строками:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = cols - 1; j >= 0; --j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Освобождаем память
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;

    // Задержка перед закрытием окна
    cout << "Нажмите Enter для выхода...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}