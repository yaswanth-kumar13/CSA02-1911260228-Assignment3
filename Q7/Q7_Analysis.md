
# Q7 – Student Council Election Counting

## 1. Requirements
- Maximum 12 candidates.
- Up to 5000 votes in the basic problem.
- Reject candidate numbers outside 1 to c.
- Count valid and invalid votes.
- Display candidates in descending vote order.
- Identify winner or tie.

## 2. Arrays
votes[] stores the input vote sequence.
counts[] stores the number of votes per candidate.
results[] stores candidate numbers and vote totals.

## 3. Pseudocode
1. Initialise all candidate counts to zero.
2. Read each vote.
3. If vote is between 1 and c, increment its count.
4. Otherwise increment invalid count.
5. Sort candidate results by descending count.
6. Compare the highest two totals.
7. Report a winner or tie.

## 4. Complexity
Counting: O(v+c)
Sorting candidate results: O(c²)
Extra space: O(c), excluding the vote input array.

## 5. Alternative Approaches
Searching candidate names for every vote takes O(v*c) time.
Sorting all votes takes O(v log v) time.
A count array uses O(v+c) time and O(c) counting space.

## 6. Extension
For 500 candidates, increase the count array capacity to 500. A more efficient sorting method can be used for candidate results.

## 7. Limitation
The system assumes candidate numbers are valid identifiers and does not authenticate voters or prevent repeated voting.

## 8. Conclusion
A count array provides efficient election tallying by directly indexing candidate totals.
