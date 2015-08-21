#include <stdio.h>
#include "lib.h"

/*
    gcc -c main.c       Compile just main (-c == compile and assemble, but don't link)                      
    nm -A main.o        Inspect main.o with the nm utility
    objdump -S main.o   See disassembly output of the .o file (with -r for more detail (relocation entries))
    readelf -l factorial
*/

int main(int argc, char * argv[])
{
    int value, i;
    
    printf("FACTORIAL\n\n");
    
    if(argc > 1)
    {
        value = atoi(argv[1]);
        
        for(i = 1; i <= value; i++)
        {
            printf("Factorial of %d\t= %d\n", i, factorial(i));
        }
    }
    else
        printf("ERROR: Please include a value to compute\n");
    
    return 0;
}