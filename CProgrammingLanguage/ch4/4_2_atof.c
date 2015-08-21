#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

/*
    Converts string to double
*/
double atof(char s[])
{
    double val, power, retval;
    int i, sign, exp;

    for (i = 0; isspace(s[i]); i++) // skip white space
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '-' || s[i] == '+')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    // scientific notation
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        if (s[i] == '-')
        {
            i++;
            exp = s[i] - '0';
            for (; exp > 0; exp--)
            {
                power *= 10.0;
            }
        }
        else
        {
            exp = s[i] - '0';
            for (; exp > 0; exp--)
            {
                val *= 10.0;
            }
        }
    }

    retval = sign * val / power;

    return retval;
}

int get_line(char s[], int lim)
{
    int c, i;
    
    i = 0;
    
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    
    if(c == '\n')
        s[i++] = c;
    
    s[i] = '\0';
    return i;
}

// rudimentary summing calculator
int main(int argc, char ** argv)
{
    double sum; 
    char line[MAXLINE];

    printf("*** %s ***\n", argv[0]);

    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%f\n", sum += atof(line));

    return 0;
}


