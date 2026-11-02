#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;
using Matrix = vector<vector<double>>;

Matrix readMatrix(int r, int c) {
    Matrix a(r, vector<double>(c));
    for (auto& row : a) for (double& x : row)
        if (!(cin >> x)) throw runtime_error("Invalid matrix element.");
    return a;
}
void print(const Matrix& a) {
    for (const auto& row : a) {
        for (double x : row) cout << x << '\t';
        cout << '\n';
    }
}
double determinant(Matrix a) {
    int n = (int)a.size();
    double det = 1.0;
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int r = i + 1; r < n; ++r)
            if (fabs(a[r][i]) > fabs(a[pivot][i])) pivot = r;
        if (fabs(a[pivot][i]) < 1e-10) return 0.0;
        if (pivot != i) { swap(a[pivot], a[i]); det = -det; }
        det *= a[i][i];
        for (int r = i + 1; r < n; ++r) {
            double factor = a[r][i] / a[i][i];
            for (int c = i + 1; c < n; ++c) a[r][c] -= factor * a[i][c];
        }
    }
    return det;
}
int main() {
    try {
        int choice;
        do {
            cout << "\nMATRIX CALCULATOR\n1.Addition  2.Multiplication  3.Transpose  4.Determinant  0.Exit\nChoice: ";
            if (!(cin >> choice)) throw runtime_error("Invalid menu input.");
            if (choice == 0) break;
            int r, c, r2, c2;
            if (choice == 1 || choice == 2) {
                cout << "Enter rows and columns of first matrix: ";
                if (!(cin >> r >> c) || r <= 0 || c <= 0 || r > 10 || c > 10) throw runtime_error("Dimensions must be 1 to 10.");
                cout << "Enter first matrix:\n"; Matrix a = readMatrix(r, c);
                cout << "Enter rows and columns of second matrix: ";
                if (!(cin >> r2 >> c2) || r2 <= 0 || c2 <= 0 || r2 > 10 || c2 > 10) throw runtime_error("Dimensions must be 1 to 10.");
                cout << "Enter second matrix:\n"; Matrix b = readMatrix(r2, c2);
                if (choice == 1) {
                    if (r != r2 || c != c2) { cout << "Addition requires equal dimensions.\n"; continue; }
                    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) a[i][j] += b[i][j];
                    print(a);
                } else {
                    if (c != r2) { cout << "Columns of A must equal rows of B.\n"; continue; }
                    Matrix product(r, vector<double>(c2, 0));
                    for (int i = 0; i < r; ++i) for (int k = 0; k < c; ++k)
                        for (int j = 0; j < c2; ++j) product[i][j] += a[i][k] * b[k][j];
                    print(product);
                }
            } else if (choice == 3 || choice == 4) {
                cout << "Enter order of square matrix (1-10): ";
                if (!(cin >> r) || r <= 0 || r > 10) throw runtime_error("Order must be 1 to 10.");
                cout << "Enter matrix:\n"; Matrix a = readMatrix(r, r);
                if (choice == 3) {
                    for (int i = 0; i < r; ++i) for (int j = i + 1; j < r; ++j) swap(a[i][j], a[j][i]);
                    print(a);
                } else cout << "Determinant = " << determinant(a) << '\n';
            } else cout << "Choose a valid option.\n";
        } while (choice != 0);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n'; return 1;
    }
    return 0;
}
