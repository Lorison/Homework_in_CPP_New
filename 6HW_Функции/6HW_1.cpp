#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

// Объявления арифметических функций
int sum(int a, int b);
int diff(int a, int b);
int multiplication(int a, int b);
double division(int a, int b);

int main()
{
    // Настройка русской кодировки консоли
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Исходные числа для операций
    int a = 5, b = 10;

    // Вычисление результатов
    int s = sum(a, b);
    int dif = diff(a, b);
    int mult = multiplication(a, b);
    double div = division(a, b);

    // Вывод результатов
    cout << a << " + " << b << " = " << s << endl;
    cout << a << " - " << b << " = " << dif << endl;
    cout << a << " * " << b << " = " << mult << endl;
    cout << a << " / " << b << " = " << div << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}

// Реализация функции сложения
int sum(int a, int b) {
    return a + b;
}

// Реализация функции вычитания
int diff(int a, int b) {
    return a - b;
}

// Реализация функции умножения
int multiplication(int a, int b) {
    return a * b;
}

// Реализация функции деления
double division(int a, int b) {
    return static_cast<double>(a) / b;
}
