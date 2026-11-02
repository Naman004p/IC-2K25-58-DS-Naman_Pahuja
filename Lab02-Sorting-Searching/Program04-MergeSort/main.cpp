#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while (i <= mid) temp.push_back(a[i++]);
    while (j <= right) temp.push_back(a[j++]);
    for (int k = 0; k < (int)temp.size(); ++k) a[left + k] = temp[k];
}
void mergeSort(vector<int>& a, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n) || n < 0 || n > 100000) { cerr << "Invalid size.\n"; return 1; }
    vector<int> a(n);
    cout << "Enter elements: ";
    for (int& x : a) if (!(cin >> x)) { cerr << "Invalid input.\n"; return 1; }
    if (!a.empty()) mergeSort(a, 0, n - 1);
    cout << "Sorted array: ";
    for (int x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}
