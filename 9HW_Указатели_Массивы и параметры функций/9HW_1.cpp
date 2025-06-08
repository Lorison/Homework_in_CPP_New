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

int main() {
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Создаем массивы разных размеров
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[] = {6, 5, 4, 8};
    int arr3[] = {1, 4, 3, 7, 5};

    // Вызываем функцию print
    print(arr1, sizeof(arr1) / sizeof(arr1[0]));
    print(arr2, sizeof(arr2) / sizeof(arr2[0]));
    print(arr3, sizeof(arr3) / sizeof(arr3[0]));

    // Задержка перед закрытием консоли
    cout << "Нажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}