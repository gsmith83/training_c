#include <stdio.h>
#include <math.h>

int odd_is_prime(int num){
    int i;
    double squareroot = sqrt(num);
    for(i = 3; i <= squareroot; i += 2){
        if(num % i == 0)
            return 0;
    }
    return 1;
}

int find_next_prime(int prime){
    int result = prime + 2;
    
    while(!odd_is_prime(result)){
        result += 2;
    }
    
    return result;
}

int main(int argc, char ** argv){
    int sum = 2;
    int prime = find_next_prime(1);
    
    int i;
    for(i = 0; i <= 998; i++){
        sum += prime;
        prime = find_next_prime(prime);
    }
    
    printf("%d", sum);
    return 0;
}