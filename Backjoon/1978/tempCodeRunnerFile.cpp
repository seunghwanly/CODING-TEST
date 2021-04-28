 if (n == 1 || n == 0)
        return false;
    if (n > 3)
    {
        for (int i = 2; i < n / 2; ++i)
        {
            if (n % i == 0)
                isPrime = false;
            break;
        }
    }