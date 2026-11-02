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
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[minIndex]) minIndex = j;
        if (minIndex != i) swap(a[i], a[minIndex]);
    }
    cout << "Sorted array: ";
    for (int x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}
