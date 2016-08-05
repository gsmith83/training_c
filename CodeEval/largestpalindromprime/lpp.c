#include <stdio.h>
#include <math.h>

int is_prime(int value){
    if(value % 2 == 0)
        return 0;
    
    int sqrtValue = (int)sqrt((double)value) + 1;
    int i;
    for(i = 3; i < sqrtValue; i+=2){
        if(value % i == 0)
            return 0;
    }
    return 1;
}

int main(int argc, char ** argv){
    int prime = 999;
    
    int j;
    for(j = 0; j < 9; j++){
        if(is_prime(prime)){
            printf("%d\n", prime);
            return 0;
        }
        prime -= 10;;
    }
    
    return 0;
}