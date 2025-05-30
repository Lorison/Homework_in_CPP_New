#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

// Функция обмена значениями
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int a = 5, b = 8;

    cout << "a = " << a << ", b = " << b << endl;

    swap(a, b);  // Передача по ссылке

    cout << "a = " << a << ", b = " << b << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}