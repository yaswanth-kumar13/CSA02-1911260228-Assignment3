
# Q5 – Processing Text Without the Library

## Null Character
The null character '\0' marks the end of a C string.

## Word Counting
Scan each character. Count a word when a non-space character follows the beginning of the string or whitespace.

## String Operations
Manual loops perform word counting, uppercase conversion, reversal and palindrome checking.

Library functions include strlen, strcpy, strcmp and toupper.

## Safety
strcpy can overflow a small destination array when the source is too long. snprintf limits the number of characters written. fgets is preferred for safe input.

gets() was removed because it cannot limit input length.

## String Storage
char s[] = "OK" creates a modifiable array.
char *s = "OK" points to a string literal and must not be modified.

## Complexity
Word count: O(n)
Uppercase: O(n)
Reverse: O(n)
Palindrome: O(n)
Extra space: O(1), excluding copied strings.

Repeated strlen in a loop condition can cause O(n²) time. Recursion uses O(n) stack space for reversal.

## Conclusion
Manual functions help understand character processing. Standard library functions are preferable for reliable production code when used safely.
