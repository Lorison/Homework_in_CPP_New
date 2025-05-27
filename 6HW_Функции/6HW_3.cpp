#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

// Рекурсивная функция вычисления числа Фибоначчи
int fibonacci(int n) {
    // Базовые случаи для выхода из рекурсии
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Рекурсивный вызов
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int count;
    cout << "Введите число: ";
    cin >> count;

    // Проверка ввода
    if (count < 0) {
        cout << "Число должно быть неотрицательным!\n";
    } else {
        cout << "Числа Фибоначчи: ";
        for (int i = 0; i < count; i++) {
            cout << fibonacci(i) << " ";
        }
        cout << endl;
    }

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}