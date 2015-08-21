#include <stdio.h>

/*
    This macro will swap elements x and y of type t
*/
#define swap(t, x, y) do { t temp = x; x = y; y = temp; } while(0)


/* swap v[i] and v[j] */
/*
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
*/

/*
    Only swaps integers, not elements of an integer array
*/
int main(int argc, char * argv[])
{    
    int i, j;
    
    if(argc == 3)
    {
        i = atoi(argv[1]);
        j = atoi(argv[2]);
        
        printf("Before:\t%d %d\n", i, j);
        swap(int, i, j);
        printf("After:\t%d %d\n", i, j);
    }
    
    return 0;
    
}
