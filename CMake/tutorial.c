// Calculates the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h" // configured header file, with values set in CMakeLists.txt. See TutorialConfig.h.in

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        printf("%s Version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);  // these values are available from the header file. See above include
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }
    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}
