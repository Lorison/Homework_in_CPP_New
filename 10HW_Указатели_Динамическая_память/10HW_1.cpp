#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>  // Для numeric_limits

using namespace std;

const long long MAX_SIZE = 10;

void waitForEnter() {
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    long long size;
    cout << "Введите размер массива: ";
    cin >> size;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cerr << "Ошибка: вы ввели некорректное значение. Требуется число." << endl;
        waitForEnter();
        return 1;
    }

    if (size <= 0) {
        cerr << "Ошибка: размер массива должен быть положительным числом." << endl;
        waitForEnter();
        return 1;
    }

    if (size > MAX_SIZE) {
        cerr << "Ошибка: размер массива слишком велик. Максимум: " << MAX_SIZE << endl;
        waitForEnter();
        return 1;
    }

    int* arr = new (nothrow) int[size];
    if (arr == nullptr) {
        cerr << "Ошибка: не удалось выделить память под массив." << endl;
        waitForEnter();
        return 1;
    }

    cout << "Введите элементы массива:\n";
    for (long long i = 0; i < size; ++i) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cerr << "Ошибка: ожидается целое число для элемента массива." << endl;
            delete[] arr;
            waitForEnter();
            return 1;
        }
    }

    cout << "\nВведённый массив: ";
    for (long long i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    waitForEnter();

    return 0;
}