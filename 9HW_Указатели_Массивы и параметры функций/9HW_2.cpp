#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

// Не подключаем using namespace std; чтобы избежать конфликта с std::swap

// Функция обмена через указатели
void swap(int* a, int* b) {
    int temp = *a;  // Сохраняем значение, на которое указывает a
    *a = *b;        // Записываем в a значение из b
    *b = temp;      // Записываем в b сохранённое значение
}

int main() {
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int a = 5, b = 8;

    std::cout << "a = " << a << ", b = " << b << std::endl;

    swap(&a, &b);  // Передаём адреса переменных

    std::cout << "a = " << a << ", b = " << b << std::endl;

    // Задержка перед закрытием консоли
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
