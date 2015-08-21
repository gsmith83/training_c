/*
    Prototyping pointer usage
*/

#include <stdio.h>

void printIntPointer(int a, int * aPtr);
void changeValue(int * aPtr);
void changeValue2(int * aPtr);

int main(int argc, char ** argv)
{
    int x;
    int y = 8;                                      /* normally x and xPtr would be 4 bytes away in memory; now they are 8 due to y */
    int * xPtr;
    xPtr = &x;

    /* assign x to 5 through pointer */
    *xPtr = 5;
    printf("X = %i  :  xPtr = %p\n", x, xPtr);
    
    /* assign x to 10 directly */
    x = 10;
    printf("X = %i  :  xPtr = %p\n", x, xPtr);      /* xPtr has same memory address */
    printf("&X = %p  :  &xPtr = %p\n", &x, &xPtr);
    
    /* Test passing pointers to functions */
    printf("Testing passing pointers to functions\n");
    printIntPointer(x, xPtr);
                                                    /* Compiler errors and warnings */
    /*                        
    printIntPointer(&x, &xPtr); 
    printIntPointer(*x, *xPtr);
    */                          
    
    printIntPointer(x, &x); 
    
    printf("Y = %i\n", y);
    changeValue(&y);
    printf("Y = %i\n", y);
    changeValue2(&y);
    printf("Y = %i\n", y);
}

void printIntPointer(int a, int * aPtr)
{
    printf("X = %i  :  xPtr = %p\n", a, aPtr);
}

void changeValue(int * aPtr)
{
    *aPtr = 10;
}

void changeValue2(int * aPtr)
{
    *aPtr++;                    /* this doesn't change the value of Y */
}