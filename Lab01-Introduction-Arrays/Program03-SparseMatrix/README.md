# Program 03 – Sparse Matrix (Triplet Format)

## Problem statement
Represent a matrix using only its non-zero entries in triplet form and perform transpose and addition.

## Approach
Each stored term contains `(row, column, value)`. The header records matrix rows, columns, and the number of non-zero terms. Transpose swaps row and column. Addition first checks equal dimensions and combines corresponding values.

## Pseudocode
```text
Read matrix dimensions
For each cell: if value != 0, append (row, column, value)
Display dimensions and all triplets
Transpose: scan columns; append (column, row, value)
Addition: validate dimensions; add values at matching positions;
          store only non-zero results
```

## Dry run
Matrix:
```text
0 0 5
0 8 0
```
Triplets: header (2, 3, 2), then (0, 2, 5), (1, 1, 8).  
Transpose terms: (2, 0, 5), (1, 1, 8), with dimensions 3 × 2.

## Complexity
Let r × c be dimensions and k be non-zero terms.
- Build: O(r × c) time, O(k) storage.
- Transpose (implemented by scanning each column): O(c × k) time, O(k) output.
- Addition: O(r × c + k₁ + k₂) time, O(r × c) temporary dense storage in this straightforward implementation.

## Sample I/O
```text
Enter rows and columns: 2 3
Enter matrix elements:
0 0 5
0 8 0
Row Col Value
2 3 2
0   2   5
1   1   8
```

## Real-life application
Sparse matrices are used in graph adjacency matrices, scientific computing, and recommendation systems where most values are zero.
