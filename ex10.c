#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    
    // go through each string in argv
    for(i = 0; i < argc; i++)
    {
        printf("arg %d: %s\n", i, argv[i]);
    }
    
    // Let's make our own array of strings
    char *states[] = { "California", "Oregon", "Washington", "Texas", argv[0]};
    int num_states = 8; // will walk off end of states[]
    
    for(i = 0; i < num_states; i++)
    {
        printf("state %d: %s\n", i, states[i]);
    }
    
    argv[1] = states[0];
    
    printf("%s : %s\n", argv[0], argv[1]);
    
    return 0;
}