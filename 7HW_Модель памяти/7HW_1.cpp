#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

int main() {
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Создаем переменные разных типов
    int var_int = 0;
    short var_short = 0;
    long var_long = 0;
    long long var_long_long = 0;
    float var_float = 0.0f;
    double var_double = 0.0;
    long double var_long_double = 0.0L;
    bool var_bool = false;

    // Выводим информацию о переменных
    cout << "short: " << reinterpret_cast<void*>(&var_short) << " " << sizeof(var_short) << endl;
    cout << "int: " << reinterpret_cast<void*>(&var_int) << " " << sizeof(var_int) << endl;
    cout << "long: " << reinterpret_cast<void*>(&var_long) << " " << sizeof(var_long) << endl;
    cout << "long long: " << reinterpret_cast<void*>(&var_long_long) << " " << sizeof(var_long_long) << endl;
    cout << "float: " << reinterpret_cast<void*>(&var_float) << " " << sizeof(var_float) << endl;
    cout << "double: " << reinterpret_cast<void*>(&var_double) << " " << sizeof(var_double) << endl;
    cout << "long double: " << reinterpret_cast<void*>(&var_long_double) << " " << sizeof(var_long_double) << endl;
    cout << "bool: " << reinterpret_cast<void*>(&var_bool) << " " << sizeof(var_bool) << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}