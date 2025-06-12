#include <iostream>
#include <string>         // Для std::string
#include <clocale>
#include <windows.h>
#include <limits>         // Для numeric_limits

using namespace std;

int main() {
    // Настройка русской кодировки для Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    const string secretWord = "малина";  // Загаданное слово
    string userGuess;                    // Слово, введённое пользователем

    do {
        cout << "Угадайте слово: ";
        cin >> userGuess;

        if (userGuess == secretWord) {
            cout << "Правильно! Вы победили! Загаданное слово — " << secretWord << endl;
        } else {
            cout << "Неправильно\n";
        }

    } while (userGuess != secretWord);

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}