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
    int numbers[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    
    cout << "Элементы массива:\n";
    
    // Выводим элементы через запятую и пробел
    for (int i = 0; i < 10; i++) {
        cout << numbers[i];
        if (i < 9) { // После последнего элемента запятую не ставим
            cout << ", ";
        }
    }
    
    // Задержка перед закрытием консоли
    cout << "\n\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}