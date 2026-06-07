#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Partition(int a[], int low, int high)
{
    int i, j, temp, key;

    i = low + 1;
    j = high;
    key = a[low];

    while(1)
    {
        while(i < high && a[i] <= key)
            i++;

        while(a[j] > key)
            j--;

        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int j = Partition(a, low, high);

        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}

int main()
{
    int n;
    int a[50000];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    clock_t start = clock();

    quickSort(a, 0, n - 1);

    clock_t end = clock();

    double time_taken =
    ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nExecution Time = %lf seconds\n", time_taken);

    printf("\n\nObservation Table\n");
    printf("n\tTime(seconds)\n");

    int sizes[] = {1000, 5000, 10000, 20000, 50000};

    for(int s = 0; s < 5; s++)
    {
        int size = sizes[s];

        start = clock();

        for(int r = 0; r < 50; r++)
        {
            int *temp = (int *)malloc(size * sizeof(int));

            for(int i = 0; i < size; i++)
                temp[i] = rand();

            quickSort(temp, 0, size - 1);

            free(temp);
        }

        end = clock();

        double obs_time =
        ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d\t%lf\n", size, obs_time);
    }

    return 0;
} 