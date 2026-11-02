# Program 04 – Matrix Calculator

## Problem statement
Create a menu-driven calculator for matrix addition, multiplication, transpose, and determinant of small square matrices.

## Approach
Use 2D vectors. Validate dimensions before each operation. Addition requires equal dimensions; multiplication requires columns(A) = rows(B). Transpose swaps elements across the main diagonal. Determinant uses Gaussian elimination with partial pivoting.

## Pseudocode
```text
REPEAT
  read menu choice
  Addition: read A,B; if dimensions equal, add corresponding cells
  Multiplication: read A,B; if compatible, use three nested loops
  Transpose: swap A[i][j] with A[j][i] for j > i
  Determinant: pivot each column, eliminate below pivot, multiply pivots
UNTIL Exit
```

## Dry run
A = [[1, 2], [3, 4]], B = [[5, 6], [7, 8]]
- A + B = [[6, 8], [10, 12]]
- A × B = [[19, 22], [43, 50]]
- transpose(A) = [[1, 3], [2, 4]]
- det(A) = 1×4 − 2×3 = −2

## Complexity
For an n × n matrix:
- Addition: O(n²) time, O(1) extra space when modifying one matrix.
- Multiplication: O(n³) time, O(n²) result space.
- Transpose: O(n²) time, O(1) auxiliary space.
- Determinant by elimination: O(n³) time, O(n²) working matrix.

## Sample I/O
```text
MATRIX CALCULATOR
1.Addition  2.Multiplication  3.Transpose  4.Determinant  0.Exit
Choice: 4
Enter order of square matrix (1-10): 2
Enter matrix:
1 2
3 4
Determinant = -2
```

## Real-life application
Matrix calculations are used in computer graphics, engineering, data analysis, and scientific simulations.
