#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>  // Для задержки в конце

using namespace std;

// --- Пространства имён с функциями calc ---
namespace add {
    int calc(int x, int y) {
        return x + y;
    }
}

namespace subtract {
    int calc(int x, int y) {
        return x - y;
    }
}

namespace multiply {
    int calc(int x, int y) {
        return x * y;
    }
}

namespace divide {
    int calc(int x, int y) {
        if (y != 0)
            return x / y;
        else
            return 0; // Обработка деления на ноль
    }
}

// --- Главная функция main ---
int main() {
    // Настройка русской кодировки для Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Жёстко задаём значения
    int x = 6;
    int y = 9;

    // Выводим результат
    cout << "x = " << x << ", y = " << y << endl;
    cout << "Сложение: " << add::calc(x, y) << endl;
    cout << "Вычитание: " << subtract::calc(x, y) << endl;
    cout << "Умножение: " << multiply::calc(x, y) << endl;
    cout << "Деление: " << divide::calc(x, y) << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}