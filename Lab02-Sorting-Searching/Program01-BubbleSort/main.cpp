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

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
