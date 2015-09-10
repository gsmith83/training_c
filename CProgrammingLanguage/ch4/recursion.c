#include <stdio.h>

/*
    printd Recursively prints an integer in decimal form
*/
void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }

    if (n / 10)
    {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}

/* swap v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* 
    qsort recursively sorts v[left] ... v[right] into increasing order 
*/ 
void qsort(int v[], int left, int right)
{
    int i, last;

    if (left >= right)              /* do nothing if array contains */
        return;                     /* fewer than two elements      */
    swap(v, left, (left + right) / 2);  /* move partition element */
    last = left;                        /* to v[0] */
    for (i = left + 1; i <= right; i++)
    {
        if (v[i] < v[left])
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last); /* restore partition element */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}



int main(int argc, char * argv[])
{
    int n;
    if (argc == 2)
    {
        n = atoi(argv[1]);
        printd(n);
    }
    else if (argc > 2)
    {
        int intArray[argc - 1];

        for (n = 0; n < argc - 1; n++)
        {
            intArray[n] = atoi(argv[n + 1]);
        }

        qsort(intArray, 0, argc - 2);

        printf("Sorted Array: ");
        for (n = 0; n < argc - 1; n++)
        {
            printf("%d ", intArray[n]);
        }
    }
    else
        printf("*** ERROR: ***\tprintd requires one argument\n\t\tqsort requires more than one argument");

    putchar('\n');
    return 0;
}
