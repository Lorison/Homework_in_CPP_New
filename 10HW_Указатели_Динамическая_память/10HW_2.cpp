#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>  // Для numeric_limits

using namespace std;

// Функция создания массива, заполненного нулями
double* create_array(int size) {
    return new (nothrow) double[size]();
}

// Функция задержки перед закрытием консоли
void waitForEnter() {
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    // Настройка русской кодировки для Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    // Проверка корректности ввода
    if (cin.fail() || size <= 0) {
        cerr << "Ошибка: некорректный размер массива." << endl;
        waitForEnter();
        return 1;
    }

    // Создаем массив с помощью функции
    double* arr = create_array(size);

    // Проверка успешности выделения памяти
    if (!arr) {
        cerr << "Ошибка: не удалось выделить память под массив." << endl;
        waitForEnter();
        return 1;
    }

    // Вывод массива
    cout << "Массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Освобождение памяти
    delete[] arr;

    // Задержка перед выходом
    waitForEnter();

    return 0;
}