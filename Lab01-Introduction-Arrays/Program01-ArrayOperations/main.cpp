#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr;
    int n, choice;

    cout << "Enter size of array: ";
    if (!(cin >> n) || n < 0) {
        cout << "Invalid size.\n";
        return 1;
    }

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        if (!(cin >> value)) {
            cout << "Invalid input.\n";
            return 1;
        }
        arr.push_back(value);
    }

    do {
        cout << "\n----- ARRAY OPERATIONS -----\n";
        cout << "1. Display Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Search Element\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            return 1;
        }

        int position, value;

        switch (choice) {
        case 1:
            cout << "Array: ";
            for (int element : arr) {
                cout << element << " ";
            }
            cout << "\n";
            break;

        case 2:
            cout << "Enter position and value: ";
            if (!(cin >> position >> value)) {
                return 1;
            }

            if (position < 1 || position > static_cast<int>(arr.size()) + 1) {
                cout << "Invalid position.\n";
            } else {
                arr.insert(arr.begin() + position - 1, value);
                cout << "Element inserted successfully.\n";
            }
            break;

        case 3:
            cout << "Enter position to delete: ";
            if (!(cin >> position)) {
                return 1;
            }

            if (position < 1 || position > static_cast<int>(arr.size())) {
                cout << "Invalid position.\n";
            } else {
                arr.erase(arr.begin() + position - 1);
                cout << "Element deleted successfully.\n";
            }
            break;

        case 4:
            cout << "Enter value to search: ";
            if (!(cin >> value)) {
                return 1;
            }

            {
                auto it = find(arr.begin(), arr.end(), value);

                if (it == arr.end()) {
                    cout << "Element not found.\n";
                } else {
                    cout << "Element found at position "
                         << it - arr.begin() + 1 << ".\n";
                }
            }
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
