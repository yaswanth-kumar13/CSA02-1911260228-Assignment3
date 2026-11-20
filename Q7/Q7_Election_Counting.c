
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 12
#define MAX_VOTES 500000

typedef struct
{
    int candidate;
    int votes;
} Result;

void count_votes(const int votes[], int n, int candidates,
                 int counts[], int *valid, int *invalid)
{
    *valid = *invalid = 0;

    for (int i = 0; i < candidates; i++)
        counts[i] = 0;

    for (int i = 0; i < n; i++)
    {
        if (votes[i] >= 1 && votes[i] <= candidates)
        {
            counts[votes[i] - 1]++;
            (*valid)++;
        }
        else
            (*invalid)++;
    }
}

void sort_results(Result r[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (r[j].votes < r[j + 1].votes)
            {
                Result temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
            }
}

void report(const int counts[], int candidates, int valid, int invalid)
{
    Result r[MAX_CANDIDATES];

    for (int i = 0; i < candidates; i++)
    {
        r[i].candidate = i + 1;
        r[i].votes = counts[i];
    }

    sort_results(r, candidates);

    printf("\nVALID VOTES: %d\n", valid);
    printf("INVALID VOTES: %d\n", invalid);
    printf("\nCANDIDATE RESULTS\n");

    for (int i = 0; i < candidates; i++)
        printf("Candidate %d: %d votes\n",
               r[i].candidate, r[i].votes);

    if (valid == 0)
    {
        printf("No valid votes. No winner.\n");
        return;
    }

    if (candidates > 1 && r[0].votes == r[1].votes)
        printf("RESULT: TIE\n");
    else
        printf("WINNER: Candidate %d\n", r[0].candidate);
}

void experiment(int n, int candidates)
{
    int *votes = malloc((size_t)n * sizeof(int));

    if (!votes)
    {
        printf("Memory allocation failed\n");
        return;
    }

    int counts[MAX_CANDIDATES];
    int valid, invalid;

    srand(42);

    for (int i = 0; i < n; i++)
        votes[i] = 1 + rand() % candidates;

    clock_t start = clock();

    count_votes(votes, n, candidates, counts, &valid, &invalid);

    clock_t end = clock();

    printf("%d votes: %.6f seconds\n", n,
           (double)(end - start) / CLOCKS_PER_SEC);

    free(votes);
}

int main(void)
{
    int votes[] = {1, 2, 1, 3, 2, 1, 0, -1, 4};
    int candidates = 3;
    int counts[MAX_CANDIDATES];
    int valid, invalid;

    count_votes(votes, 9, candidates, counts, &valid, &invalid);

    printf("STUDENT COUNCIL ELECTION\n");
    report(counts, candidates, valid, invalid);

    printf("\nPERFORMANCE EXPERIMENTS\n");
    experiment(5000, 12);
    experiment(500000, 12);

    return 0;
}
