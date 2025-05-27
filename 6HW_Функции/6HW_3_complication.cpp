#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>
#include <vector>

using namespace std;

vector<unsigned long long> computeFibonacci(int n) {
    vector<unsigned long long> fibSequence;
    if (n >= 1) fibSequence.push_back(0);
    if (n >= 2) fibSequence.push_back(1);
    
    for (int i = 2; i < n; i++) {
        fibSequence.push_back(fibSequence[i-1] + fibSequence[i-2]);
    }
    return fibSequence;
}

int main() {
    // Настройка кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int count;
    cout << "Введите количество чисел Фибоначчи (1-93): ";
    cin >> count;

    if (!cin || count <= 0) {
        cout << "Ошибка: введите положительное число!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } 
    else if (count > 93) {
        cout << "Ограничение: максимум 93 числа (из-за размера unsigned long long)\n";
        count = 93;
    }

    const auto fibNumbers = computeFibonacci(count);
    
    cout << "\nПервые " << count << " чисел Фибоначчи:\n";
    for (size_t i = 0; i < fibNumbers.size(); ++i) {  // Исправлено здесь
        cout << (i+1) << ": " << fibNumbers[i] << "\n";
    }

    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}
