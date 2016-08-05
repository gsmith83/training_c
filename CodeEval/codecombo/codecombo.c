#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b)) 

int main(int argc, char ** argv){
    FILE * file;
    char line[130];
    char * row[10];
    int codeCount[10][4];
    int rowNum;
    int pos;
    int pos2;
    int i, j;
    int combos;
    int max;
    
    if(argc != 2){
        printf("Exactly 1 argument required\n");
        exit(-1);
    }
    
    file = fopen(argv[1], "r");
    
    rowNum = 0;
    while(fgets(line, sizeof(line), file)){
        
        // get the strings into an array
        row[rowNum] = malloc(sizeof(char)*10 + 3);
        row[rowNum] = strtok(line, " |");
        while(row[rowNum] != NULL){
            rowNum++;
            row[rowNum] = malloc(sizeof(char)*10 + 3);
            row[rowNum] = strtok(NULL, " |");
        }
        
        // do the work
        combos = 0;
        pos = 0;
        pos2 = 0;
        for(i = 0; i < rowNum; i++){
            for(j = i + 1; j < rowNum; j++){
                
                
                while(row[i][pos] != '0'){
                    // logic
                    if(row[i][pos] == 'c' && row[j][pos] == 'o'){
                        while(row[i][++pos2] != '\0'){
                            pos++;
                            if((row[i][pos2] == 'd' && row[j][pos2] == 'e') || (row[i][pos2] == 'e' && row[j][pos2] == 'd'))
                                combos++;
                        }
                        pos2 = 0;
                    }
                    else if(row[i][pos] == 'c' && row[j][pos] == 'd'){
                        while(row[i][++pos2] != '\0'){
                            pos++;
                            if((row[i][pos2] == 'o' && row[j][pos2] == 'e') || (row[i][pos2] == 'e' && row[j][pos2] == 'o'))
                                combos++;
                        }
                        pos2 = 0;
                    }
                    else if(row[i][pos] == 'c' && row[j][pos] == 'e'){
                        while(row[i][++pos2] != '\0'){
                            pos++;
                            if((row[i][pos2] == 'd' && row[j][pos2] == 'o') || (row[i][pos2] == 'o' && row[j][pos2] == 'd'))
                                combos++;
                        }
                        pos2 = 0;
                    }
                    else if(row[i][pos] == 'o' && row[j][pos] == 'c'){
                        while(row[i][++pos2] != '\0'){
                            pos++;
                            if((row[i][pos2] == 'd' && row[j][pos2] == 'e') || (row[i][pos2] == 'e' && row[j][pos2] == 'd'))
                                combos++;
                        }
                        pos2 = 0;
                    }
                    else if(row[i][pos] == 'o' && row[j][pos] == 'd'){
                        while(row[i][++pos2] != '\0'){
                            pos++;
                            if((row[i][pos2] == 'c' && row[j][pos2] == 'e') || (row[i][pos2] == 'e' && row[j][pos2] == 'c'))
                                combos++;
                        }
                        pos2 = 0;
                    }
                    else if(row[i][pos] == 'o' && row[j][pos] == 'e'){
                        while(row[i][++pos2] != '\0'){
                            pos++;
                            if((row[i][pos2] == 'd' && row[j][pos2] == 'c') || (row[i][pos2] == 'c' && row[j][pos2] == 'd'))
                                combos++;
                        }
                        pos2 = 0;
                    }
                    else if(row[i][pos] == 'd' && row[j][pos] == 'c'){
                        while(row[i][++pos2] != '\0'){
                            pos++;
                            if((row[i][pos2] == 'o' && row[j][pos2] == 'e') || (row[i][pos2] == 'e' && row[j][pos2] == 'o'))
                                combos++;
                        }
                        pos2 = 0;
                    }
                    else if(row[i][pos] == 'd' && row[j][pos] == 'o'){
                        while(row[i][++pos2] != '\0'){
                            pos++;
                            if((row[i][pos2] == 'c' && row[j][pos2] == 'e') || (row[i][pos2] == 'e' && row[j][pos2] == 'c'))
                                combos++;
                        }
                        pos2 = 0;
                    }
                    else if(row[i][pos] == 'd' && row[j][pos] == 'e'){
                        while(row[i][++pos2] != '\0'){
                            pos++;
                            if((row[i][pos2] == 'c' && row[j][pos2] == 'o') || (row[i][pos2] == 'o' && row[j][pos2] == 'c'))
                                combos++;
                        }
                        pos2 = 0;
                    }
                    else if(row[i][pos] == 'e' && row[j][pos] == 'c'){
                        while(row[i][++pos2] != '\0'){
                            pos++;
                            if((row[i][pos2] == 'd' && row[j][pos2] == 'o') || (row[i][pos2] == 'o' && row[j][pos2] == 'd'))
                                combos++;
                        }
                        pos2 = 0;
                    }
                    else if(row[i][pos] == 'e' && row[j][pos] == 'd'){
                        while(row[i][++pos2] != '\0'){
                            pos++;
                            if((row[i][pos2] == 'c' && row[j][pos2] == 'o') || (row[i][pos2] == 'o' && row[j][pos2] == 'c'))
                                combos++;
                        }
                        pos2 = 0;
                    }
                    else if(row[i][pos] == 'e' && row[j][pos] == 'o'){
                        while(row[i][++pos2] != '\0'){
                            pos++;
                            if((row[i][pos2] == 'c' && row[j][pos2] == 'd') || (row[i][pos2] == 'd' && row[j][pos2] == 'c'))
                                combos++;
                        }
                        pos2 = 0;
                    }
                    pos++;
                }
                pos = 0;
            }
        }
        
        
        // testing
        /*
        for(i = 0; i < rowNum; i++){
            if(row[i] != NULL)
                printf("%s ", row[i]);
        }
        */
        printf("%d\n", combos);
        rowNum = 0;
        combos = 0;
    }
    fclose(file);
    return 0;
}