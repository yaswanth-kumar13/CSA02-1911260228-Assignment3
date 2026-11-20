
# Q4 – District Rainfall Records

## 1. Problem Analysis
A two-dimensional array stores monthly rainfall for 38 districts over 12 months.

## 2. Functions
- annual_totals(): Calculates annual rainfall per district.
- monthly_averages(): Calculates state monthly averages.
- wettest_month(): Finds the maximum rainfall and its location.
- deficient_districts(): Identifies districts below 60% of the annual state average.

## 3. Memory Layout
C stores two-dimensional arrays in row-major order.

Address formula:

Address(rain[i][j]) = Base + ((i * 12) + j) * sizeof(double)

## 4. Traversal Performance
Row-wise traversal accesses consecutive memory locations.
Column-wise traversal jumps between rows, reducing cache locality.

Actual timing measurements are recorded in the experimental results.

## 5. Three-Dimensional Extension
double rain[years][38][12];

This stores rainfall for multiple years, districts and months.

## 6. Alternative Representations
- One-dimensional array: Index = i * 12 + j.
- Array of pointers: Each pointer refers to a separately allocated district row.
- All provide O(1) element access.

The one-dimensional array has contiguous storage. Pointer-based rows may have separate memory locations and require additional pointer storage.

## 7. Complexity
Annual totals: O(38 * 12)
Monthly averages: O(38 * 12)
Maximum search: O(38 * 12)
Deficiency check: O(38)

## 8. Conclusion
A two-dimensional array provides organised storage and efficient row-wise access for district rainfall records.
