#include <iostream>

using namespace std;

int main() {
    const int MAX = 20;
    int arr[MAX][MAX];
    int rows, cols, choice;

    cout << "Enter number of rows and columns: ";
    if (!(cin >> rows >> cols) ||
        rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
        cout << "Invalid matrix dimensions.\n";
        return 1;
    }

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(cin >> arr[i][j])) {
                cout << "Invalid input.\n";
                return 1;
            }
        }
    }

    do {
        cout << "\n----- 2D ARRAY OPERATIONS -----\n";
        cout << "1. Display Matrix\n";
        cout << "2. Transpose Matrix\n";
        cout << "3. Calculate Row Sums\n";
        cout << "4. Calculate Column Sums\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            return 1;
        }

        switch (choice) {
        case 1:
            cout << "Matrix:\n";
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << arr[i][j] << "\t";
                }
                cout << "\n";
            }
            break;

        case 2:
            cout << "Transpose of Matrix:\n";
            for (int j = 0; j < cols; j++) {
                for (int i = 0; i < rows; i++) {
                    cout << arr[i][j] << "\t";
                }
                cout << "\n";
            }
            break;

        case 3:
            for (int i = 0; i < rows; i++) {
                int sum = 0;

                for (int j = 0; j < cols; j++) {
                    sum += arr[i][j];
                }

                cout << "Sum of row " << i + 1 << " = " << sum << "\n";
            }
            break;

        case 4:
            for (int j = 0; j < cols; j++) {
                int sum = 0;

                for (int i = 0; i < rows; i++) {
                    sum += arr[i][j];
                }

                cout << "Sum of column " << j + 1 << " = " << sum << "\n";
            }
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
