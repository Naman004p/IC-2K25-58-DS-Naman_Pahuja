#include <iostream>
#include <vector>
using namespace std;

void display(const vector<int>& a) {
    if (a.empty()) { cout << "Array is empty.\n"; return; }
    for (int x : a) cout << x << ' ';
    cout << '\n';
}

int main() {
    vector<int> a;
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n) || n < 0) { cerr << "Invalid size.\n"; return 1; }
    cout << "Enter elements: ";
    for (int i = 0, x; i < n; ++i) {
        if (!(cin >> x)) { cerr << "Invalid element.\n"; return 1; }
        a.push_back(x);
    }

    int choice;
    do {
        cout << "\n1.Insert  2.Delete  3.Search  4.Left rotate  5.Right rotate  6.Display  0.Exit\nChoice: ";
        if (!(cin >> choice)) { cerr << "Invalid input.\n"; return 1; }
        int pos, value;
        switch (choice) {
        case 1:
            cout << "Enter 0-based index and value: ";
            if (!(cin >> pos >> value)) return 1;
            if (pos < 0 || pos > (int)a.size()) cout << "Invalid index.\n";
            else { a.insert(a.begin() + pos, value); cout << "Inserted.\n"; }
            break;
        case 2:
            cout << "Enter 0-based index: ";
            if (!(cin >> pos)) return 1;
            if (pos < 0 || pos >= (int)a.size()) cout << "Invalid index.\n";
            else { a.erase(a.begin() + pos); cout << "Deleted.\n"; }
            break;
        case 3: {
            cout << "Enter value to search: ";
            if (!(cin >> value)) return 1;
            int i = 0;
            while (i < (int)a.size() && a[i] != value) ++i;
            if (i == (int)a.size()) cout << "Not found.\n";
            else cout << "Found at index " << i << ".\n";
            break;
        }
        case 4: case 5:
            cout << "Enter number of positions: ";
            if (!(cin >> pos)) return 1;
            if (!a.empty()) {
                int k = ((pos % (int)a.size()) + (int)a.size()) % (int)a.size();
                if (choice == 4) rotate(a.begin(), a.begin() + k, a.end());
                else rotate(a.begin(), a.end() - k, a.end());
                cout << "Array rotated.\n";
            } else cout << "Array is empty.\n";
            break;
        case 6: display(a); break;
        case 0: cout << "Exiting.\n"; break;
        default: cout << "Choose a valid option.\n";
        }
    } while (choice != 0);
    return 0;
}
