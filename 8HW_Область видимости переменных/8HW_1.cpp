#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

// Функция, считающая количество вызовов
void counting_function() {
    static int count = 0;  // статическая переменная — существует всё время
    count++;

    cout << "Количество вызовов функции counting_function(): " << count << endl;
}

int main() {
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    for (int i = 0; i < 15; i++) {
        counting_function();
    }

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}