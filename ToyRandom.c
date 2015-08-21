#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_RANGE 0
#define END_RANGE 1000000
#define LOOPS 100000000

int main(int argc, char ** argv)
{
    int i, random;
    int range[END_RANGE - START_RANGE];
    memset(range, 0, sizeof(range));
    
    for(i = 0; i < LOOPS; i++)
    {
        random = (rand() % END_RANGE) + START_RANGE;
        
        range[random]++;
    }
    
    // print results
    for(i = 0; i < END_RANGE - START_RANGE; i++)
    {
        printf("RANGE[%d] \t== %d\n", i, range[i]);
    }
    
    printf("\nrange[0] = %d\n", range[0]);
    printf("\nrange[1] = %d\n", range[1]);
    printf("\nrange[2] = %d\n", range[2]);
    
    return 0;
}