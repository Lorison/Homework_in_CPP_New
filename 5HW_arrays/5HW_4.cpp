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

    // Исходный неупорядоченный массив
    int arr[10] = {10, 3, 4, 1, 8, 9, 7, 2, 6, 5};

    // Вывод массива до сортировки
    cout << "Массив до сортировки: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Сортировка "обратным пузырьком"
    bool swapped;
    int n = 10; // Размер массива
    do {
        swapped = false;
        // Проход от конца массива к началу
        for (int i = n - 1; i > 0; i--) {
            // Если текущий элемент меньше предыдущего, меняем их местами
            if (arr[i] < arr[i - 1]) {
                // Обмен элементов
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = true;
            }
        }
        // После каждого прохода наименьший элемент "всплывает" в начало
    } while (swapped); // Повторяем, пока есть обмены

    // Вывод массива после сортировки
    cout << "Массив после сортировки: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}