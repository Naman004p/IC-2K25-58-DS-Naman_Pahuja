#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n) || n < 0 || n > 100000) { cerr << "Invalid size.\n"; return 1; }
    vector<int> a(n);
    cout << "Enter elements: ";
    for (int& x : a) if (!(cin >> x)) { cerr << "Invalid input.\n"; return 1; }
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
            if (a[j] > a[j + 1]) { swap(a[j], a[j + 1]); swapped = true; }
        if (!swapped) break;
    }
    cout << "Sorted array: ";
    for (int x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}
