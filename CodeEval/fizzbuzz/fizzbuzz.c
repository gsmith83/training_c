#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char ** argv){
    FILE * file;
    char line[10];
    int x, y, n, i;
    file = fopen(argv[1], "r");
    while(fgets(line, sizeof(line), file)){
        // assign vars
        x = atoi(strtok(line, " "));
        y = atoi(strtok(NULL, " "));
        n = atoi(strtok(NULL, " "));
        for(i = 1; i <= n; i++){
            if(i % x == 0 && i % y == 0)
                printf("FB");
            else if(i % x == 0)
                printf("F");
            else if(i % y == 0)
                printf("B");
            else
                printf("%d", i);
            if(i != n)
                printf(" ");
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}