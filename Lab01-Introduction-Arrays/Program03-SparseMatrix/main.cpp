#include <iostream>

using namespace std;

int main() {
    const int MAX = 20;

    int matrix[MAX][MAX];
    int triplet[MAX * MAX + 1][3];

    int rows, cols;
    int count = 1;

    cout << "Enter number of rows and columns: ";
    if (!(cin >> rows >> cols) ||
        rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
        cout << "Invalid matrix dimensions.\n";
        return 1;
    }

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(cin >> matrix[i][j])) {
                cout << "Invalid input.\n";
                return 1;
            }

            // Store only non-zero elements.
            if (matrix[i][j] != 0) {
                triplet[count][0] = i;
                triplet[count][1] = j;
                triplet[count][2] = matrix[i][j];
                count++;
            }
        }
    }

    // Store rows, columns and number of non-zero elements.
    triplet[0][0] = rows;
    triplet[0][1] = cols;
    triplet[0][2] = count - 1;

    cout << "\nSparse Matrix in Triplet Representation:\n";
    cout << "Row\tColumn\tValue\n";

    for (int i = 0; i < count; i++) {
        cout << triplet[i][0] << "\t"
             << triplet[i][1] << "\t"
             << triplet[i][2] << "\n";
    }

    cout << "\nTranspose in Triplet Representation:\n";
    cout << "Row\tColumn\tValue\n";
    cout << cols << "\t" << rows << "\t" << count - 1 << "\n";

    for (int column = 0; column < cols; column++) {
        for (int i = 1; i < count; i++) {
            if (triplet[i][1] == column) {
                cout << triplet[i][1] << "\t"
                     << triplet[i][0] << "\t"
                     << triplet[i][2] << "\n";
            }
        }
    }

    return 0;
}
