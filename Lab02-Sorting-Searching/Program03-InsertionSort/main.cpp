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

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
