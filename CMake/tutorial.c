// Calculates the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h" // configured header file, with values set in CMakeLists.txt. See TutorialConfig.h.in
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        printf("%s Version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);  // these values are available from the header file.
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }
    double inputValue = atof(argv[1]);
#ifdef USE_MYMATH
    double outputValue = mysqrt(inputValue);
#else
    double outputValue = sqrt(inputValue);
#endif
    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}
