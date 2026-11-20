
#include <stdio.h>

long long comparisons = 0;

int merge(const int a[], int na, const int b[], int nb, int out[])
{
    int i = 0, j = 0, k = 0;

    while (i < na && j < nb)
    {
        comparisons++;

        if (a[i] >= b[j])
            out[k++] = a[i++];
        else
            out[k++] = b[j++];
    }

    while (i < na)
        out[k++] = a[i++];

    while (j < nb)
        out[k++] = b[j++];

    return k;
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main(void)
{
    int campusA[] = {98, 91, 85, 72};
    int campusB[] = {95, 91, 80};
    int merged[7];

    int n = merge(campusA, 4, campusB, 3, merged);

    printf("MERGED MERIT LIST:\n");
    display(merged, n);
    printf("Comparisons: %lld\n", comparisons);

    int empty[] = {};
    int test[] = {90, 80, 70};
    int result[3];

    comparisons = 0;
    n = merge(empty, 0, test, 3, result);

    printf("\nEMPTY LIST TEST:\n");
    display(result, n);

    int equalA[] = {90, 90};
    int equalB[] = {90, 90};
    int equalResult[4];

    comparisons = 0;
    n = merge(equalA, 2, equalB, 2, equalResult);

    printf("\nEQUAL SCORES TEST:\n");
    display(equalResult, n);

    return 0;
}
