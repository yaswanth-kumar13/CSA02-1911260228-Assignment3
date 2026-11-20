
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 5000
#define LEN 31

int comparisons = 0;
long long character_copies = 0;

int compare_names(const char a[], const char b[])
{
    comparisons++;
    return strcmp(a, b);
}

void sort_names(char names[][LEN], int n)
{
    char temp[LEN];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare_names(names[j], names[j + 1]) > 0)
            {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
                character_copies += strlen(names[j]) + strlen(names[j + 1]) + strlen(temp) + 3;
            }
        }
    }
}

int binary_search(char names[][LEN], int n, const char key[])
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (compare_names(names[mid], key) == 0)
            return mid;
        else if (strcmp(names[mid], key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(void)
{
    char names[MAX][LEN];
    int n;

    printf("Enter number of residents (maximum 5000): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX)
        return 1;

    getchar();

    for (int i = 0; i < n; i++)
    {
        printf("Name %d: ", i + 1);

        if (fgets(names[i], LEN, stdin) == NULL)
            return 1;

        names[i][strcspn(names[i], "\n")] = '\0';
    }

    sort_names(names, n);

    printf("\nSORTED DIRECTORY\n");

    for (int i = 0; i < n; i++)
        printf("%s\n", names[i]);

    printf("\nDuplicate names:\n");

    int found = 0;

    for (int i = 1; i < n; i++)
        if (strcmp(names[i], names[i - 1]) == 0)
        {
            printf("%s\n", names[i]);
            found = 1;
        }

    if (!found)
        printf("No duplicates\n");

    char key[LEN];

    printf("\nEnter name to search: ");

    if (fgets(key, LEN, stdin) == NULL)
        return 1;

    key[strcspn(key, "\n")] = '\0';

    comparisons = 0;
    int position = binary_search(names, n, key);

    if (position >= 0)
        printf("Name found at position %d\n", position + 1);
    else
        printf("Name not found\n");

    printf("Binary search comparisons: %d\n", comparisons);
    printf("Sorting strcmp calls: %d\n", comparisons);
    printf("Character copies during sorting: %lld\n", character_copies);

    return 0;
}
