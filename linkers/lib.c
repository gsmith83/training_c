int factorial(int base)
{
    int res = 1, i = 1;
    
    while(i <= base)
    {
        res *= i;
        i++;
    }
    
    return res;
}