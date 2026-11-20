# Q1 – Searching a Library Catalogue

## 1. Problem Analysis
The library stores accession numbers in an array. Students search for books using accession numbers.

Two searching algorithms are considered:
- Linear Search
- Binary Search

## 2. Binary Search Pseudocode
1. Set low = 0 and high = n - 1.
2. Calculate mid = low + (high - low) / 2.
3. Compare a[mid] with the search key.
4. If equal, return the index.
5. If smaller, search the right half.
6. Otherwise, search the left half.
7. Repeat until found or the range becomes empty.

## 3. Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best | O(1) |
| Average | O(log n) |
| Worst | O(log n) |

Extra space: O(1).

## 4. Experimental Output

| Accession Number | Result Index | Comparisons |
|---|---:|---:|
| 1021 | 0 | 3 |
| 1305 | 5 | 3 |
| 1533 | 9 | 4 |
| 1400 | -1 | 4 |

## 5. Technical Explanation

Binary search requires sorted data because it eliminates half of the remaining search range after every comparison.

The midpoint formula avoids potential integer overflow.

A missing book can require the maximum number of comparisons because the search must eliminate all possible positions before confirming that the key is absent.

## 6. Alternative Concepts

### Hash Table
- Average search time: O(1).
- Worst-case search time: O(n).
- Extra space: O(n).
- Linear probing can resolve collisions.

### Interpolation Search
- Average search time: O(log log n) for suitably uniformly distributed sorted data.
- Worst-case search time: O(n).
- Extra space: O(1).

## 7. Conclusion

Binary search is suitable for a large, sorted library catalogue because it requires fewer comparisons than linear search. However, the cost of maintaining sorted order when new books are added must also be considered.