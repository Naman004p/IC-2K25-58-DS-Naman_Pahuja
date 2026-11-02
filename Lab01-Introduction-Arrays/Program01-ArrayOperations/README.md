# Program 01 – 1D Array Operations

## Problem statement
Implement insertion, deletion, linear search, and left/right rotation on a one-dimensional array.

## Approach / algorithm
Use a vector as a dynamically sized array. Validate every index before modifying it. Linear search checks elements from left to right. Rotation uses the normalized shift `k = positions % n`.

## Pseudocode
```text
REPEAT until Exit
  read choice
  IF Insert: validate 0 <= index <= size; insert value
  IF Delete: validate 0 <= index < size; erase element
  IF Search: scan from index 0 until value found or end
  IF Rotate: normalize k; move first k elements to end (left)
             or last k elements to front (right)
  IF Display: print all elements
END REPEAT
```

## Dry run
Initial array: [10, 20, 30, 40]
- Insert 25 at index 2 → [10, 20, 25, 30, 40]
- Search 30 → found at index 3
- Delete index 1 → [10, 25, 30, 40]
- Left rotate by 1 → [25, 30, 40, 10]

## Complexity
| Operation | Time | Extra space |
|---|---:|---:|
| Display | O(n) | O(1) |
| Search | O(n) | O(1) |
| Insert / delete | O(n) | O(n) worst case due to shifting/storage |
| Rotation | O(n) | O(1) auxiliary (container implementation dependent) |

## Sample I/O
```text
Enter number of elements: 4
Enter elements: 10 20 30 40
1.Insert  2.Delete  3.Search  4.Left rotate  5.Right rotate  6.Display  0.Exit
Choice: 3
Enter value to search: 30
Found at index 2.
```

## Real-life application
A playlist or circular schedule can rotate its sequence to bring the next item to the front.
