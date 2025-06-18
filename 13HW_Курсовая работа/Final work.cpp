#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>     // Для system()
#include <windows.h>   // Для SetConsoleOutputCP и Sleep
#include <limits>      // Для numeric_limits
#include <direct.h>    // Для _getcwd

using namespace std;

// Функция вывода текущего состояния поля
void printGrid(const vector<vector<bool>>& grid, int generation, int liveCount) {
    system("cls"); // Очистка консоли в Windows

    cout << "Поколение: " << generation << endl;
    cout << "Количество живых клеток: " << liveCount << "\n\n";

    for (const auto& row : grid) {
        for (bool cell : row) {
            cout << (cell ? "* " : "- ");
        }
        cout << endl;
    }
}

// Подсчёт живых соседей вокруг клетки
int countLiveNeighbors(const vector<vector<bool>>& grid, int rows, int cols, int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                if (grid[nx][ny]) {
                    ++count;
                }
            }
        }
    }
    return count;
}

// Обновление состояния клеток по правилам игры
vector<vector<bool>> updateGrid(const vector<vector<bool>>& grid, int rows, int cols) {
    vector<vector<bool>> newGrid(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = countLiveNeighbors(grid, rows, cols, i, j);
            if (grid[i][j]) {
                newGrid[i][j] = (neighbors == 2 || neighbors == 3);
            } else {
                newGrid[i][j] = (neighbors == 3);
            }
        }
    }

    return newGrid;
}

// Подсчёт количества живых клеток
int countLiveCells(const vector<vector<bool>>& grid) {
    int count = 0;
    for (const auto& row : grid) {
        for (bool cell : row) {
            if (cell) ++count;
        }
    }
    return count;
}

// Проверка совпадения двух сеток
bool gridsEqual(const vector<vector<bool>>& a, const vector<vector<bool>>& b) {
    int rows = a.size();
    int cols = a[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для корректного отображения русского языка

    // Показываем текущую рабочую директорию
    char currentDir[1024];
    if (_getcwd(currentDir, sizeof(currentDir)) != nullptr) {
        cout << "Текущая рабочая директория: " << currentDir << endl;
    } else {
        cerr << "Не удалось получить текущую рабочую директорию." << endl;
    }

    // Указываем точный путь к input.txt
    string filename = "Final work_game Life/input.txt";

    ifstream fin(filename);
    if (!fin) {
        cerr << "Ошибка: файл \"" << filename << "\" не найден!\n";
        cerr << "Убедитесь, что он находится в папке Final work_game Life.\n\n";

        cout << "Нажмите Enter для выхода...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return 1;
    }

    int rows, cols;
    fin >> rows >> cols;

    vector<vector<bool>> grid(rows, vector<bool>(cols, false));
    int x, y;
    while (fin >> x >> y) {
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            grid[x][y] = true;
        }
    }

    fin.close();

    int generation = 0;
    bool changed = true;
    vector<vector<bool>> prevGrid;

    while (changed) {
        int liveCount = countLiveCells(grid);
        printGrid(grid, generation, liveCount);

        if (liveCount == 0) {
            cout << "Игра окончена: все клетки мертвы." << endl;
            break;
        }

        prevGrid = grid;
        grid = updateGrid(grid, rows, cols);
        changed = !gridsEqual(prevGrid, grid);

        if (!changed) {
            cout << "Игра окончена: стабильная конфигурация." << endl;
        }

        ++generation;
        Sleep(1000); // Задержка в 1 секунду
    }

    // Вывод финального состояния
    printGrid(grid, generation, countLiveCells(grid));

    // Завершение
    cout << "Игра завершена. Нажмите Enter для выхода...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
