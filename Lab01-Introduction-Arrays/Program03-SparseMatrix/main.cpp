#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

struct Term { int row, col, value; };
struct Sparse {
    int rows, cols;
    vector<Term> terms;
};

Sparse readSparse() {
    Sparse s{};
    cout << "Enter rows and columns: ";
    if (!(cin >> s.rows >> s.cols) || s.rows <= 0 || s.cols <= 0 || s.rows > 100 || s.cols > 100)
        throw runtime_error("Invalid matrix dimensions.");
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < s.rows; ++i)
        for (int j = 0, x; j < s.cols; ++j) {
            if (!(cin >> x)) throw runtime_error("Invalid matrix element.");
            if (x != 0) s.terms.push_back({i, j, x});
        }
    return s;
}
void display(const Sparse& s) {
    cout << "Row Col Value\n";
    cout << s.rows << " " << s.cols << " " << s.terms.size() << "  (rows, columns, non-zero terms)\n";
    for (auto t : s.terms) cout << t.row << "   " << t.col << "   " << t.value << '\n';
}
Sparse transpose(const Sparse& s) {
    Sparse t{s.cols, s.rows, {}};
    for (int col = 0; col < s.cols; ++col)
        for (auto x : s.terms)
            if (x.col == col) t.terms.push_back({x.col, x.row, x.value});
    return t;
}
Sparse add(const Sparse& a, const Sparse& b) {
    if (a.rows != b.rows || a.cols != b.cols) throw runtime_error("Dimensions must match for addition.");
    vector<vector<int>> dense(a.rows, vector<int>(a.cols, 0));
    for (auto x : a.terms) dense[x.row][x.col] += x.value;
    for (auto x : b.terms) dense[x.row][x.col] += x.value;
    Sparse result{a.rows, a.cols, {}};
    for (int i = 0; i < a.rows; ++i)
        for (int j = 0; j < a.cols; ++j)
            if (dense[i][j] != 0) result.terms.push_back({i, j, dense[i][j]});
    return result;
}
int main() {
    try {
        cout << "First sparse matrix\n";
        Sparse a = readSparse();
        cout << "Triple representation:\n"; display(a);
        cout << "Transpose:\n"; display(transpose(a));
        char choice;
        cout << "Add a second matrix? (y/n): ";
        if (!(cin >> choice)) return 1;
        if (choice == 'y' || choice == 'Y') {
            cout << "Second sparse matrix\n";
            Sparse b = readSparse();
            cout << "Sum (triple representation):\n"; display(add(a, b));
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n'; return 1;
    }
    return 0;
}
