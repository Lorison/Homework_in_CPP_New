#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

// Функция возведения в степень
int power(int value, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= value;
    }
    return result;
}

int main() {
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Вычисление и вывод результатов
    cout << "5 в степени 2 = " << power(5, 2) << endl;
    cout << "3 в степени 3 = " << power(3, 3) << endl;
    cout << "4 в степени 4 = " << power(4, 4) << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}