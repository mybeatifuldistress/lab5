#include <iostream>
#include <ctime>
#include <locale>

int main() {

    srand(time(NULL));
    setlocale(LC_ALL, "");

    int size;
    std::cout << "Введите размер матрицы смежности: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Размер матрицы должен быть > 0" << std::endl;
        return 0;
    }

    std::cout << std::endl;

    int** arr = new int* [size];
    for (int i = 0; i < size; ++i) {
        arr[i] = new int[size];
    }

    int count_smez = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                arr[i][j] = 0;
            }
            else if (i > j) {
                arr[i][j] = arr[j][i];
            }
            else {
                arr[i][j] = rand() % 2;
                if (arr[i][j] == 1) {
                    count_smez++;
                }
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "\nКоличество рёбер (размер) графа через матрицу смежности: " << count_smez << "\n\n";

    for (int i = 0; i < size; ++i) {
        int g = 0;
        for (int j = 0; j < size; ++j) {
            if (arr[i][j] == 1) {
                g++;
            }
        }

        if (g == 0) std::cout << "Вершина " << i + 1 << " - изолированная" << std::endl;
        if (g == 1) std::cout << "Вершина " << i + 1 << " - концевая" << std::endl;
        if (g == size - 1) std::cout << "Вершина " << i + 1 << " - доминирующая" << std::endl;
    }

    std::cout << "\n=========================================================================================\n";

    std::cout << "Матрица инцидентности:\n\n";
    int** arr1 = new int* [size];
    for (int i = 0; i < size; ++i) {
        arr1[i] = new int[count_smez] {};
    }

    int d = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr[i][j] == 1 && i < j) {
                arr1[i][d] = 1;
                arr1[j][d] = 1;
                d++;
            }
        }
    }

    int count_in = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < count_smez; ++j) {
            std::cout << arr1[i][j] << "\t";
            if (j + 1 > count_in) {
                count_in = j + 1;
            }
        }
        std::cout << std::endl;
    }

    std::cout << "\nКоличество рёбер (размер) графа через матрицу инцидентности: " << count_in << std::endl;

    for (int i = 0; i < size; ++i) {
        int g = 0;
        for (int j = 0; j < count_smez; ++j) {
            if (arr1[i][j] == 1) {
                g++;
            }
        }

        if (g == 0) std::cout << "Вершина " << i + 1 << " - изолированная" << std::endl;
        if (g == 1) std::cout << "Вершина " << i + 1 << " - концевая" << std::endl;
        if (g == size - 1) std::cout << "Вершина " << i + 1 << " - доминирующая" << std::endl;
    }

    for (int i = 0; i < size; ++i) {
        delete[] arr1[i];
    }
    delete[] arr1;

    for (int i = 0; i < size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
