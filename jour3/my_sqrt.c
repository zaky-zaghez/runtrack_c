int my_sqrt(int n)
{
    if (n < 0)
        return 0;
    
    if (n == 0 || n == 1)
        return n;
    
    int low = 1;
    int high = n;
    int result = 0;
    
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int square = mid * mid;
        
        if (square == n)
            return mid;
        
        if (square < n)
        {
            low = mid + 1;
            result = mid; // Garde le plus grand candidat possible
        }
        else
        {
            high = mid - 1;
        }
    }
    
    // Vérifie si le résultat est exact
    if (result * result == n)
        return result;
    else
        return 0;
}