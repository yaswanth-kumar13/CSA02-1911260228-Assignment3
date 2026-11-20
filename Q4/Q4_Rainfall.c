
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DISTRICTS 38
#define MONTHS 12

void annual_totals(double rain[DISTRICTS][MONTHS], double total[])
{
    for (int i = 0; i < DISTRICTS; i++)
    {
        total[i] = 0;
        for (int j = 0; j < MONTHS; j++)
            total[i] += rain[i][j];
    }
}

void monthly_averages(double rain[DISTRICTS][MONTHS], double avg[])
{
    for (int j = 0; j < MONTHS; j++)
    {
        double sum = 0;
        for (int i = 0; i < DISTRICTS; i++)
            sum += rain[i][j];

        avg[j] = sum / DISTRICTS;
    }
}

void wettest_month(double rain[DISTRICTS][MONTHS], int *district, int *month, double *maximum)
{
    *maximum = rain[0][0];
    *district = 0;
    *month = 0;

    for (int i = 0; i < DISTRICTS; i++)
        for (int j = 0; j < MONTHS; j++)
            if (rain[i][j] > *maximum)
            {
                *maximum = rain[i][j];
                *district = i;
                *month = j;
            }
}

void deficient_districts(double total[], double threshold)
{
    printf("\nDistricts below 60%% of state average:\n");

    for (int i = 0; i < DISTRICTS; i++)
        if (total[i] < threshold)
            printf("District %d: %.2f mm\n", i + 1, total[i]);
}

void benchmark(void)
{
    int n = 2000;
    double *a = malloc((size_t)n * n * sizeof(double));

    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    clock_t start = clock();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[(size_t)i * n + j] = i + j;

    clock_t row_end = clock();

    double sum = 0;

    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            sum += a[(size_t)i * n + j];

    clock_t col_end = clock();

    printf("\n2000 x 2000 Traversal Benchmark\n");
    printf("Row-wise: %.6f seconds\n",
           (double)(row_end - start) / CLOCKS_PER_SEC);
    printf("Column-wise: %.6f seconds\n",
           (double)(col_end - row_end) / CLOCKS_PER_SEC);
    printf("Checksum: %.0f\n", sum);

    free(a);
}

int main(void)
{
    double rain[DISTRICTS][MONTHS];
    double total[DISTRICTS];
    double average[MONTHS];

    for (int i = 0; i < DISTRICTS; i++)
        for (int j = 0; j < MONTHS; j++)
            rain[i][j] = 50 + ((i * 17 + j * 23) % 250);

    annual_totals(rain, total);
    monthly_averages(rain, average);

    printf("DISTRICT ANNUAL RAINFALL\n");

    for (int i = 0; i < DISTRICTS; i++)
        printf("District %d: %.2f mm\n", i + 1, total[i]);

    printf("\nSTATE MONTHLY AVERAGES\n");

    for (int j = 0; j < MONTHS; j++)
        printf("Month %d: %.2f mm\n", j + 1, average[j]);

    int district, month;
    double maximum;

    wettest_month(rain, &district, &month, &maximum);

    printf("\nWettest district: %d\n", district + 1);
    printf("Wettest month: %d\n", month + 1);
    printf("Maximum rainfall: %.2f mm\n", maximum);

    double state_average = 0;

    for (int j = 0; j < MONTHS; j++)
        state_average += average[j];

    deficient_districts(total, state_average * 12 * 0.60);

    printf("\nHAND VERIFICATION - 3 x 4 ARRAY\n");

    int small[3][4] = {
        {10, 20, 30, 40},
        {20, 30, 40, 50},
        {30, 40, 50, 60}
    };

    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
            sum += small[i][j];

        printf("Row %d total: %d\n", i + 1, sum);
    }

    benchmark();

    return 0;
}
