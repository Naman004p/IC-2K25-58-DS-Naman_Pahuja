# Program 02 – Selection Sort

## Problem statement
Sort an integer array in ascending order using Selection Sort.

## Algorithm
At each position i, find the smallest value in the unsorted suffix and swap it with A[i].

## Pseudocode
```text
FOR i = 0 TO n-2
  minIndex = i
  FOR j = i+1 TO n-1
    IF A[j] < A[minIndex], minIndex = j
  Swap A[i] and A[minIndex]
```

## Dry run
Input [64, 25, 12, 22]  
Pass 1: [12, 25, 64, 22]  
Pass 2: [12, 22, 64, 25]  
Pass 3: [12, 22, 25, 64]

## Complexity
Best, average, worst: O(n²) comparisons. Auxiliary space O(1). Standard selection sort is not stable.

## Sample I/O
```text
Enter number of elements: 4
Enter elements: 64 25 12 22
Sorted array: 12 22 25 64
```

## Real-life application
Useful when minimizing the number of swaps is important, such as when writes are relatively costly.
