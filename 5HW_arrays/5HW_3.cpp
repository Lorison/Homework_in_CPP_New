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

    // Создаем и заполняем двумерный массив 3x6
    int matrix[3][6] = {
        {15, 24, 3, 42, 11, 8},
        {6, 17, 30, 9, 22, 13},
        {4, 19, 7, 28, 35, 2}
    };

    // Выводим массив в виде таблицы
    cout << "Массив:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Инициализируем переменные для хранения минимума и максимума
    int min_val = matrix[0][0];
    int max_val = matrix[0][0];
    int min_row = 0, min_col = 0;
    int max_row = 0, max_col = 0;

    // Поиск минимального и максимального элементов
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            if (matrix[i][j] < min_val) {
                min_val = matrix[i][j];
                min_row = i;
                min_col = j;
            }
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    // Выводим результаты
    cout << "Индекс минимального элемента: " << min_row << " " << min_col << endl;
    cout << "Индекс максимального элемента: " << max_row << " " << max_col << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}