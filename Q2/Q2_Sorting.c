
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

long long comparisons, operations;

void bubble_sort(int a[], int n)
{
    comparisons = operations = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                operations++;
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}

void selection_sort(int a[], int n)
{
    comparisons = operations = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (a[j] < a[min])
                min = j;
        }

        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            operations++;
        }
    }
}

void insertion_sort(int a[], int n)
{
    comparisons = operations = 0;

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (a[j] > key)
            {
                a[j + 1] = a[j];
                operations++;
                j--;
            }
            else
                break;
        }

        a[j + 1] = key;
    }
}

void generate(int a[], int n, int type)
{
    for (int i = 0; i < n; i++)
        a[i] = 1001 + i;

    if (type == 1)
    {
        for (int i = 0; i < 20 && i < n - 1; i++)
        {
            int p = n - 1 - i;
            int temp = a[p];
            a[p] = a[p - 1];
            a[p - 1] = temp;
        }
    }
    else if (type == 2)
    {
        for (int i = 0; i < n / 2; i++)
        {
            int temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
    }
    else if (type == 3)
    {
        for (int i = n - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}

int main(void)
{
    int original[MAX], a[MAX];
    int sizes[] = {100, 1000, 10000};
    char *orders[] = {"Sorted", "Nearly Sorted", "Reverse Sorted", "Random"};

    srand(42);

    printf("EXAMINATION REGISTER SORTING ANALYSIS\n");

    for (int s = 0; s < 3; s++)
    {
        int n = sizes[s];

        printf("\n========== ARRAY SIZE: %d ==========\n", n);

        for (int t = 0; t < 4; t++)
        {
            generate(original, n, t);

            printf("\nInput Order: %s\n", orders[t]);
            printf("Algorithm\tComparisons\tSwaps/Shifts\n");

            memcpy(a, original, n * sizeof(int));
            bubble_sort(a, n);
            printf("Bubble\t\t%lld\t\t%lld\n", comparisons, operations);

            memcpy(a, original, n * sizeof(int));
            selection_sort(a, n);
            printf("Selection\t%lld\t\t%lld\n", comparisons, operations);

            memcpy(a, original, n * sizeof(int));
            insertion_sort(a, n);
            printf("Insertion\t%lld\t\t%lld\n", comparisons, operations);
        }
    }

    return 0;
}
