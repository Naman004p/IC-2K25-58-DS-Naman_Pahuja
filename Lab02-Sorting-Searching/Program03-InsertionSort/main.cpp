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
    for (int i = 1; i < n; ++i) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; }
        a[j + 1] = key;
    }
    cout << "Sorted array: ";
    for (int x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}
