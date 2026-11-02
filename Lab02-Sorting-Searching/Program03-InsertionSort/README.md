# Program 03 – Insertion Sort

## Problem statement
Sort an integer array in ascending order using Insertion Sort.

## Algorithm
Treat the first element as sorted. Take each next element as key, shift larger sorted elements one position right, and insert key into the gap.

## Pseudocode
```text
FOR i = 1 TO n-1
  key = A[i]; j = i-1
  WHILE j >= 0 AND A[j] > key
    A[j+1] = A[j]; j = j-1
  A[j+1] = key
```

## Dry run
Input [5, 2, 4, 6]  
Insert 2 → [2, 5, 4, 6]  
Insert 4 → [2, 4, 5, 6]  
Insert 6 → [2, 4, 5, 6]

## Complexity
Best O(n) for already sorted input; average O(n²); worst O(n²). Auxiliary space O(1). Stable: yes.

## Sample I/O
```text
Enter number of elements: 4
Enter elements: 5 2 4 6
Sorted array: 2 4 5 6
```

## Real-life application
Good for small datasets and maintaining a sorted list as new values arrive.
