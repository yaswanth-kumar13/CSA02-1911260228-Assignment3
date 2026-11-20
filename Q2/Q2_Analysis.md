
# Q2 – Sorting the Examination Hall Seating Register

## 1. Problem Analysis
The examination cell requires register numbers to be arranged in ascending order. Data may be sorted, nearly sorted, reverse sorted or random.

## 2. Algorithms
- Bubble Sort: Compares adjacent elements and swaps them when necessary. An early-exit flag stops the algorithm if no swaps occur.
- Selection Sort: Finds the smallest element and places it in the correct position.
- Insertion Sort: Inserts each element into its correct position in the already sorted portion.

## 3. Pseudocode

### Bubble Sort
1. Repeat through the array.
2. Set swapped = false.
3. Compare adjacent elements.
4. Swap if they are in the wrong order.
5. If no swaps occur, stop.

### Selection Sort
1. Find the minimum element in the unsorted portion.
2. Swap it with the first unsorted element.
3. Repeat until sorted.

### Insertion Sort
1. Select the next element as key.
2. Compare it with previous elements.
3. Shift larger elements right.
4. Insert the key in its correct position.

## 4. Complexity Analysis

| Algorithm | Best | Average | Worst | Extra Space |
|---|---|---|---|---|
| Bubble | O(n) | O(n²) | O(n²) | O(1) |
| Selection | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion | O(n) | O(n²) | O(n²) | O(1) |

## 5. Stability
- Bubble Sort: Stable.
- Selection Sort: Generally unstable.
- Insertion Sort: Stable.

Stability preserves the original relative order of students having equal marks.

## 6. Early Exit
The bubble sort flag identifies whether any swaps occurred during a pass. If no swaps occurred, the array is already sorted and further passes are unnecessary.

## 7. Experimental Investigation
The program measures comparisons and swaps or shifts for array sizes 100, 1000 and 10000 using four input orders.

Actual measurements are recorded in the program output and should be included in the experimental results.

## 8. Recommended Algorithm
Insertion sort is recommended for a seating register that is already sorted except for 20 late registrations. It performs efficiently when only a small number of elements are out of order.

## 9. Alternative Concept – Counting Sort
Counting sort stores the frequency of each register number in a count array.

Time complexity: O(n + k)
Extra space: O(k)

It is suitable when the range k of register numbers is reasonably small. It is inefficient when the register-number range is very large compared with the number of students.
