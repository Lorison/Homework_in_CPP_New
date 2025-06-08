#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

// Функция для вывода массива
void print(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция для переворота массива
void reverse(int* arr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        // Меняем местами i-й элемент с (size - 1 - i)-м
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Создаем массив
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Вывод до изменения
    cout << "До функции reverse: ";
    print(arr, size);

    // Вызываем функцию reverse
    reverse(arr, size);

    // Вывод после изменения
    cout << "После функции reverse: ";
    print(arr, size);

    // Задержка перед закрытием консоли
    cout << "Нажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}