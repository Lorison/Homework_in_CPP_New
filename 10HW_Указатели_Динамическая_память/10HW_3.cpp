#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>  // Для numeric_limits

using namespace std;

// Функция создания двумерного динамического массива
int** create_two_dim_array(int rows, int cols) {
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    return arr;
}

// Функция заполнения таблицы умножения
void fill_two_dim_array(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = (i + 1) * (j + 1);  // Таблица умножения
        }
    }
}

// Функция вывода массива
void print_two_dim_array(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << "\t";  // Вывод с табуляцией
        }
        cout << endl;
    }
}

// Функция удаления двумерного массива
void delete_two_dim_array(int** arr, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];  // Удаляем каждую строку
    }
    delete[] arr;  // Удаляем массив указателей
}

// Функция задержки перед закрытием консоли
void waitForEnter() {
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    // Настройка русской кодировки для Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int rows, cols;

    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    // Проверка корректности ввода
    if (cin.fail() || rows <= 0 || cols <= 0) {
        cerr << "Ошибка: некорректные размеры массива." << endl;
        waitForEnter();
        return 1;
    }

    // Создание массива
    int** table = create_two_dim_array(rows, cols);

    // Заполнение массива
    fill_two_dim_array(table, rows, cols);

    // Вывод заголовка и самой таблицы
    cout << "Таблица умножения:" << endl;
    print_two_dim_array(table, rows, cols);

    // Освобождение памяти
    delete_two_dim_array(table, rows);

    // Задержка перед выходом
    waitForEnter();

    return 0;
}