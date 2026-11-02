# Program 02 – 2D Array Operations

## Problem statement
Perform display, search, row insertion/deletion, and 90-degree clockwise rotation on a matrix.

## Approach
Store the matrix as a vector of rows. Search scans each cell. Row insertion/deletion uses a validated row index. For rotation, require a square matrix, transpose it in place, then reverse each row.

## Pseudocode
```text
Read rows, columns and matrix
REPEAT
  Display: print every row
  Search: inspect every cell for target
  Insert row: validate index; read a full row; insert
  Delete row: validate index; erase row
  Rotate: if rows = columns, transpose then reverse each row
UNTIL Exit
```

## Dry run
Input matrix:
```text
1 2
3 4
```
Transpose → `1 3 / 2 4`; reverse each row → `3 1 / 4 2`.

## Complexity
- Display/search: O(r × c) time.
- Row insertion/deletion: O(r × c) worst case due to shifting rows.
- 90° rotation: O(n²) time and O(1) auxiliary space for an n × n matrix.

## Sample I/O
```text
Enter rows and columns: 2 2
Enter matrix elements:
1 2
3 4
Choice: 5
Rotated matrix:
3 1
4 2
```

## Real-life application
A 2D array models seating plans, image pixels, game boards, and spreadsheet-like data.
