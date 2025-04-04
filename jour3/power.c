int power(int base, int exponent)
{
    int result = 1;
    
    if (exponent < 0)  // Pour les exposants négatifs, retourne 0
        return 0;
    
    while (exponent > 0)
    {
        result *= base;
        exponent--;
    }
    
    return result;
}