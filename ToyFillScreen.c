#include <stdio.h>

#define CHARS 100000

int main(int argc, char ** argv)
{
    int i;
    
    for(i = 0; i < CHARS; i+=7)
    {   
        printf("%c", ((i % 122) + 33));
    }
}