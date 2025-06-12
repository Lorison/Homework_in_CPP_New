#include <iostream>
#include <string>     // Для использования std::string
#include <clocale>
#include <windows.h>
#include <limits>     // Для numeric_limits

using namespace std;

int main() {
    // Настройка русской кодировки для Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Объявление переменных для имени и фамилии
    string name;
    string surname;

    // Ввод имени
    cout << "Введите имя: ";
    cin >> name;

    // Ввод фамилии
    cout << "Введите фамилию: ";
    cin >> surname;

    // Конкатенация (объединение) строк
    string greeting = "Здравствуйте, " + name + " " + surname + "!";

    // Вывод приветствия
    cout << greeting << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}