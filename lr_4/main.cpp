#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct DiagonalMatrixElement {
    int row, col, value;
};

vector<DiagonalMatrixElement> readDiagonalMatrix(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    vector<DiagonalMatrixElement> matrix;

    while (!file.eof()) {
        DiagonalMatrixElement element;
        file >> element.row >> element.col >> element.value;
        matrix.push_back(element);
    }

    file.close();

    return matrix;
}

void writeDiagonalMatrix(const string& filename, const vector<DiagonalMatrixElement>& matrix) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    for (const auto& element : matrix) {
        file << element.row << " " << element.col << " " << element.value << endl;
    }

    file.close();
}

void swapColumns(vector<DiagonalMatrixElement>& matrix, int col1, int col2) {
    for (auto& element : matrix) {
        if (element.col == col1) {
            element.col = col2;
        } else if (element.col == col2) {
            element.col = col1;
        }
    }
}

void printDiagonalMatrix(const vector<DiagonalMatrixElement>& matrix) {
    for (const auto& element : matrix) {
        cout << element.row << " " << element.col << " " << element.value << endl;
    }
}

int main() {
    string filename = "../matrix.txt";
    vector<DiagonalMatrixElement> originalDiagonalMatrix;

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Считать из файла\n";
        cout << "2. Вывести исходную диагональную схему на экран\n";
        cout << "3. Перестановка столбцов и запись в файл\n";
        cout << "0. Выход\n";
        cout << "Выберите опцию: ";
        cin >> choice;

        switch (choice) {
            case 1:
                originalDiagonalMatrix = readDiagonalMatrix(filename);
                cout << "Данные считаны из файла." << endl;
                break;
            case 2:
                cout << "Исходная диагональная схема:" << endl;
                printDiagonalMatrix(originalDiagonalMatrix);
                break;
            case 3: {
                int col1, col2;
                cout << "Введите номера столбцов для перестановки: ";
                cin >> col1 >> col2;
                swapColumns(originalDiagonalMatrix, col1, col2);
                cout << "Новая диагональная схема после перестановки столбцов:" << endl;
                printDiagonalMatrix(originalDiagonalMatrix);

                writeDiagonalMatrix("../output_matrix.txt", originalDiagonalMatrix);
                cout << "Новая диагональная схема записана в файл output_matrix.txt." << endl;
                break;
            }
            case 0:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Некорректный ввод. Попробуйте еще раз.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
