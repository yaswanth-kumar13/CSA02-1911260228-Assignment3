
# Q3 – Merging Two Merit Lists

## 1. Objective
Combine two descending merit lists into one descending list without sorting again.

## 2. Algorithm
1. Initialise three indexes i, j and k to zero.
2. Compare the current elements of both arrays.
3. Copy the larger score into the output array.
4. Increment the corresponding index.
5. Copy remaining elements from either array.
6. Return the total number of elements.

## 3. Pseudocode
WHILE i < m AND j < n:
    IF A[i] >= B[j]:
        OUT[k] = A[i]
        i++
    ELSE:
        OUT[k] = B[j]
        j++
    k++

Copy remaining elements of A.
Copy remaining elements of B.

## 4. Complexity Analysis
Time complexity: O(m+n)
Extra space: O(m+n)
Maximum comparisons: m+n-1 for two non-empty lists.

## 5. Stability
When scores are equal, the >= condition selects Campus A first. This preserves the original order within each campus and gives Campus A priority for equal scores.

## 6. Edge Cases
- One empty list: Remaining elements of the other list are copied directly.
- All equal scores: All elements are retained.
- Different lengths: Remaining elements are copied after one list ends.

## 7. Alternative Concept
Using qsort() after combining both arrays requires O((m+n) log(m+n)) time.

A simple in-place merge can require O(m*n) time but avoids allocating a complete third array.

## 8. Conclusion
Merging sorted arrays is efficient because each element is processed once. It is suitable for combining campus merit lists.
