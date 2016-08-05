/*
    itoa    Converts an integer to asci characters
    itob    Converts an integer to a base b character representation
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// forward declarations
void itoa(int n, char s[]);
void itob(int n, char s[], int base);
void reverse(char s[]);

int main(int argc, char ** argv)
{
    int i;
    char s[10];
    
    printf("%s\n\n", argv[0]);
    
    memset(s, 0, sizeof(s));
    
    for(i = -255; i <= 255; i++)
    {
        itob(i, s, 2);
        printf("%d in binary \t\t== %s\n", i, s);
        itob(i, s, 8);
        printf("%d in octal \t\t== %s\n", i, s);
        itob(i, s, 16);
        printf("%d in hexadecimal \t== %s\n", i, s);
        itob(i, s, 36);
        printf("%d in base 36 \t\t== %s\n\n", i, s);
    }
    
    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;
    
    if((sign = n) < 0)
        n = -n; // make n positive
    
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);
    
    if(sign < 0)
        s[i++] = '-';
    
    s[i] = '\0'; //terminate string
    reverse(s);
}

// handles up to base 36
void itob(int n, char s[], int base)
{
    static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, sign;
    
    if( base < 2 || base > 36)
    {
        printf("ERROR: Cannot support base %d\n", base);
        exit(EXIT_FAILURE);
    }
    
    if((sign = n) < 0)
    {
        n = -n;
    }
    
    i = 0;
    
    do{
        s[i++] = digits[n % base];
    }while((n /= base) > 0);
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;
    
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}