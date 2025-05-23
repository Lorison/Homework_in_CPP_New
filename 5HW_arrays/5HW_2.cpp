#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

int main() {
    // Настройка кодировки для UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Создаем и заполняем массив из 10 элементов
    int numbers[10] = {45, 6, 25, 1, 42, 10, 80, 30, 8, 11};
    
    // Выводим массив
    cout << "Массив: ";
    for (int i = 0; i < 10; i++) {
        cout << numbers[i];
        if (i < 9) {
            cout << " ";
        }
    }
    cout << endl;

    // Находим минимальный и максимальный элементы
    int min_num = numbers[0];
    int max_num = numbers[0];
    
    for (int i = 1; i < 10; i++) {
        if (numbers[i] < min_num) {
            min_num = numbers[i];
        }
        if (numbers[i] > max_num) {
            max_num = numbers[i];
        }
    }

    // Выводим результаты
    cout << "Минимальный элемент: " << min_num << endl;
    cout << "Максимальный элемент: " << max_num << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}
