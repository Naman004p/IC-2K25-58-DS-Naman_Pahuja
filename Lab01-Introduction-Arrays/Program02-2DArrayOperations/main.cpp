#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<int>>& a) {
    for (const auto& row : a) {
        for (int x : row) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    int r, c;
    cout << "Enter rows and columns: ";
    if (!(cin >> r >> c) || r <= 0 || c <= 0 || r > 50 || c > 50) {
        cerr << "Invalid dimensions (1 to 50 allowed).\n"; return 1;
    }
    vector<vector<int>> a(r, vector<int>(c));
    cout << "Enter matrix elements:\n";
    for (auto& row : a) for (int& x : row)
        if (!(cin >> x)) { cerr << "Invalid element.\n"; return 1; }

    int choice;
    do {
        cout << "\n1.Display  2.Search  3.Insert row  4.Delete row  5.Rotate square matrix 90 clockwise  0.Exit\nChoice: ";
        if (!(cin >> choice)) return 1;
        int x, y, value;
        switch (choice) {
        case 1: print(a); break;
        case 2: {
            cout << "Value: "; if (!(cin >> value)) return 1;
            bool found = false;
            for (int i = 0; i < (int)a.size(); ++i)
                for (int j = 0; j < (int)a[i].size(); ++j)
                    if (a[i][j] == value) { cout << "Found at (" << i << ", " << j << ")\n"; found = true; }
            if (!found) cout << "Not found.\n";
            break;
        }
        case 3: {
            cout << "Insert before row index (0 to " << r << "): ";
            if (!(cin >> x)) return 1;
            if (x < 0 || x > r) { cout << "Invalid row index.\n"; break; }
            vector<int> row(c);
            cout << "Enter " << c << " values: ";
            for (int& v : row) if (!(cin >> v)) return 1;
            a.insert(a.begin() + x, row); ++r; cout << "Row inserted.\n";
            break;
        }
        case 4:
            cout << "Row index to delete: "; if (!(cin >> x)) return 1;
            if (x < 0 || x >= r) cout << "Invalid row index.\n";
            else { a.erase(a.begin() + x); --r; cout << "Row deleted.\n"; }
            break;
        case 5:
            if (r != c) { cout << "Rotation requires a square matrix.\n"; break; }
            for (int i = 0; i < r; ++i)
                for (int j = i + 1; j < c; ++j) swap(a[i][j], a[j][i]);
            for (auto& row : a) reverse(row.begin(), row.end());
            cout << "Rotated matrix:\n"; print(a);
            break;
        case 0: cout << "Exiting.\n"; break;
        default: cout << "Choose a valid option.\n";
        }
    } while (choice != 0);
    return 0;
}
