# Program 01 – Bubble Sort

## Problem statement
Sort an integer array in ascending order using Bubble Sort.

## Algorithm
Compare adjacent elements and swap them when they are in the wrong order. After each pass, the largest unsorted element reaches its final position. Stop early if a pass makes no swaps.

## Pseudocode
```text
FOR i = 0 TO n-2
  swapped = false
  FOR j = 0 TO n-i-2
    IF A[j] > A[j+1], swap and set swapped = true
  IF swapped = false, stop
```

## Dry run
Input [5, 1, 4, 2]  
Pass 1: [1, 4, 2, 5]  
Pass 2: [1, 2, 4, 5]  
Pass 3: no swaps → stop.

## Complexity
Best O(n) with early stopping; average O(n²); worst O(n²). Auxiliary space O(1). Stable: yes.

## Sample I/O
```text
Enter number of elements: 4
Enter elements: 5 1 4 2
Sorted array: 1 2 4 5
```

## Real-life application
Useful for teaching sorting and for very small or nearly sorted lists.
