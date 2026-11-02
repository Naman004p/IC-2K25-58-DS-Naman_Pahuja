#include <iostream>

using namespace std;

const int MAX = 10;

void readMatrix(double matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(cin >> matrix[i][j])) {
                throw 1;
            }
        }
    }
}

void displayMatrix(double matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

double determinant(double matrix[MAX][MAX], int n) {
    if (n == 1) {
        return matrix[0][0];
    }

    if (n == 2) {
        return matrix[0][0] * matrix[1][1]
             - matrix[0][1] * matrix[1][0];
    }

    double det = 0;
    double minor[MAX][MAX];

    for (int column = 0; column < n; column++) {
        int minorRow = 0;

        for (int i = 1; i < n; i++) {
            int minorColumn = 0;

            for (int j = 0; j < n; j++) {
                if (j != column) {
                    minor[minorRow][minorColumn] = matrix[i][j];
                    minorColumn++;
                }
            }

            minorRow++;
        }

        int sign = (column % 2 == 0) ? 1 : -1;
        det += sign * matrix[0][column]
             * determinant(minor, n - 1);
    }

    return det;
}

int main() {
    double first[MAX][MAX];
    double second[MAX][MAX];
    double result[MAX][MAX];

    int choice, rows, cols, rows2, cols2;

    do {
        cout << "\n----- MATRIX CALCULATOR -----\n";
        cout << "1. Matrix Addition\n";
        cout << "2. Matrix Multiplication\n";
        cout << "3. Matrix Transpose\n";
        cout << "4. Determinant\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            return 1;
        }

        if (choice == 1 || choice == 2) {
            cout << "Enter rows and columns of first matrix: ";
            if (!(cin >> rows >> cols) ||
                rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
                cout << "Invalid dimensions.\n";
                continue;
            }

            cout << "Enter first matrix elements:\n";
            try {
                readMatrix(first, rows, cols);
            } catch (...) {
                cout << "Invalid input.\n";
                return 1;
            }

            cout << "Enter rows and columns of second matrix: ";
            if (!(cin >> rows2 >> cols2) ||
                rows2 < 1 || rows2 > MAX || cols2 < 1 || cols2 > MAX) {
                cout << "Invalid dimensions.\n";
                continue;
            }

            cout << "Enter second matrix elements:\n";
            try {
                readMatrix(second, rows2, cols2);
            } catch (...) {
                cout << "Invalid input.\n";
                return 1;
            }

            if (choice == 1) {
                if (rows != rows2 || cols != cols2) {
                    cout << "Matrices must have equal dimensions.\n";
                    continue;
                }

                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        result[i][j] = first[i][j] + second[i][j];
                    }
                }

                cout << "Sum of matrices:\n";
                displayMatrix(result, rows, cols);
            } else {
                if (cols != rows2) {
                    cout << "Matrices cannot be multiplied.\n";
                    continue;
                }

                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols2; j++) {
                        result[i][j] = 0;

                        for (int k = 0; k < cols; k++) {
                            result[i][j] += first[i][k] * second[k][j];
                        }
                    }
                }

                cout << "Product of matrices:\n";
                displayMatrix(result, rows, cols2);
            }

        } else if (choice == 3) {
            cout << "Enter rows and columns: ";
            if (!(cin >> rows >> cols) ||
                rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
                cout << "Invalid dimensions.\n";
                continue;
            }

            cout << "Enter matrix elements:\n";
            try {
                readMatrix(first, rows, cols);
            } catch (...) {
                cout << "Invalid input.\n";
                return 1;
            }

            cout << "Transpose of matrix:\n";

            for (int j = 0; j < cols; j++) {
                for (int i = 0; i < rows; i++) {
                    cout << first[i][j] << "\t";
                }
                cout << "\n";
            }

        } else if (choice == 4) {
            cout << "Enter order of square matrix: ";
            if (!(cin >> rows) || rows < 1 || rows > MAX) {
                cout << "Invalid order.\n";
                continue;
            }

            cout << "Enter matrix elements:\n";
            try {
                readMatrix(first, rows, rows);
            } catch (...) {
                cout << "Invalid input.\n";
                return 1;
            }

            cout << "Determinant = "
                 << determinant(first, rows) << "\n";

        } else if (choice != 0) {
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
