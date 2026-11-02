# Program 04 – Merge Sort

## Problem statement
Sort an integer array in ascending order using the divide-and-conquer Merge Sort algorithm.

## Algorithm
Divide the array into two halves until each subarray has one element. Recursively sort both halves, then merge the sorted halves into a temporary array.

## Pseudocode
```text
MERGE_SORT(A, left, right)
  IF left >= right, return
  mid = left + (right-left)/2
  MERGE_SORT(A, left, mid)
  MERGE_SORT(A, mid+1, right)
  MERGE the two sorted halves
```

## Dry run
Input [8, 3, 5, 1]  
Split [8,3] and [5,1] → [3,8] and [1,5]  
Merge → [1,3,5,8]

## Complexity
Best, average, worst: O(n log n). Auxiliary space O(n) for temporary merge arrays, plus O(log n) recursion stack. Stable: yes.

## Sample I/O
```text
Enter number of elements: 4
Enter elements: 8 3 5 1
Sorted array: 1 3 5 8
```

## Real-life application
Used for reliable sorting of large datasets and external sorting when data is too large for memory.
