#include <stdio.h>

int main(int argc, char ** argv)
{
    char * pmessage = "Hello World\n";
    char amessage[] = "Hello World\n";

    printf(pmessage);
    printf(amessage);

    amessage[4] = ' ';
    //*(pmessage + 4) = ' ';   // undefined results when changing contents of a pointer

    printf(amessage);
}
