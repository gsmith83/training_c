/* 
binary search
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_LENGTH 1500000


int main(int argc, char ** argv)
{
    int value, i, j, step, pos, elapsed;
    int range[RANGE_LENGTH];
    clock_t start, diff;
    
    printf("*** argv[0] ***\n");
    
    if(argc > 1)
    {
        value = atoi(argv[1]);
        j = 0;
        
        
        for(i = 0; i < RANGE_LENGTH; i++)
        {
            range[i] = j;
            step = 1 + (i & 3);
            j += step;
            
            //printf("range[%d] = %d\n", i, range[i]);
        }
        
        start = clock();
        pos = binsearch(value, range, RANGE_LENGTH);
        diff = clock() - start;
        
        elapsed = diff * 1000 / CLOCKS_PER_SEC;
        
        
        if(pos != -1)
        {
            printf("Match at range[%d]\tTime elapsed = %d\n", pos, elapsed);
        }
        else
            printf("No match\tTime elapsed = %d\n", elapsed);
    }
    else
        printf("ERROR: A a value to search for is required\n");
    
    
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(x < v[mid])
            high = mid - 1;
        else if(x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

