#include <iostream>

using namespace std;

int main() {
    int arr[1000];
    int n;

    cout << "Enter number of elements: ";
    if (!(cin >> n) || n < 0 || n > 1000) {
        cout << "Invalid size.\n";
        return 1;
    }

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) {
            cout << "Invalid input.\n";
            return 1;
        }
    }

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
