
#include <stdio.h>

int linear_search(const int a[], int n, int key, int *comparisons)
{
    *comparisons = 0;

    for (int i = 0; i < n; i++)
    {
        (*comparisons)++;

        if (a[i] == key)
            return i;
    }

    return -1;
}

int binary_search_count(const int a[], int n, int key, int *comparisons)
{
    int low = 0;
    int high = n - 1;

    *comparisons = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        (*comparisons)++;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(void)
{
    int sorted[] = {1021, 1048, 1103, 1190, 1222, 1305, 1377, 1402, 1460, 1533};
    int unsorted[] = {1305, 1021, 1460, 1103, 1533, 1222, 1048, 1402, 1190, 1377};
    int keys[] = {1021, 1305, 1533, 1400};
    int n = 10;

    printf("LIBRARY SEARCH COMPARISON\n\n");

    for (int i = 0; i < 4; i++)
    {
        int linear_comparisons, binary_comparisons;

        int linear_result = linear_search(unsorted, n, keys[i], &linear_comparisons);
        int binary_result = binary_search_count(sorted, n, keys[i], &binary_comparisons);

        printf("Book: %d\n", keys[i]);
        printf("Linear Search: Index = %d, Comparisons = %d\n",
               linear_result, linear_comparisons);
        printf("Binary Search: Index = %d, Comparisons = %d\n\n",
               binary_result, binary_comparisons);
    }

    return 0;
}
