#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

// Обмен через XOR (без временной переменной)
void swap(int &a, int &b) {
    if (&a != &b) {  // Защита от обмена самим с собой
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

int main() {
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int a = 5, b = 8;

    cout << "До обмена: a = " << a << ", b = " << b << endl;

    swap(a, b);

    cout << "После обмена: a = " << a << ", b = " << b << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}