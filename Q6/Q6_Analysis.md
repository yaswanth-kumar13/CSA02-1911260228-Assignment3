
# Q6 – Hostel Resident Directory

## Objective
Sort hostel resident names alphabetically, search by name and identify duplicates.

## Algorithm
1. Read names using fgets.
2. Remove trailing newline.
3. Sort names using strcmp.
4. Identify adjacent equal names.
5. Search using binary search.

## strcmp
strcmp compares character values until a difference or null terminator is found. It is case-sensitive.

## Case-insensitive comparison
Convert characters using tolower before comparing.

## Complexity
Bubble sorting: O(n²) comparisons.
Binary searching: O(log n) string comparisons.
Duplicate detection: O(n).

Each string comparison can examine up to L characters.

## Alternative
Sorting an array of indices or pointers avoids repeatedly copying entire names. It requires additional storage for indices or pointers.

Using qsort with pointers requires O(n log n) comparisons, with each comparison potentially examining O(L) characters.

## Conclusion
Sorting names makes searching and duplicate detection efficient. Sorting pointers or indices is useful when names are long.
