#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; // next free position; same as   static char *allocp = &allocbuf[0];

char * alloc(int n)     // return pointer to n characters
{
    if (allocbuf + ALLOCSIZE - allocp >= n) // enough space
    {
        allocp += n;
        return allocp - n; // old pointer
    }
    else
        return 0;
}

void afree(char * p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    {
        allocp = p;
    }
}


// main testing
int main(int argc, char ** argv)
{
    int i;
    char *abc = alloc(3);
    
    for (i = 0; i < 3; i++)
    {
        abc[i] = 'a' + i;
    }

    for (i = 0; i < 3; i++)
    {
        printf("abc[%d] = %c\n", i, abc[i]);
    }

    afree(abc);
}
